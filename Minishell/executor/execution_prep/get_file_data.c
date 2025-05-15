/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:06:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/15 16:11:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

static void	find_last_file(t_exec *exec, t_token *token);
static int	add_one(t_exec *exec, t_token *token, t_token **token_address);
static int	get_here_doc_file(char *limiter, t_exec *exec);

/*REVIEW - get_file_data

	This function is called both in execution main and in manage_parenthesis.
	do_pipe is a bool that enables or disables the pipe creation.
	If called from execution main, do_pipe is set to 1.
	If called from manage_parenthesis, do_pipe is set to 0.

//	1)	We find the last file in the command block.
		Example: (cat < file1.txt <file2.txt >file3.txt >file4.txt)
		STDIN: 	file2.txt;
		STDOUT: file4.txt.
		See find_last_file below for more information.
	2)	We iterate for all token contents;
	3)	If we find a execution separator (|, &&, ||) in the same
		parenthesis layer as the execution layer, we stop;
	4)	If the token is a redictor sign (>, >>, <, <<, <()), we
		manage that file (see add_one below);
	5)	If something goes wrong (non existing files, perms.), we return error.
		This error will abort the command block, preventing execution;
	6)	If find_last_file does not find any OUTPUT redirections, and if
		there are NO pipes, dup the regular STDOUT;
	7)	If find_last_file does not find any OUTPUT redirections, and if
		there are pipes, dup the STDOUT side of the pipe.
		If there are both pipes and redirections, make an empty pipe,
		to avoid let cat stay appended;
	8)	If there are redirections on STDIN or STDOUT, add_one will manage
		them.
	9)	We update the current command number: in add_one weird things
		happen when redir_subshells are present.
*/
int	get_file_data(t_exec *exec, t_token *token, bool do_pipe)
{
	int	file_not_found;
	int	current_cmd;

	file_not_found = 0;
	current_cmd = token->cmd_num;
	find_last_file(exec, token);
	while (token->prior == exec->prior_layer && !is_exec_sep(token->type))
	{
		if (!file_not_found && is_red_sign(token->type))
			file_not_found = add_one(exec, token, &token);
		if (token->type != RED_SUBSHELL && !is_exec_sep(token->type))
			token += (token->content != NULL);
	}
	if (do_pipe && token->type == PIPE && exec->prior_layer == token->prior)
	{
		pipe(exec->pipe_fds);
		if (exec->last_out == -1 && !file_not_found)
			dup_and_reset(&exec->pipe_fds[1], 1);
		else
			close_and_reset(&exec->pipe_fds[1]);
	}
	if (do_pipe)
		exec->curr_cmd = current_cmd;
	return (file_not_found);
}

/*REVIEW - find_last_file

//	Finds last STDIN redirector and STDOUT redirector in command block.
	Command blocks are divided by execution separator (|, &&, ||).
	
*/
static void	find_last_file(t_exec *exec, t_token *token)
{
	int	layer;

	layer = token->prior;
	exec->last_in = -1;
	exec->last_out = -1;
	while (token->content && is_exec_sep(token->type) == _NO)
	{
		if (token->type == RED_IN || token->type == HERE_DOC)
			exec->last_in = token->id;
		else if (token->type == RED_OUT || token->type == RED_O_APPEND)
			exec->last_out = token->id;
		if (token->type == RED_SUBSHELL)
		{
			while (token->type == RED_SUBSHELL)
				skip_deeper_layers(&token, layer);
		}
		else if (token->content)
			++token;
	}
}

//	grep -v .c <(ls | grep -v .h)
//
/*REVIEW - add_one

//	1)	If REDIRECT_INPUT (RED_IN): open file with INFILE permissions;
		If HERE_DOC:				take fd in here_docs array;
		If OUTFILE_TRUNC:			open file with O_T permissions;
		If OUTFILE_APPEND:			open file with O_A permissions;
		If RED_SUBSHELL (<(ls)):	call get_subshell_filename.
	
	2)	If fd is invalid, and the token is an outfile: stop the whole program;
	3)	If fd is invalid, and the token is an infile: stop the cmd block;
	4)	If the token is the last STDIN/STDOUT redirector:
		dup the fd on STDOUT if is a redirect output sign, else in STDIN;
	5)	Close the fd.
		If the fd is a here_doc, we do not close it, unless is the last
		STDIN redirector.
*/
static int	add_one(t_exec *exec, t_token *token, t_token **token_address)
{
	int	fd;

	if (token->type == RED_IN)
		fd = open(token->content, INFILE);
	else if (token->type == HERE_DOC)
		fd = exec->here_doc_fds[exec->curr_cmd];
	else if (token->type == RED_OUT)
		fd = open(token->content, OUTFILE_TRUNC, 0666);
	else if (token->type == RED_O_APPEND)
		fd = open(token->content, OUTFILE_APPEND, 0666);
	else
		return (get_subshell_filename(exec, token_address, token->cmd_num));
	if (fd == -1 && access(token->content, F_OK) == 0)
		return (bash_message(E_PERMISSION_DENIED, token->content), 1);
	else if (fd == -1)
		return (bash_message(E_OPEN, token->content), 1);
	if ((token->id == exec->last_in && is_red_input_sign(token->type)) || \
		(token->id == exec->last_out && is_red_output_sign(token->type)))
	{
		dup2(fd, is_red_output_sign(token->type));
	}
	if (token->type != HERE_DOC)
		close(fd);
	return (0);
}

/*REVIEW - get_here_doc_file

//FIXME - Signals management is not implemented yet!

//	1)	We open a file named "here_doc";
	2)	We write "> ": a bash syntax string that means "Write here, user".
		The write process goes line per line. If user gives a special
		character, called LIMITER, the write process stops.
		Limiter is not written in here doc file.
	3)	We close and open here_doc file to move the cursor to the start
		of the line;
	4)	We return the new fd, if there are no errors.
		It will be saved in a here_doc_fds array, and closed at the end
		of its own command block.
*/
static int	get_here_doc_file(char *limiter, t_exec *exec)
{
	int		fd;
	char	*line;
	int		limiter_len;

	fd = open(".here_doc", INFILE_DOC, 0666);
	if (fd < 0)
		error(E_OPEN, exec);
	ft_putstr_fd("> ", 2);
	line = get_next_line_bonus(0);
	limiter_len = ft_strlen(limiter);
	while ((line) && (double_cmp(limiter, line, limiter_len, 1)) != 0)
	{
		write_here_doc(line, exec, fd);
		ft_putstr_fd("> ", exec->stdout_fd);
		free(line);
		line = get_next_line_bonus(0);
	}
	close(fd);
	fd = open(".here_doc", INFILE_DOC, 0666);
	if (fd < 0)
		return (free(line), unlink(".here_doc"), error(E_OPEN, exec));
	if (!line)
		return (close(fd), unlink(".here_doc"), error(E_MALLOC, exec));
	return (free(line), unlink(".here_doc"), fd);
}

/*REVIEW - prepare_here_docs

//FIXME - Signals management is not implemented yet!

//		For every command block, we open all here_docs.
		However, we need to keep the fd only if the here_doc is 
		the last STDIN redirector.
		1)	We iterate through every token of the command block;
		2)	We gain the fd of the here doc. If a here doc already exists
			in the current command block, we close it.
*/
void	prepare_here_docs(t_exec *exec, t_token *token)
{
	int	i;

	while (token->content)
	{
		i = token->cmd_num;
		if (token->type == HERE_DOC)
		{
			if (exec->here_doc_fds[i])
				close_and_reset(&exec->here_doc_fds[i]);
			exec->here_doc_fds[i] = get_here_doc_file(token->content, exec);
		}
		++token;
	}
}

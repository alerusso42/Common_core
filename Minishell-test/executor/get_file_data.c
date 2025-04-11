/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:06:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/11 09:29:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	find_last_file(t_exec *exec, t_token *token);
static int	add_one(t_exec *exec, t_token *token);
static int	get_here_doc_file(char *limiter, t_exec *exec);

int	get_file_data(t_exec *exec, t_token *token)
{
	find_last_file(exec, token);
	while (token->content)
	{
		if (is_exec_sep(token->type))
			break ;
		else if (is_red_sign(token->type))
			if (add_one(exec, token) != 0)
				return (1);
		++token;
	}
	if (exec->last_out == -1 && token->type != PIPE)
		dup2(exec->stdout_fd, 1);
	if (exec->last_out == -1 && token->type == PIPE)
	{
		pipe(exec->pipe_fds);
		dup2(exec->pipe_fds[1], 1);
		close(exec->pipe_fds[1]);
		exec->pipe_fds[1] = 0;
	}
	return (0);
}

static void	find_last_file(t_exec *exec, t_token *token)
{
	exec->last_in = -1;
	exec->last_out = -1;
	while (token->content && is_exec_sep(token->type) == _NO)
	{
		if (token->type == RED_IN || token->type == HERE_DOC)
			exec->last_in = token->id;
		else if (token->type == RED_OUT || token->type == RED_O_APPEND)
			exec->last_out = token->id;
		++token;
	}
}

//	RED_IN avrà un ruolo importante nelle parentesi...
//	grep -v .c <(ls | grep -v .h)
static int	add_one(t_exec *exec, t_token *token)
{
	int	fd;

	if (token->type == RED_IN)
		fd = open(token->content, INFILE);
	else if (token->type == HERE_DOC)
		fd = exec->here_doc_fds[exec->cmd_num];
	else if (token->type == RED_OUT)
		fd = open(token->content, OUTFILE_TRUNC, 0666);
	else
		fd = open(token->content, OUTFILE_APPEND, 0666);
	if (fd == -1)
		return (bash_message(E_OPEN, token->content));
	if ((token->id == exec->last_in && is_red_input_sign(token->type)) || \
		(token->id == exec->last_out && is_red_output_sign(token->type)))
	{
		dup2(fd, is_red_output_sign(token->type));
	}
	if (token->type == HERE_DOC)
		return (0);
	return (close(fd), 0);
}

static int	get_here_doc_file(char *limiter, t_exec *exec)
{
	int		fd;
	char	*line;
	int		limiter_len;

	fd = open("here_doc", INFILE_DOC, 0666);
	if (fd < 0)
		error(E_OPEN, exec);
	ft_putstr_fd("> ", 2);
	line = get_next_line_bonus(0);
	limiter_len = ft_strlen(limiter);
	while ((line) && (double_cmp(limiter, line, limiter_len, 1)) != 0)
	{
		ft_putstr_fd("> ", 2);
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line_bonus(0);
	}
	close(fd);
	open("here_doc", INFILE_DOC, 0666);
	if (fd < 0)
		return (free(line), unlink("here_doc"), error(E_OPEN, exec));
	if (!line)
		return (close(fd), unlink("here_doc"), error(E_MALLOC, exec));
	return (free(line), unlink("here_doc"), fd);
}

void	prepare_here_docs(t_exec *exec, t_token *token)
{
	int	i;

	i = 0;
	while (token->content)
	{
		find_last_file(exec, token);
		while (token->content && !is_exec_sep(token->type))
		{
			if (token->type == HERE_DOC)
				exec->here_doc_fds[i] = get_here_doc_file(token->content, exec);
			if (token->id != exec->last_in && exec->here_doc_fds[i])
				close_and_reset(&exec->here_doc_fds[i]);
			++token;
		}
		if (token->content)
			++token;
		++i;
	}
}

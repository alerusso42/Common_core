/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:52:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/23 12:01:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	redir_output(t_exec *exec, t_token *token, int fds[2], int getfd);
static void	print_file(int infile, int outfile);

int	manage_parenthesis(t_exec *exec, t_token **token, int getfd)
{//FIXME - Ripristinare fork
	pid_t	pid;//
	int		fds[2];
	int		temp_fd;
	
	temp_fd = exec->stdout_fd;
	fds[0] = 0;
	fds[1] = 0;
	pipe(fds);
	exec->stdout_fd = fds[1];
	dup2(fds[1], 1);
	pid = fork();//
	if (pid < 0)//
		return (close(fds[0]), close(fds[1]), error(E_FORK, exec));//
	else if (pid == 0)//
		execute_loop(*token, exec);
	exec->stdout_fd = temp_fd;
	dup2(temp_fd, 1);
	while ((*token)->content && (*token)->prior == (*token + 1)->prior)
		++(*token);
	if ((*token)->content)
		++(*token);
	redir_output(exec, *token, fds, getfd);
	close(fds[1]);
	return (fds[0]);
}

static void	redir_output(t_exec *exec, t_token *token, int fds[2], int getfd)
{
	int	layer;

	if (getfd)
		return ;
	layer = exec->prior_layer;
	while (layer < token->prior && !is_exec_sep(token->type))
		++token;
	if (layer > token->prior || token->type == AND || token->type == OR)
	{
		print_file(fds[1], exec->stdout_fd);
		close_and_reset(&fds[0]);
	}
	else
	{
		if (exec->stdin_fd)
			close_and_reset(&exec->stdin_fd);
		exec->stdin_fd = fds[0];
	}
}

static void	print_file(int infile, int outfile)
{
	char	*line;

	line = get_next_line_bonus(infile);
	while (line)
	{
		ft_putstr_fd(line, outfile);
		free(line);
		line = get_next_line_bonus(infile);
	}
}

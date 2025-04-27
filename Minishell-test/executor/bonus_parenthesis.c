/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:52:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/27 12:51:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	redir_output(t_exec *exec, t_token *token, int fds[2], int getfd);
static void	print_file(int infile, int outfile);

int	manage_parenthesis(t_exec *exec, t_token **token, int getfd)
{//FIXME - Ripristinare fork
	//pid_t	pid;//
	int		fds[2];
	int		temp_fd;

	if (getfd)
		++(*token);
	temp_fd = exec->stdout_fd;
	fds[0] = 0;
	fds[1] = 0;
	int	layer = exec->prior_layer;
	pipe(fds);
	exec->stdout_fd = fds[1];
	dup2(fds[1], 1);
	//pid = fork();//
	//if (pid < 0)//
	//	return (close(fds[0]), close(fds[1]), error(E_FORK, exec));//
	//else if (pid == 0)//
		execute_loop(*token, exec);
	exec->prior_layer = layer;
	exec->stdout_fd = temp_fd;
	close(1);
	dup2(temp_fd, 1);
	//while ((*token)->content && (*token)->prior > exec->prior_layer)
	//	++(*token);
	skip_deeper_layers(token, exec->prior_layer);
	write(fds[1], "\0", 1);
	close(fds[1]);
	redir_output(exec, *token, fds, getfd);
	if ((*token)->content)
		++(*token);
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
		print_file(fds[0], exec->stdout_fd);
		close_and_reset(&fds[0]);
	}
	else
	{
		close_and_reset(&exec->pipe_fds[0]);
		exec->pipe_fds[0] = fds[0];
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

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

static void	redir_output(t_exec *exec, bool redir_to_pipe, int input_fd);
static bool	detect_pipe(t_token *token, int getfd);

int	manage_parenthesis(t_exec *exec, t_token **token, int getfd)
{//FIXME - Ripristinare fork
	//pid_t	pid;//
	int		fds[2];
	int		temp_fd;
	int		redir_to_pipe;

	if (getfd)
		++(*token);
	temp_fd = exec->stdout_fd;
	fds[0] = 0;
	fds[1] = 0;
	redir_to_pipe = detect_pipe(*token, getfd);
	int	layer = exec->prior_layer;
	if (getfd || redir_to_pipe)
	{
		pipe(fds);
		exec->stdout_fd = fds[1];
		dup2(fds[1], 1);
	}
	//pid = fork();//
	//if (pid < 0)//
	//	return (close(fds[0]), close(fds[1]), error(E_FORK, exec));//
	//else if (pid == 0)//
		execute_loop(*token, exec);
	exec->prior_layer = layer;
	exec->stdout_fd = temp_fd;
	close(1);
	dup2(temp_fd, 1);
	skip_deeper_layers(token, exec->prior_layer);
	close(fds[1]);
	redir_output(exec, redir_to_pipe, fds[0]);
	if ((*token)->content)
		++(*token);
	return (fds[0]);
}

static void	redir_output(t_exec *exec, bool redir_to_pipe, int input_fd)
{
	if (redir_to_pipe == 0)
		return ;
	close_and_reset(&exec->pipe_fds[0]);
	exec->pipe_fds[0] = input_fd;
}

static bool	detect_pipe(t_token *token, int getfd)
{
	if (getfd)
		return (0);
	skip_deeper_layers(&token, token->prior - 1);
	if (token->type == PIPE)
		return (1);
	return (0);
}

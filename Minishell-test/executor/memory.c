/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:37:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/03 19:07:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	free_memory2(t_exec *exec);

//REVIEW -
/*
	To update storage:	storage(data, STORE)
	TO receive storage:	storage(data, RECEIVE)
*/
t_exec	*storage(t_exec *update, int mode)
{
	static t_exec	*stack;

	if (mode == STORE)
		stack = update;
	return (stack);
}

void	*free_debug_data(t_debug_data *data)
{
	data->matrix = _free_three_d_matrix(data->matrix);
	free(data->temp);
	data->temp = NULL;
	free(data->filename1);
	free(data->filename2);
	data->filename1 = NULL;
	data->filename2 = NULL;
	close(data->fd_to_close);
	data->fd_to_close = 0;
	free(data->tokens);
	data->tokens = NULL;
	return (NULL);
}

//REVIEW - Alloc for t_exec
int	alloc_memory(t_exec *exec, int cmd_num)
{
	storage(exec, STORE);
	exec->stdin_fd = dup(0);
	exec->stdout_fd = dup(1);
	exec->cmd_num = cmd_num;
	exec->commands = (char ***)ft_calloc(cmd_num + 2, sizeof(char **));
	if (!exec->commands)
		error(E_MALLOC);
	exec->pid_list = (int *)ft_calloc(cmd_num + 1, sizeof(int));
	if (!exec->pid_list)
		error(E_MALLOC);
	exec->builtins = (t_builtin *)ft_calloc(BUILT_N, sizeof(t_builtin));
	if (!exec->builtins)
		error(E_MALLOC);
	exec->which_cmd = (char *)ft_calloc(cmd_num + 1, sizeof(char));
	if (!exec->which_cmd)
		error(E_MALLOC);
	exec->here_doc_fds = (int *)ft_calloc(cmd_num + 1, sizeof(int));
	if (!exec->here_doc_fds)
		error(E_MALLOC);
	return (0);
}

//REVIEW - Release memory of t_exec
void	free_memory(void)
{
	t_exec	*exec;

	exec = storage(NULL, RECEIVE);
	if (!exec)
		return ;
	dup2(exec->stdin_fd, 0);
	dup2(exec->stdout_fd, 1);
	close(exec->stdin_fd);
	close(exec->stdout_fd);
	exec->commands = _free_three_d_matrix(exec->commands);
	exec->path = _free_matrix(exec->path);
	free(exec->pid_list);
	exec->pid_list = NULL;
	free(exec->builtins);
	exec->builtins = NULL;
	free(exec->which_cmd);
	exec->which_cmd = NULL;
	free_memory2(exec);
	storage(NULL, STORE);
}

static void	free_memory2(t_exec *exec)
{
	int	i;

	if (access("here_doc", F_OK) == 0)
		unlink("here_doc");
	i = -1;
	while (++i != exec->cmd_num)
	{
		close_and_reset(&exec->here_doc_fds[i]);
	}
	free(exec->here_doc_fds);
	exec->here_doc_fds = NULL;
	if (exec->pipe_fds[0])
		close(exec->pipe_fds[0]);
	if (exec->pipe_fds[1])
		close(exec->pipe_fds[1]);
}

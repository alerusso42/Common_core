/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/28 17:15:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	goto_next_command_block(t_exec *exec, t_token **tokens);
static int	invoke_programs(t_exec *exec, int i, void *data, int debug);
static int	wait_everyone(t_exec *exec);

int	execute(t_token *tokens, void *data, int debug)
{
	t_exec		*exec;

	if (!tokens)
		error(E_ARGS);
	if (alloc_memory(&exec, count_commands(tokens)) != 0)
		return (error(E_MALLOC));
	if (get_commands_data(exec, tokens) != 0)
		return (error(E_MALLOC));
	if (get_paths_data(exec, tokens) != 0)
		return (E_MALLOC);
	exec->cmd_num = 0;
	while (tokens->content)
	{
		get_file_data(exec, tokens);
		invoke_programs(exec, exec->cmd_num, data, debug);
		if (goto_next_command_block(exec, &tokens) != 0)
			break ;
		exec->cmd_num++;
	}
	wait_everyone(exec);
	free_memory();
	return (0);
}

static int	goto_next_command_block(t_exec *exec, t_token **tokens)
{
	while ((*tokens)->content && is_exec_sep((*tokens)->type) == _NO)
	{
		++(*tokens);
	}
	if ((*tokens)->type == AND || (*tokens)->type == OR)
	{
		if (((*tokens)->type == AND && exec->exit_status != 0) || \
		((*tokens)->type == OR && exec->exit_status == 0))
			return (1);
		wait_everyone(exec);
	}
	if (exec->pipe_fds[0])
	{
		dup2(exec->pipe_fds[0], 0);
		close(exec->pipe_fds[0]);
		dup2(exec->stdout_fd, 1);
		exec->pipe_fds[0] = 0;
	}
	if ((*tokens)->content)
		++(*tokens);
	return (0);
}

static int	invoke_programs(t_exec *exec, int i, void *data, int debug)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (E_FORK);
	else if (pid == 0)
	{
		execve(exec->commands[i][0], exec->commands[i], exec->env);
		if (debug == _YES)
			data = free_debug_data((t_debug_data *)data);
		else
			(void)data;//	Qui france mettiamo la tua funzione che freea tutto
		return (storage(exec, STORE), free_memory(), exit(1), 1);
	}
	else
	{
		storage(exec, STORE);
		exec->pid_list[i] = pid;
	}
	return (0);
}

static int	wait_everyone(t_exec *exec)
{
	int	i;

	i = exec->last_cmd_done;
	while (exec->pid_list[i])
	{
		waitpid(exec->pid_list[i], &exec->exit_status, 0);
		++i;
	}
	exec->last_cmd_done = i;
	return (0);
}

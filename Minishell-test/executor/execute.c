/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/07 17:09:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	execute_loop(t_token *token, t_exec *exec);
static int	goto_next_command_block(t_exec *exec, t_token **tokens);
static int	invoke_programs(t_exec *exec, int i);
static int	wait_everyone(t_exec *exec);

int	execute(t_token *tokens, void *data, int debug)
{
	t_exec	exec;

	exec = (t_exec){0};
	get_main_struct_data(&exec, data, debug);
	if (!tokens)
		error(E_ARGS);
	alloc_memory(&exec, count_commands(&exec, tokens));
	prepare_here_docs(&exec, tokens);
	get_commands_data(&exec, tokens);
	get_paths_data(&exec, tokens);
	execute_loop(tokens, &exec);
	free_memory();
	return (0);
}

static int	execute_loop(t_token *token, t_exec *exec)
{
	exec->cmd_num = 0;
	while (token->content)
	{
		*exec->exit_status = 0;
		if (get_file_data(exec, token) == 0)
			invoke_programs(exec, exec->cmd_num);
		close_and_reset(&exec->here_doc_fds[exec->cmd_num]);
		if (goto_next_command_block(exec, &token) != 0)
			break ;
		exec->cmd_num++;
	}
	wait_everyone(exec);
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
		if (((*tokens)->type == AND && *exec->exit_status != 0) || \
		((*tokens)->type == OR && *exec->exit_status == 0))
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

static int	invoke_programs(t_exec *exec, int i)
{
	pid_t	pid;

	if (is_a_valid_executable(exec, i) == _NO)
		return (0);
	if (exec->which_cmd[i] != 0)
		return ((exec->builtins[(int)exec->which_cmd[i]]) \
		(exec->commands[i], exec));
	pid = fork();
	if (pid < 0)
		error(E_FORK);
	else if (pid == 0)
	{
		execve(exec->commands[i][0], exec->commands[i], *exec->env);
		return (ft_exit(NULL, exec), 1);
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
		waitpid(exec->pid_list[i], &*exec->exit_status, 0);
		++i;
	}
	exec->last_cmd_done = i;
	return (0);
}

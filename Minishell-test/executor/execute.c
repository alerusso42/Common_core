/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/11 16:46:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	execute_loop(t_token *token, t_exec *exec);
static int	goto_next_command_block(t_exec *exec, t_token **tokens);
static int	invoke_programs(t_exec *exec, int i);
static int	wait_everyone(t_exec *exec);

//NOTE  Manda il puntatore al primo token, t_data (castato void *), 0.
//		execute(token, (void *)t_data, 0);
//		execute torna sempre 0.
//		QUANDO CHIAMI EXECUTE OGNI FILE APERTO/MEMORIA ALLOCATA DEVE ESSERE
//		LIBERATA, OPPURE INSERITA NELLA STRUTTURA t_data, IN UN PUNTATORE
//		CHE PUNTA ALLA TUA STRUTTURA DATI.
//		Devi avere poi una funzione che libera tutta la tua memoria, cosi
//		che possa chiamarla quando viene lanciato exit.
//
/*REVIEW - execute

//	1)	We declare the exec struct in stack, and assign it to {0}.
	2)	We get various data from main struct:
		-	The address of the environment (char **);
		-	The address of the environment size (int);
		-	The address of the environment last element (int);
		-	The address of the exit code.
	3)	We open all the here docs, and store their fds in a int array;
	4)	Get a 3D matrix, that stores the argv of each command.
		Example: echo Hello! | cat > file1.txt
		matrix = {{"echo", "Hello!", NULL}, {"cat", "file1.txt", NULL}}
	5)	We get the path of every command. Builtin are not converted.
		matrix = {{"echo", "Hello!", NULL}, {"/bin/cat", "file1.txt", NULL}}
	6)	Now, we iterate every command in execute_loop;
	7)	We free only the memory of execution.
*/
int	execute(t_token *tokens, void *data, int debug)
{
	t_exec	exec;

	exec = (t_exec){0};
	get_main_struct_data(&exec, data, debug);
	if (!tokens)
		error(E_ARGS, &exec);
	alloc_memory(&exec, count_commands(&exec, tokens));
	prepare_here_docs(&exec, tokens);
	get_commands_data(&exec, tokens);
	get_paths_data(&exec, tokens);
	execute_loop(tokens, &exec);
	free_memory(&exec);
	return (0);
}

/*REVIEW - execute

//	1)	We iterate while there are token with a valid content;
	2)	We set the exit status at 0;
	3)	We alter STDIN and STDOUT, if we do not fail to get filedatas;
	4)		We invoke the program in a child;
	5)	If there is a here_doc opened, we close it;
	6)	We go to the next command block;
	7)	We wait every children.
*/
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

/*REVIEW - execute

//	1)	We iterate while there are token with a valid content;
	2)	We set the exit status at 0;
	3)	We alter STDIN and STDOUT, if we do not fail to get filedatas;
	4)		We invoke the program in a child;
	5)	If there is a here_doc opened, we close it;
	6)	We go to the next command block;
	7)	We wait every children.
*/
static int	goto_next_command_block(t_exec *exec, t_token **tokens)
{
	while ((*tokens)->content && is_exec_sep((*tokens)->type) == _NO)
	{
		++(*tokens);
	}
	if ((*tokens)->type == AND || (*tokens)->type == OR)
	{
		while (((*tokens)->content) && \
		(((*tokens)->type == AND && *exec->exit_status != 0) || \
		((*tokens)->type == OR && *exec->exit_status == 0)))
		{
			if (is_exec_sep((*tokens)->type))
				exec->cmd_num++;
			++(*tokens);
		}
		if (!(*tokens)->content)
			return (1);
		wait_everyone(exec);
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
		error(E_FORK, exec);
	else if (pid == 0)
	{
		execve(exec->commands[i][0], exec->commands[i], *exec->env);
		return (ft_exit(NULL, exec), 1);
	}
	exec->pid_list[i] = pid;
	if (exec->pipe_fds[0])
	{
		dup2(exec->pipe_fds[0], 0);
		close(exec->pipe_fds[0]);
		dup2(exec->stdout_fd, 1);
		exec->pipe_fds[0] = 0;
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

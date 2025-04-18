/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:47:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 10:54:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
//REVIEW - error
//
//	error prints the errore type, then free all the memory, including parsing
	part memory, and exit the whole program.
	It is called for serious problem, like malloc errors.
*/
int		error(int err, t_exec *memory)
{
	*memory->exit_status = 1;
	if (err == NONE)
	{
		ft_putstr_fd("Please insert an error.\n", 2);
	}
	else if (err == E_ARGS)
	{
		ft_putstr_fd("France non mi hai passato nulla lol\n", 2);
	}
	else if (err == E_MALLOC || err == E_FORK)
	{
		ft_putstr_fd("bash: fork: Cannot allocate memory\n", 2);
	}
	else if (err == E_OPEN)
	{
		ft_putstr_fd("Open critical error\n", 2);
	}
	return (ft_exit(NULL, memory));
}

/*
//REVIEW - bash_message

//	bash_message prints the error type, showing, in some cases,
	what file cause the error.
	It just prints the error, though: it does not kill the process.
*/
int	bash_message(int message, char *file)
{
	if (message == E_OPEN)
	{
		_fd_printf(2, "bash: %s: No such file or directory\n", file);
	}
	else if (message == E_ENV_PARSING)
	{
		_fd_printf(2, "bash: export: `%s': not a valid identifier\n", file);
	}
	else if (message == E_CD_ARGS)
	{
		_fd_printf(2, "bash: cd: too many arguments\n");
	}
	else if (message == E_CD_NOHOME)
	{
		_fd_printf(2, "bash: cd: HOME not set\n");
	}
	else if (message == E_CMD_NOTFOUND)
	{
		_fd_printf(2, "%s: command not found\n");
	}
	else if (message == E_IS_DIRECTORY)
	{
		_fd_printf(2, "bash: %s: Is a directory\n");
	}
	return (1);
}

/*
//REVIEW - is_a_valid_executable

	This function is launched before command execution.
	It checks the executability of the program, and prints a bash_message if:

	1)	The executable is a directory 	(Exit status 126);
	2)	There executable does not exist (Exit status 127).
*/
int	is_a_valid_executable(t_exec *exec, int i)
{
	DIR	*dir;

	if (exec->which_cmd[i] != 0)
		return (_YES);
	dir = opendir(exec->commands[i][0]);
	if (dir)
	{
		bash_message(E_IS_DIRECTORY, exec->commands[i][0]);
		closedir(dir);
		set_exit_status(exec, 126);
		return (_NO);
	}
	else if (access(exec->commands[i][0], F_OK | X_OK) != 0)
	{
		bash_message(E_CMD_NOTFOUND, exec->commands[i][0]);
		set_exit_status(exec, 127);
		return (_NO);
	}
	return (_YES);
}

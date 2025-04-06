/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:47:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/06 10:56:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	error(int err)
{
	t_exec	*exec;

	exec = storage(NULL, RECEIVE);
	exec->exit_status = 1;
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
	return (ft_exit(NULL, exec));
}

int	bash_message(int message, char *file)
{
	if (message == E_OPEN)
	{
		_fd_printf(2, "bash: %s: No such file or directory\n", file);
	}
	else if (message == E_MALLOC)
	{
		_fd_printf(2, "bash: fork: Cannot allocate memory\n");
	}
	else if (message == E_ENV_PARSING)
	{
		_fd_printf(2, "bash: export: `%s': not a valid identifier", file);
	}
	else if (message == E_CD_ARGS)
	{
		_fd_printf(2, "bash: cd: too many arguments");
	}
	return (1);
}

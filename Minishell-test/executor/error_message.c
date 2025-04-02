/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:47:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/02 15:02:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	error(int err)
{
	t_exec	*exec;

	exec = storage(NULL, RECEIVE);
	if (err == NONE)
	{
		return (ft_putstr_fd("Please insert an error.\n", 2), err);
	}
	else if (err == E_ARGS)
	{
		return (ft_putstr_fd("France non mi hai passato nulla lol\n", 2), err);
	}
	else if (err == E_MALLOC)
	{
		return (ft_putstr_fd("bash: fork: Cannot allocate memory\n", 2), err);
	}
	return (ft_putstr_fd("UNKNOWN error\n", 2),  ft_exit(NULL, exec));
}

int	bash_message(int message, char *file)
{
	if (message == E_OPEN)
	{
		_fd_printf(2, "bash: %s: No such file or directory\n", file);
		return (1);
	}
	else if (message == E_MALLOC)
	{
		_fd_printf(2, "bash: fork: Cannot allocate memory\n");
	}
	else if (message == E_ENV_PARSING)
	{
		_fd_printf(2, "bash: export: `%s': not a valid identifier", file);
	}
	return (_fd_printf(2, "UNKNOWN message\n"));
}

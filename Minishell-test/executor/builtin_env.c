/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:46:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/06 11:54:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	print_env(char **env);

/*
//REVIEW - print_env

//		If there are no arguments, calls print_env.
*/
int	ft_env(char **args, t_exec *exec)
{
	if (args[1])
		return (set_exit_status(exec, 1));
	exec->exit_status = 0;
	print_env(*exec->env);
	return (0);
}

/*
//REVIEW - print_env

//		For every characters of the environment, if they have '=',
		we print them.
*/
static void	print_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			_fd_printf(1, "%s\n", env[i]);
		++i;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:46:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/05 15:21:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	print_env(char **env);

int	ft_env(char **args, t_exec *exec)
{
	(void)args;
	exec->exit_status = 0;
	print_env(*exec->env);
	return (0);
}

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

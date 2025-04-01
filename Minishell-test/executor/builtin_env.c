/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:46:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/01 16:16:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_env(char **args, t_exec *exec)
{
	int		i;
	char	**env;

	(void)args;
	i = 0;
	env = *exec->env;
	if (!env)
		return (0);
	while (env[i])
		_fd_printf(1, "%s\n", env[i++]);
	return (0);
}

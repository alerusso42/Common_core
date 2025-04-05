/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:47:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/05 15:20:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_pwd(char **args, t_exec *exec)
{
	char	*pwd;

	(void)args;
	exec->exit_status = 0;
	pwd = ft_getenv(*exec->env, "PATH", NULL);
	if (!pwd)
	{
		pwd = getcwd(NULL, 0);
	}
	if (!pwd)
		return (0);
	_fd_printf(1, "%s", pwd);
	return (0);
}

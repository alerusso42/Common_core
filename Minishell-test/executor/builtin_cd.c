/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:47:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/05 15:25:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	up_env(char **update, char *old_pwd, char *pwd, t_exec *exec);

int	ft_cd(char **args, t_exec *exec)
{
	char	*old_pwd;
	char	*pwd;
	char	**pwd_update;

	exec->exit_status = 0;
	if (args[1] && args[2])
	{
		exec->exit_status = 1;
		return (bash_message(E_CD_ARGS, NULL), 0);
	}
	if (!args[1])
		return (0);
	old_pwd = getcwd(NULL, 0);
	exec->exit_status = chdir(args[1]);
	if (exec->exit_status == -1)
		return (0);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (0);
	pwd_update = (char **)ft_calloc(2, sizeof(char *));
	if (!pwd_update)
		error(E_MALLOC);
	pwd_update[0] = NULL;
	up_env(pwd_update, old_pwd, pwd, exec);
	return (0);
}

static int	up_env(char **update, char *old_pwd, char *pwd, t_exec *exec)
{
	char	*str;

	str = ft_strjoin("PWD=", pwd);
	if (!str)
		return (free(update), error(E_MALLOC));
	update[1] = str;
	ft_export(update, exec);
	free(str);
	str = ft_strjoin("OLDPWD=", old_pwd);
	if (!str)
		return (free(update), error(E_MALLOC));
	update[1] = str;
	ft_export(update, exec);
	free(str);
	free(update);
	return (0);
}

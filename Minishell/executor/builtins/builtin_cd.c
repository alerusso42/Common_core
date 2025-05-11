/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:47:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/11 12:41:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

static int	up_env(char **update, char *old_pwd, char *pwd, t_exec *exec);
static void	back_to_home(char **env, char **new);
static int	dir_is_invalid(char *dir, t_exec *exec);

/*REVIEW - ft_cd

//		Cd is a program that takes ONLY one argument.

//		If there are no arguments, it does nothing, and returns Exit Code 0.
		Same if there are more than one arguments, but returns Exit Code 1.
		Same if there is one or more pipe, returning Exit Code 0.

//		Basically, the cd program does three operations:
			Update the environment variable OLDPWD with getcwd;
		 	change the current directory with chdir;
			Update the environment variable PWD with getcwd.
		The environment changes must be apply only if the calls of
		getcwd and chdir are successful.
		To apply the environment changes, we call ft_export.

//		Operations:
		1)	Check for args size. If more than one arguments, Exit Code 1.
			If less than one, Exit Code 0;
		2)	We get old_pwd, we change the directory, we get pwd;
		3)	We alloc a matrix (pwd_update), that will store the data
			to pass to ft_export (to update OLD_PWD and PWD);
		4)	We call up_env. Go below.
*/
//FIXME - Messaggio errore "cd executor/M"
int	ft_cd(char **args, t_exec *exec)
{
	char	*old_pwd;
	char	*pwd;
	char	**pwd_update;
	char	*new;

	*exec->exit_code = 0;
	if (args[1] && args[2])
		return (bash_message(E_CD_ARGS, NULL), set_exit_code(exec, 1));
	if (dir_is_invalid(args[1], exec) || exec->at_least_one_pipe)
		return (0);
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		error(E_MALLOC, exec);
	new = args[1];
	if (!args[1])
		back_to_home(*exec->env, &new);
	if (chdir(new) != 0)
		return (bash_message(E_CD, new), free(old_pwd), set_exit_code(exec, 1));
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (free(old_pwd), error(E_MALLOC, exec));
	pwd_update = (char **)ft_calloc(3, sizeof(char *));
	if (!pwd_update)
		return (free(old_pwd), free(pwd), error(E_MALLOC, exec));
	return (up_env(pwd_update, old_pwd, pwd, exec), 0);
}

static int	dir_is_invalid(char *dir, t_exec *exec)
{
	if (access(dir, F_OK) == -1)
	{
		bash_message(E_CD, dir);
		set_exit_code(exec, 1);
		return (_YES);
	}
	return (_NO);
}

/*REVIEW - back_to_home

//	cd without arguments change current directory to $HOME (from env).		
	If $HOME is unsetted, bash prints a unique message.
*/
static void	back_to_home(char **env, char **new)
{
	*new = ft_getenv(env, "HOME", NULL);
	if (!*new)
	{
		bash_message(E_CD_NOHOME, NULL);
		return ;
	}
	while (**new && **new != '=')
		++(*new);
	if (**new == '=')
		++(*new);
}

/*REVIEW - update_environment

//		1)	We strjoin PWD= and the current pwd: ft_export mimics the
			real export, so it understand this syntax;
		2)	We call ft_export, and we free the str;
		3)	Same for OLDPWD. Lastly, we free the update matrix.
*/
static int	up_env(char **update, char *old_pwd, char *pwd, t_exec *exec)
{
	char	*str;

	update[0] = NULL;
	str = ft_strjoin("PWD=", pwd);
	if (!str)
		return (free(old_pwd), free(pwd), free(update), error(E_MALLOC, exec));
	update[1] = str;
	ft_export(update, exec);
	free(str);
	str = ft_strjoin("OLDPWD=", old_pwd);
	if (!str)
		return (free(old_pwd), free(pwd), free(update), error(E_MALLOC, exec));
	update[1] = str;
	ft_export(update, exec);
	free(str);
	free(update);
	free(old_pwd);
	free(pwd);
	return (0);
}

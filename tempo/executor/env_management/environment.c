/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:26:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/28 19:21:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

//NOTE -	TO USE THESE FUNCTION, YOU MUST USE cpy_env FIRST!!!
//			We need to copy the environment to heap first, and saving the
//			new environment, its size and its last element.
//			Execution part needs these three variables to work properly.
//
//
//NOTE - Usage: give the environment taken in main;
//				the address of a char** variable, for the copied environment; 
//				the address of an int variable, that will store the env size;
//				the address of an int variable, that will store env last elem.
/*
//REVIEW - cpy_env

//		Operations:
		1)	Finds the search string in the environment matrix, skipping '=';
		2)	Where, if not NULL, is set to i if env[i], otherwise to -1;
		3)	Returns env[i], that MUST NOT BE FREED.
*/
int	cpy_env(char **old_env, char ***new_env, int *env_size, int *last_env)
{
	int	i;

	if (!old_env)
		return (E_NOENV);
	i = 0;
	while (old_env[i])
		++i;
	*new_env = ft_calloc(i + *env_size + 1, sizeof(char *));
	if (!*new_env)
		return (E_MALLOC);
	i = 0;
	while (old_env[i])
	{
		(*new_env)[i] = ft_strdup(old_env[i]);
		if (!(*new_env)[i])
		{
			*new_env = _free_matrix(*new_env);
			return (E_MALLOC);
		}
		++i;
	}
	if (*env_size == 0)
		*env_size = i;
	*last_env = i;
	return (0);
}

//NOTE - Returns the content of an item in the environment, if exist. 
//				give **environment (NOT ADDRESS);
//				the string to search; 
//				an optional int ptr. If not NULL, it will be given the
//				index of the env element, or -1 if not found.
//				You can safely pass it to NULL.
//NOTE - YOU MUST NOT FREE THE RETURNED STRING! It's env memory!!!

char	*get_env(char **env, char *search)
{
	char	*item;

	item = ft_getenv(env, search, NULL);
	if (!item)
		return (NULL);
	while (*item && *item != '=')
		++item;
	if (!*item)
		return (NULL);
	++item;
	return (item);
}

//NOTE - 	Returns this stuff: "~/42projects/Minishell$"
//			Usage: give **environment (NOT ADDRESS), returns pwd location.
//NOTE - YOU MUST FREE THE RETURNED STRING!	If NULL is returned, is E_MALLOC!
/*
//REVIEW - get_pwd_address

//		Operations:
		1)	Get pwd and home from the environment;
		2)	If pwd does not exists, return the pwd from getcwd;
		3)	If pwd exists but home does not, return pwd + 4,
			because we skip the first four bytes (PWD=/user/homes/...);
		4)	If both pwd and home exists in env, 
			if pwd + 4 (/user/homes/...) is equal to home + 5 (we skip HOME=),
				we return pwd skipping home_len bytes, and putting "~/" behind;
			Else
				we return pwd + 4.
*/
char	*get_pwd_address(char **env)
{
	char	*pwd;
	char	*home;
	int		home_len;

	pwd = ft_getenv(env, "PWD", NULL);
	home = ft_getenv(env, "HOME", NULL);
	if (!pwd)
		return (getcwd(NULL, 0));
	else if (pwd && !home)
	{
		return (ft_strdup(pwd + 4));
	}
	else if (pwd && home)
	{
		home_len = ft_strlen(home);
		if (ft_strncmp(pwd + 4, home + 5, home_len - 5))
			return (ft_strdup(pwd + 4));
		return (_ft_strjoin_free(ft_strdup("~/"), ft_strdup(pwd + home_len)));
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:47:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/03 12:49:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	erase_one(char *item, char ***env, t_exec *exec);

int	ft_unset(char **args, t_exec *exec)
{
	int		i;

	i = 1;
	while (args[i])
	{
		if (!env_pars(args[i], NULL, NULL, NULL))
			erase_one(args[i], exec->env, exec);
		else
			bash_message(E_ENV_PARSING, args[i]);
		++i;
	}
	return (0);
}

static int	erase_one(char *item, char ***env, t_exec *exec)
{
	int	i;
	int	j;
	int	item_len;
	int	env_len;

	if (!(*env)[0])
		return (0);
	i = -1;
	item_len = ft_strlen(item);
	while ((*env)[++i])
	{
		env_len = _sub_strlen((*env)[i], "+=", EXCL);
		if (!ft_strncmp(item, (*env)[i], item_len) && \
		!ft_strncmp(item, (*env)[i], env_len))
			break ;
	}
	if (!(*env)[i])
		return (0);
	free((*env)[i]);
	(*env)[i] = NULL;
	j = i;
	while ((*env)[++j])
		(*env)[i++] = (*env)[j];
	(*env)[i] = NULL;
	*exec->last_env -= 1;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:26:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/01 17:02:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	copy_env(char **stack_env, char ***heap_env, int *env_size, int *last_env)
{
	int	i;

	if (!stack_env)
		return (E_NOENV);
	i = 0;
	while (stack_env[i])
		++i;
	*heap_env = ft_calloc(i + 1, sizeof(char *));
	if (!*heap_env)
		return (E_MALLOC);
	i = 0;
	while (stack_env[i])
	{
		(*heap_env)[i] = ft_strdup(stack_env[i]);
		if (!(*heap_env)[i])
		{
			*heap_env = _free_matrix(*heap_env);
			return (E_MALLOC);
		}
		++i;
	}
	*env_size = i;
	*last_env = i;
	return (0);
}

char	*ft_getenv(char **env, char *search)
{
	int		search_len;
	int		item_len;

	search_len = ft_strlen(search);
	while(*env)
	{
		item_len = _sub_strlen(*env, "=", EXCL);
		if (!ft_strncmp(search, *env, search_len) && \
		!ft_strncmp(search, *env, item_len))
			return (*env);
		++env;
	}
	return (NULL);
}

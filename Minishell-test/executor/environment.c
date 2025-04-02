/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:26:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/02 19:02:25 by alerusso         ###   ########.fr       */
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
	*heap_env = ft_calloc(i + *env_size + 1, sizeof(char *));
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
	if (*env_size == 0)
		*env_size = i;
	*last_env = i;
	return (0);
}

int	expand_env(char ***env, int *env_size)
{
	char	**new_env;
	int		temp;

	if (copy_env(*env, &new_env, env_size, &temp) == E_MALLOC)
		error(E_MALLOC);
	*env_size *= 2;
	_free_matrix(*env);
	*env = new_env;
	return (0);
}

char	*ft_getenv(char **env, char *search, int *where)
{
	int		search_len;
	int		item_len;
	int		i;

	search_len = ft_strlen(search);
	i = 0;
	while(env[i])
	{
		item_len = _sub_strlen(env[i], "=", EXCL);
		if (!ft_strncmp(search, env[i], search_len) && \
		!ft_strncmp(search, env[i], item_len))
			break ;
		++i;
	}
	if (where)
		*where = (i * (env[i] != NULL)) + (-1 * (env[i] == NULL));
	return (env[i]);
}

int	env_pars(char *item, int *no_eq_plus, int *name_size, int *cont_size)
{
	int	i;

	if (!ft_isalpha(*item) && *item != '_')
		return (E_ENV_PARSING);
	i = 1;
	while (item[i] && (ft_isalnum(item[i]) || item[i] == '_'))
		++i;
	if (item[i] && item[i] != '=' && item[i] != '+')
		return (E_ENV_PARSING);
	else if (no_eq_plus == NULL)
		return (0);
	*name_size = i;
	*no_eq_plus = 1;
	if (item[i] == '+' && item[i + 1] == '=')
		*no_eq_plus += 1;
	while (item[i])
		++i;
	*cont_size = i - *no_eq_plus - *name_size;
	return (0);
}

void	print_env(char **env, int print_init)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		if (print_init)
			_fd_printf(1, "declare -x ");
		if (print_init || ft_strchr(env[i], '='))
			_fd_printf(1, "%s\n", env[i]);
		++i;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:26:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/05 14:39:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

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

int	expand_env(char ***env, int *env_size)
{
	char	**new_env;
	int		temp;

	if (cpy_env(*env, &new_env, env_size, &temp) == E_MALLOC)
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
	while (env[i])
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

char	*get_pwd_address(char **env)
{
	char	*pwd;
	char	*home;
	int		home_len;

	pwd = ft_getenv(env, "PWD", NULL);
	home = ft_getenv(env, "HOME", NULL);
	if (!pwd && !home)
		return (ft_strdup(getcwd(NULL, 0)));
	else if (pwd && !home)
	{
		return (ft_strdup(pwd));
	}
	else if (pwd && home)
	{
		home_len = ft_strlen(home);
		if (ft_strncmp(pwd, home, home_len))
			return (ft_strdup(pwd));
		return (_ft_strjoin_free(ft_strdup("~"), ft_strdup(pwd + home_len)));
	}
	return (NULL);
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

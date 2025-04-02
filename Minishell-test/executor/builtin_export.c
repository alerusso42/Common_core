/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:47:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/02 19:00:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	add_one(char *item, char ***env, t_exec *exec, int pars_data[4]);
static void	insert(char *item, char ***env, t_exec *exec, int pars_data[4]);

int	ft_export(char **args, t_exec *exec)
{
	int		i;
	int		pars_data[4];	

	i = 1;
	if (!args[1])
		return (print_env(*exec->env, _YES), 0);
	while (args[i])
	{
		if (!env_pars(args[i], &pars_data[0], &pars_data[1], &pars_data[2]))
			add_one(args[i], exec->env, exec, pars_data);
		else
			bash_message(E_ENV_PARSING, args[i]);
		++i;
	}
	return (0);
}

static void	add_one(char *item, char ***env, t_exec *exec, int pars_data[4])
{
	int		where;
	char	*name;

	if (*exec->env_size <= *exec->last_env + 1)
		if (expand_env(exec->env, exec->env_size) == E_MALLOC)
			error(E_MALLOC);
	name = (char *)ft_calloc(pars_data[ENV_NAME_SIZE] + 2, sizeof(char));
	if (!name)
		error(E_MALLOC);
	_sub_strcpy(name, item, "+=", EXCL);
	if (ft_getenv(*env, name, &where) && pars_data[ENV_NO_EQ_PLUS] != 2)
	{
		free((*env)[where]);
		(*env)[where] = NULL;
		*exec->last_env -= 1;
	}
	else if (where < 0)
		where = *exec->last_env;
	free(name);
	name = NULL;
	pars_data[ENV_WHICH_VAL] = where;
	insert(item, env, exec, pars_data);
}

static void	insert(char *item, char ***env, t_exec *exec, int pars_data[4])
{
	int		where;
	int		skip_until_content;
	char	*cont;

	where = pars_data[ENV_WHICH_VAL];
	skip_until_content = pars_data[ENV_NAME_SIZE] + pars_data[ENV_NO_EQ_PLUS];
	if (!(*env)[where])
	{
		(*env)[where] = ft_strdup(item);
		if (!(*env)[where])
			error(E_MALLOC);
		*exec->last_env += 1;
		return ;
	}
	cont = (char *)ft_calloc(pars_data[ENV_CONT_SIZE] + 2, sizeof(char));
	if (!cont)
		error(E_MALLOC);
	_sub_strcpy(cont, item + skip_until_content, "", EXCL);
	if (pars_data[ENV_NO_EQ_PLUS] == 0 || pars_data[ENV_NO_EQ_PLUS] == 1)
	{
		(*env)[where][skip_until_content] = 0; 
	}
	(*env)[where] = _ft_strjoin_free((*env)[where], cont);
	if (!(*env)[where])
		error(E_MALLOC);
}

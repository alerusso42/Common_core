/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:47:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/14 10:51:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	add_one(char *item, char ***env, t_exec *exec, int pars_data[4]);
static void	insert(char *item, char ***env, t_exec *exec, int pars_data[4]);
static char	*remove_plus(char *str);
static void	print_export(char **env);

/*
//REVIEW - ft_export

//		Export can take any number of arguments.
		If there are no arguments, it prints all the environment, including
		no initialized values (see below print_export).

//		Export argument may be valid or invalid. There is a parsing for it.
		Valid arguments examples are:
		"MAN=carlo";	"MAN=";  "MAN";	"_MAN2"; "___M_A_N+=";	"MAN=2c$ar=lo*"
		Invalid arguments examples are:
		"2MAN=conti";	"*MAN="; "M2AN"; "_MAN("; "___M_A_N-=";	"M@N+=conti"
		To valid them, see env_pars function in environment.c.

//		If one argument is not valid, we do the following, but the ES will be
		set to 1.
		If there are pipes in the command line, the export will not be done,
		but env_pars will still be done anyway.

//		Operations:
		1)	If there are no arguments, we print the environment, including
			no initialized data;
		2)	For every argument in args, we loop using index i;
		3)	If the parsing succeds, and if there are no pipe, we add the new
			value in the environment (see below add_one).
			Else if the parsing fails, we print an error message and set ES to
			1, and we go to the next argument.
*/
int	ft_export(char **args, t_exec *exec)
{
	int		i;
	int		pars_data[4];	

	i = 1;
	*exec->exit_status = 0;
	if (!args[1])
		return (print_export(*exec->env), 0);
	while (args[i])
	{
		if (!env_pars(args[i], &pars_data[0], &pars_data[1], &pars_data[2]))
		{
			if (exec->at_least_one_pipe == _NO)
				add_one(args[i], exec->env, exec, pars_data);
		}
		else
		{
			bash_message(E_ENV_PARSING, args[i]);
			*exec->exit_status = 1;
		}
		++i;
	}
	return (0);
}

/*
//REVIEW - add_one

//		So, we need to manage three cases:
			1)	export MAN
			2)	export MAN=Carlo
			3)	export MAN+=Conti

//		In the env_pars, we have saved three data in a int array (pars_data):
		pars_data[0] --> ENV_NO_EQ_PLUS: 0 means case 1), 1 case 2), 2 3);
		pars_data[1] --> ENV_NAME_SIZE:  The len of the env title (MAN);
		pars_data[2] --> ENV_CONT_SIZE:  The len of the env cont (Carlo c.);

//		For item, we mean the arg we are currently managing.

//		Operations:
		1)	If the size of env is not enough to get a new element,
			we realloc it, doubling its size;
		2)	We alloc for the name of the item to update/add;
		3)	We copy the content of the item into name, until \0, +, =.
			We now have, for example, "OLDPWD";
		4)	If the operation is not a plus (pars_data[ENV_NO_EQ_PLUS] != 2)
			and the item already exists, free it and decrease the number of
			elements in the env matrix. ft_getenv sets where to the index
			of the item.
			Else, if the operation is a plus or the item does not exists,
			we set the where variable to the index of the last member in env;
		5)	We save where in pars_data[3] --> pars_data[ENV_WHICH_VAL].
		6)	We insert the value in the env matrix, in the where position.
			See below the insert function.
*/
static void	add_one(char *item, char ***env, t_exec *exec, int pars_data[4])
{
	int		where;
	char	*name;

	if (*exec->env_size <= *exec->last_env + 1)
		if (expand_env(exec->env, exec->env_size, exec) == E_MALLOC)
			error(E_MALLOC, exec);
	name = (char *)ft_calloc(pars_data[ENV_NAME_SIZE] + 2, sizeof(char));
	if (!name)
		error(E_MALLOC, exec);
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

/*
//REVIEW - insert

//		Operations:
		1)	If the element of env in index does not exists, we simply add it.
			This happens when the item does not exist yet;
		2)	Else, we calculate the length of the item, excluding the content
			(USER+=48) -->	NAME_SIZE + ENV_NO_EQ_PLUS (ENEP can be 0,1,2);
		3)	If we do not have to add the content (ENV_NO_EQ_PLUS == 0,1)
			We put a \0 in the index of the first character of content;
		4)	We strjoin the current element with the new content.
*/
static void	insert(char *item, char ***env, t_exec *exec, int pars_data[4])
{
	int		where;
	int		skip_until_content;
	char	*cont;

	where = pars_data[ENV_WHICH_VAL];
	if (!(*env)[where])
	{
		(*env)[where] = remove_plus(ft_strdup(item));
		if (!(*env)[where])
			error(E_MALLOC, exec);
		*exec->last_env += 1;
		return ;
	}
	cont = (char *)ft_calloc(pars_data[ENV_CONT_SIZE] + 2, sizeof(char));
	if (!cont)
		error(E_MALLOC, exec);
	skip_until_content = pars_data[ENV_NAME_SIZE] + pars_data[ENV_NO_EQ_PLUS];
	_sub_strcpy(cont, item + skip_until_content, "", EXCL);
	if (pars_data[ENV_NO_EQ_PLUS] == 0 || pars_data[ENV_NO_EQ_PLUS] == 1)
	{
		(*env)[where][skip_until_content] = 0;
	}
	(*env)[where] = _ft_strjoin_free((*env)[where], cont);
	if (!(*env)[where])
		error(E_MALLOC, exec);
}

static char	*remove_plus(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '+')
		++i;
	if (str[i] == '+')
		_cut_string(str + i, 0, 0);
	return (str);
}

/*
//REVIEW - print_export

//		This is how the print must look like:
		declare -x ___M_A_N
		declare -x MAN="Carlo Conti"
		...

//		Operations:
		1)	If the environment is NULL, we return;
		2)	For every argument in args, we loop using index i;
		3)	We print "declare -x ";
		4)	While the arg has characters, and they are different than '=',
			print them;
		5)	If there are no more characters, we print \n and continue;
		6)	Else, we print the following characters, preceeded by a " and
			followed by "\n.
			So, they'll look like MAN="Carlo Conti"\n.
*/
static void	print_export(char **env)
{
	int	i;
	int	j;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		write(1, "declare -x ", 11);
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			write(1, &env[i][j++], 1);
		if (!env[i][j])
		{
			write(1, "\n", 1);
			++i;
			continue ;
		}
		write(1, "=\"", 2);
		while (env[i][++j])
			write(1, &env[i][j], 1);
		write(1, "\"\n", 2);
		++i;
	}
}

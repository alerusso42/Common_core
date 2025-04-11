/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:32:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/11 09:28:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int			get_one(t_exec *exec, t_token **token, int cmd_num);
int			count_arguments(t_token *token);
static void	get_builtin_functions(t_exec *exec);

int	get_commands_data(t_exec *exec, t_token *token)
{
	int	cmd_num;

	get_builtin_functions(exec);
	cmd_num = 0;
	while (token->content)
	{
		if (token->type == COMMAND)
		{
			if (get_one(exec, &token, cmd_num) != 0)
				error(E_MALLOC, exec);
			exec->which_cmd[cmd_num] = \
			is_a_builtin_cmd(exec->commands[cmd_num][0]);
			++cmd_num;
		}
		else
			++token;
	}
	return (0);
}

int	get_one(t_exec *exec, t_token **token, int cmd_num)
{
	int	command_argc;
	int	i;

	command_argc = count_arguments(*token);
	exec->commands[cmd_num] = \
	(char **)ft_calloc(command_argc + 1, sizeof(char *));
	if (!exec->commands[cmd_num])
		error(E_MALLOC, exec);
	i = 0;
	while ((i != command_argc))
	{
		if ((*token)->type == COMMAND || (*token)->type == ARGUMENT)
		{
			exec->commands[cmd_num][i] = ft_strdup((*token)->content);
			if (!exec->commands[cmd_num][i])
				error(E_MALLOC, exec);
			++i;
		}
		++(*token);
	}
	return (0);
}

int	count_arguments(t_token *token)
{
	int	counter;

	counter = 1;
	++token;
	while ("LOOP: counts every argument, considering parenthesis")
	{
		if (is_exec_sep(token->type) == _YES || !token->content)
			break ;
		else if (token->content && token->prior != (token + 1)->prior)
			break ;
		else if (token->type == COMMAND || token->type == ARGUMENT)
			counter++;
		++token;
	}
	return (counter);
}

static void	get_builtin_functions(t_exec *exec)
{
	exec->builtins[B_ECHO] = ft_echo;
	exec->builtins[B_CD] = ft_cd;
	exec->builtins[B_PWD] = ft_pwd;
	exec->builtins[B_EXPORT] = ft_export;
	exec->builtins[B_UNSET] = ft_unset;
	exec->builtins[B_ENV] = ft_env;
	exec->builtins[B_EXIT] = ft_exit;
}

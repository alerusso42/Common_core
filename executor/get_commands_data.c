/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:32:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/26 17:11:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	get_one(t_exec *exec, t_token **token, int cmd_num);
int	count_arguments(t_token *token);

int	get_commands_data(t_exec *exec, t_token *token)
{
	int	cmd_num;

	cmd_num = 0;
	while (token->content)
	{
		if (token->type == COMMAND)
		{
			if (get_one(exec, &token, cmd_num) != 0)
				return (E_MALLOC);
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
	exec->commands[cmd_num] = (char **)ft_calloc(command_argc + 1, sizeof(char *));
	if (!exec->commands[cmd_num])
		return (E_MALLOC);
	i = 0;
	while (i != command_argc)
	{
		exec->commands[cmd_num][i] = ft_strdup((*token)->content);
		if (!exec->commands[cmd_num][i])
			return (E_MALLOC);
		++i;
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
		if (token->type != ARGUMENT)
			break ;
		if (token->prior != (token + 1)->prior)
			break ;
		counter++;
		++token;
	}
	return (counter);
}

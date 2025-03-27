/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/26 17:08:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	goto_next_command_block(t_token **tokens);

int	execute(t_token *tokens)
{
	t_exec	*exec;

	if (!tokens)
		error(E_ARGS);
	if (alloc_memory(&exec, count_commands(tokens)) != 0)
		return (error(E_MALLOC));
	if (get_commands_data(exec, tokens) != 0)
		return (error(E_MALLOC));
	while (tokens->content)
	{
		get_file_data(exec, tokens);
		goto_next_command_block(&tokens);
	}
	free_memory();
	return (0);
}

void	goto_next_command_block(t_token **tokens)
{
	while ((*tokens)->content && is_exec_sep((*tokens)->type) == _NO)
	{
		++(*tokens);
	}
	if ((*tokens)->content)
		++(*tokens);
}

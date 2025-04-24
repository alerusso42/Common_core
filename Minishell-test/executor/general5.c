/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:24:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/24 20:32:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	find_command_argument_index(t_token *token)
{
	t_token	*current;
	int		cmd_argc;

	current = token;
	cmd_argc = 0;
	while (token->id != 0 && token->cmd_num != (token - 1)->cmd_num)
		--token;
	while (token != current)
	{
		
	}
}
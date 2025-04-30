/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:48:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/30 17:05:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	p_tok(t_token *token)
{
	t_token	*head;

	head = token;
	_fd_printf(1, "\n[START]\n++++++++++++++++++++\n");
	while (token->content)
	{
		_fd_printf(1, "\n+------------------+\nToken %d:\n", token->id);
		_fd_printf(1, "Content:\t|%s|\n", token->content);
		_fd_printf(1, "Id:\t\t|%d|\n", token->id);
		_fd_printf(1, "Type:\t\t|%d|\n", token->type);
		_fd_printf(1, "Priority:\t|%d|\n", token->prior);
		++token;
	}
	token = head;
	_fd_printf(1, "\n+------------------+\n[END]\n++++++++++++++++++++\n");
	_fd_printf(1, "\nTest for: ");
	while (token->content)
	{
		_fd_printf(1, "%s ", token->content);
		++token;
	}
	_fd_printf(1, "\n\033[1;32mExecution:\033[0m\n");
}

void	p_end(t_exec *exec)
{
	_fd_printf(1, "\n\033[1;33mE. code:\033[0m %d", *exec->exit_status);
}

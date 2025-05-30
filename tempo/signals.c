/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:40:55 by ftersill          #+#    #+#             */
/*   Updated: 2025/05/06 12:16:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// -CTRL-backslash = SIGQUIT gestito con la flag SIG_IGN
// -CTRL-C = SIGINT
// -CTRL-D command is controlled in the start() function cause 
//		it sends a NULL string to readline()
void	signals(int signal, siginfo_t *info, void *s)
{
	(void)info;
	(void)s;
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_read_terminal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:40:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

int	read_terminal(t_stack *a)
{
	char	*line;

	line = get_next_line(1);
	if (!line)
		return (ER_MALLOC_ERROR);
	while (line)
	{
		l_printf("linea: %s\n", line);
		free(line);
		line = get_next_line(0);
	}
	(void)a;
	return (0);
}

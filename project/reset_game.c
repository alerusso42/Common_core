/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/23 15:48:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

void	*storage_structs(t_all *update, int mode)
{
	static t_all	*all;
	
	if (mode == UPDATE)
	{
		all = update;
		return (NULL);
	}
	else
		return (all);
}

int	end(int keycode)
{
	t_all	*all;

	(void)keycode;
	all = (t_all *)storage_structs(NULL, GET);
	full_reset(4, &all->input, &all->map, &all->random, &all->mlx);
	free(all);
	all = NULL;
	exit(0);
}
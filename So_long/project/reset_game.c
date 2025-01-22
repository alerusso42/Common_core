/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/22 12:57:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

void	end(t_all *all)
{
	full_reset(4, &all->input, &all->map, &all->random, &all->mlx);
	free(all);
	all = NULL;
	exit(0);
}
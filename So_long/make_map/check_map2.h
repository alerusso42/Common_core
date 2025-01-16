/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/16 15:11:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP2_H
# define CHECK_MAP2_H
# include "types.h"
# include "ft_printf.h"
# include "check_map.h"

int	count_stuff(t_solution *solution, t_onebyte character, \
int size_x, int size_y);

/*
int	last_chk_path(t_solution *solution, int size_x, int size_y)
{
	
}*/

int	sixth_chk_colet(t_solution *solution, int size_x, int size_y)
{
	if (count_stuff(solution, 'E', size_x, size_y) < 1)
		return (1);
	return (0);
}

int	fifth_chk_enemy(t_solution *solution, int size_x, int size_y)
{
	int	enemy_num;

	enemy_num = solution->variable_3_enemy_num;
	if (count_stuff(solution, '$', size_x, size_y) != enemy_num)
		return (1);
	return (0);
}

#endif
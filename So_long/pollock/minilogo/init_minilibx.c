/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:17:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/13 14:27:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilogo.h"

int	init_minilibx(t_minilibx **libx, int win_x, int win_y, char *win_name)
{
	if (libx == NULL)
		return (1);
	*libx = (t_minilibx *)malloc(sizeof(t_minilibx));
	if (!(*libx))
		return (1);
	(*libx)->connection = mlx_init();
	if (!((*libx)->connection))
		return (free(*libx), 1);
	(*libx)->window = mlx_new_window((*libx)->connection, win_x, win_y,\
	 win_name);
	 if (!((*libx)->window))
		return (free((*libx)->connection), free(*libx), 1);
	return (0);
}

void	free_minilibx(t_minilibx **libx)
{
	if (!libx)
		return ;
	if ((*libx)->connection)
		free((*libx)->connection);
	(*libx)->connection = NULL;
	if ((*libx)->window)
		free((*libx)->window);
	(*libx)->window = NULL;
	if ((*libx))
		free(*libx);
}
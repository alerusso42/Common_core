/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_turtle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/13 17:25:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilogo.h"

int	init_turtle(t_turtle **turtle, int screen_size_x, int screen_size_y,\
 t_minilibx *libx)
{
	if (turtle == NULL)
		return (1);
	*turtle = (t_turtle *)malloc(sizeof(t_turtle));
	if (!(*turtle))
		return (1);
	(*turtle)->x_pos = 0;
	(*turtle)->y_pos = 0;
	(*turtle)->penup = OFF;
	(*turtle)->pensize = 1;
	(*turtle)->angle = 0;
	(*turtle)->screen_size_x = screen_size_x;
	(*turtle)->screen_size_y = screen_size_x;
	(*turtle)->screen_center_x = screen_size_x / 2;
	(*turtle)->screen_center_y = screen_size_y / 2;
	(*turtle)->x_pos = screen_size_x / 2;
	(*turtle)->y_pos = screen_size_y / 2;
	(*turtle)->screen_color = 0X000000;
	(*turtle)->connection = libx->connection;
	(*turtle)->window = libx->window;
	return (0);
}

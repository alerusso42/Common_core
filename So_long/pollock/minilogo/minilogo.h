/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilogo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:27:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/16 10:03:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILOGO_H
# define MINILOGO_H
# include <malloc.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "minilibx/mlx.h"
# define FORWARD 0
# define BACK 1
# define SIZE_X_WINDOW 500
# define SIZE_Y_WINDOW 1500
# define ON 1
# define OFF 0

// angle goes from 0 to 359. Points to the direction you need to add pixels.
typedef struct s_turtle
{
	int		x_pos;
	int		y_pos;
	int		angle;
	int		penup:1;
	int		pensize;
	int		pencolor;
	int		screen_size_x;
	int		screen_size_y;
	int		screen_center_x;
	int		screen_center_y;
	int		screen_color;
	void	*connection;
	void	*window;
	
}				t_turtle;

typedef struct s_minilibx
{
	void	*connection;
	void	*window;
}				t_minilibx;

int		init_minilibx(t_minilibx **libx, int win_x, int win_y, char *win_name);
void	free_minilibx(t_minilibx **libx);
int	init_turtle(t_turtle **turtle, int screen_size_x, int screen_size_y,\
 t_minilibx *libx);
void	right(int amount, t_turtle *turtle);
void	left(int amount, t_turtle *turtle);
void	forward(int amount, t_turtle *turtle);
void	back(int amount, t_turtle *turtle);
void	pendown(t_turtle *turtle);
void	penup(t_turtle *turtle);
void	setxy(int x, int y, t_turtle *turtle);
void	home(t_turtle *turtle);
void	clearscreen(t_turtle *turtle);
void	pensize(int new_pensize, t_turtle *turtle);
void	pencolor(int new_pencolor, t_turtle *turtle);

#endif
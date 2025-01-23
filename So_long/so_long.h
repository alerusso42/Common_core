/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:49:29 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/21 09:43:59 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx-linux/mlx_int.h"
# include "./minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <unistd.h>
# include <linux/stat.h>
# include <sys/stat.h>
# include <stddef.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef	struct s_sprite
{
	int		direction;
	int		look_to;
	void	*link_front;
	void	*link_side_dx;
	void	*link_side_sx;
	void	*link_back;
	void	*fairy1;
	void	*fairy2;
	void	*zelda;
	void	*zelda_horny;
	void	*tree;
	void	*floor;
	void	*knight_front;
	void	*knight_back;
	void	*knight_dx;
	void	*knight_sx;
}	t_sprite;

typedef struct	s_imma
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		coll;
	t_sprite	sprite;
}	t_imma;

int		count_lines(void);
void	ft_free(char **map);
int		search(char **map, int n);
int		required(char **map, t_imma *imma);
int		is_sqare(char **map, int lines);
void	find_p(char **map, int *x, int *y);
void	floodfill(char **map, int x, int y);
int		path_finder(char **map);
int		char_check(char **map);
char	**get_map(t_imma *imma);
int		input_control(int keysym, t_imma *imma);
int		input_mouse_control(t_imma *imma);
void	take_immag(t_imma	*imma);
void	print_map(t_imma *imma);
int		game_loop(t_imma *imma);
void	move_map(t_imma *imma);
void	destroy(t_imma *imma);
void	destroy_immag(t_imma *imma);

#endif

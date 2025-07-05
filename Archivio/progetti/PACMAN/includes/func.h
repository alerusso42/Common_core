/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:41:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 11:50:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include "pacman.h"

typedef struct s_data	t_data;
typedef struct s_SDL	t_SDL;
typedef struct s_map	t_map;
typedef struct s_entity	t_entity;

int		init_all(t_data *data);
int		alloc_memory(t_data *data);
void	free_all(t_data *data);
void	free_memory(t_data *data);
int		error(t_data *data, int type);

//SECTION - Game

void	game_loop(t_data *data);
void	events(t_data *data);
void	move_enemies(t_data *data);
int		triggered(t_data *data, int en_x, int en_y);

//SECTION - Map

int	get_map(t_data *data, int map_id);

//SECTION - Engine

void	map_render(t_data *data, bool first_rend);
void	animations(t_data *data);

//SECTION - utils

uint32_t	_random(int size);
int			random_color(void);
double		proportion(double a, double b, double c, double d);
double		safe_division(double divisor, double dividend);
uint64_t	elapsed_time(uint64_t start);
int			check_extension_file(char *filename, char *extension);
int			file_size(int size[2], t_fd fd);
int			find_stuff(t_data *data, char c, int *x, int *y);
int			count_stuff(t_data *data, char c);
void		copy_map(t_map **map, t_map **old_map);
int			valid_path(t_data *data);
t_data		*getter(t_data *newdata, bool update);
int			alloc_map(t_data *data);
void		*free_map(t_map **map);
void		set_player(t_data *data);
void		set_exit(t_data *data);
int			set_enemies(t_data *data);
void		move(t_data *data, t_entity *entity, int x, int y);
void		update_speed(t_entity *entity, int move_speed, int anim_speed);
void		animate_one(t_data *data, t_entity *entity);
void		replace(t_entity *entity, int x, int y);
void		swap(t_entity *entity, int x, int y);

//SECTION - Debug

void	print_map(t_map **map, t_map **old_map);

#endif
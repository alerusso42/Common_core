/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_function_list_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:33:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 16:11:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FUNCTION_LIST_BONUS_H
# define Z_FUNCTION_LIST_BONUS_H
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define MIN_INT_VALUE -2147483648
# define MAX_INT_VALUE 2147483647
//
# if __has_include("so_long.h")
#  include "so_long.h"
# else
#  include "so_long_bonus.h"
# endif

// cc -g -Wall -Wextra -Werror main.c -Lminilibx -lmlx -lX11 -lXext -lm
//
//			GET_DATA
void		*get_data(int change_mode, int width, int heigth, char *fn);
//			AI:
//				BFS_ALGORYTHM
int			get_best_path(t_map *map, int enemy_num);
int			draw_path(t_bfs *bfs);
void		del_free(void *ptr);
t_typelist	*store_list(t_typelist *list, int mode);
void		clean_bfs(t_map *map, int enemy_num);
//				TRIGGER_ENEMIES
int			triggered(t_all *all, int en_x, int en_y);
//
int			change_mod(char *argv[], int argc);
//			CHECKS
int			check_file(char *argv, char **filename);
int			check_extension_file(char *filename, char *extension);
t_bool		find_mapsize(char *filename);
int			check_pic(t_mlx *mlx);
int			check_map(t_input *input, t_map *map, \
int size_x, int size_y);
int			count_stuff(t_map *map, t_onebyte character, \
int size_x, int size_y);
int			first_chk_char(t_input *input, t_map *map);
int			secon_chk_fillwall(t_map *map, int size_x, int size_y);
int			third_chk_player(t_map *map, int size_x, int size_y);
int			fourt_chk_exit(t_map *map, int size_x, int size_y);
int			fifth_chk_enemy(t_map *map, int size_x, int size_y);
int			sixth_chk_colet(t_map *map, int size_x, int size_y);
int			find_stuff(t_map *map, t_onebyte c, int *x, int *y);
int			last_chk_path(t_input *input, t_map *map);
//			EDIT_MAP_TOOLS
int			sort_coordinates(t_map *map, t_random *random, \
int *x, int *y);
void		secon_step_fillwall(t_map *map, int size_x, int size_y);
void		third_step_player(t_map *map, t_random *random);
void		fourt_step_exit(t_map *map, t_random *random);
void		fifth_step_enemy(t_map *map, t_random *random);
void		sixth_step_colet(t_map *map, t_random *random);
void		last_step_walls(t_map *map, t_random *random);
//			GENERAL_UTILITIES
int			ft_abs(int num);
void		ft_swap(int *x, int *y);
int			ft_pow(int base, int exponent);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen_newline(char *string);
void		*error(int error);
int			l_printf(const char *str, ...);
//			ALLOCATIONS
t_all		*alloc_data(int game_size[2], int seed, int create_or_read, \
char *fn);
t_all		*alloc_data2(t_input **input, t_map **map, t_random *random);
t_all		*alloc_data3(t_input *input, t_map *map, t_random *random);
int			alloc_user_input(t_input **input, int game_size[2]);
void		temp_set_input(t_input **input);
int			alloc_randomlist(t_random **random, int game_size);
int			alloc_mlx(t_mlx **mlx);
int			get_mlx(t_mlx *mlx, int x, int y, char *dname);
t_random	*fill_random(t_random **random, t_input *input);
void		show_random_values(t_random *random);
int			alloc_map(t_input **input, t_map **map);
int			alloc_enemies(t_map *map);
void		copy_map(t_map **map, int row_n, int col_n);
void		fill_map(t_map **map, int row_n, int col_n);
//			GET_MAP
t_bool		create_map(t_input *input, t_map *map, t_random *random);
t_bool		read_map(t_input *input, t_map *map);
void		print_map(t_map *map);
int			save_map(t_map *map, int size_x, int size_y);
int			edit_map(t_map *map, int size_x, int size_y, \
t_random *random);
//			RANDOMIZATION
int			get_randomlist(t_random **random, int game_size);
void		twist_random(t_random **random, int game_size);
void		twist_random2(t_random **random, int game_size);
void		twist_random3(t_random **random, int game_size);
int			randomize_color(int seed_1, int seed_2, int seed_3);
//			ENEMY_MAPPING
int			get_enemies_position(t_map *map, char search);
int			id_enemy(t_map *map, int x, int y);
//			PRINT_STRINGS
void		get_key_settings(t_all *all);
void		print_str_win(int layer, int color, char *str, int data);
void		p_event_triggered(t_map *map, int enemy_num);
void		p_event_lost(t_map *map, int enemy_num);
void		p_event_collectables_left(t_all *all);
//			PRINT_MAP
int			get_images(t_mlx *mlx, int *s, void *i);
void		update_screen(t_all *all, int dialga);
void		clear_screen(t_all *all);
void		*pic(t_all *all, int x, int y, int dialga);
void		*which_pac_man(t_all *all, int dialga);
void		*which_enemy(t_all *all, int x, int y);
void		animations(t_all *all, int dialga);
//			RESET MEMORY
int			full_reset(int struct_num, ...);
int			reset_pic(t_mlx *mlx);
//			MOVE_TOOL
int			move_player(t_map *map, int direction);
void		move_enemies(t_all *all, int dialga);
void		swap(int x1, int y1, int x2, int y2);
void		replace(int dest_x, int dest_y, int src_x, int src_y);
void		replace_bfs(int new[2], int old[2], int n);
//			SPEED
int			speed_one(int dialga);
int			speed_two(int dialga);
int			speed_three(int dialga);
int			speed_four(int dialga);
int			speed_five(int dialga);
//			END
void		kill_pac(void);
int			end(void);
void		quit(int keycode, t_all *all);
//			STORAGES
void		*storage_structs(t_all *update, int mode);
//			USER_SETTINGS
t_bool		switches(t_input *input, t_map *map, t_random *random);
t_bool		variables(t_input *input, t_map *map, t_random *random);
t_bool		mlx_settings(t_mlx *mlx);
int			switch_to_bonus(t_input *input, t_map *map, t_random *random);
//			DEBUG_TOOLS
void		print_bfs(t_map *map, int enemy_num);

#endif
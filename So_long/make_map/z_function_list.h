/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_function_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:33:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 11:40:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FUNCTION_LIST_H
# define Z_FUNCTION_LIST_H
# include "types.h"
# include "z_error_list.h"
# include "get_next_line_bonus.h"
# include "z_error_list.h"
# include "printf/ft_printf.h"
# include "Libft/libft.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define MIN_INT_VALUE -2147483648
# define MAX_INT_VALUE 2147483647

int			alloc_user_input(t_input **input, int game_size[2]);
void		temp_set_input(t_input **input);
int			alloc_randomlist(t_random **random, int game_size);
t_random	*fill_random(t_random **random, t_input *input);
void		show_random_values(t_random *random);
int			alloc_sol(t_input **input, t_solution **solution);
int			change_mod(char *argv[], int argc);
int			check_extension_file(char *filename, char *extension);
t_bool		find_mapsize(char *filename, int game_size[2]);
int			check_map(t_input *input, t_solution *solution, \
int size_x, int size_y);
int			count_stuff(t_solution *solution, t_onebyte character, \
int size_x, int size_y);
int			first_chk_char(t_input *input, t_solution *solution);
int			secon_chk_fillwall(t_solution *solution, int size_x, int size_y);
int			third_chk_player(t_solution *solution, int size_x, int size_y);
int			fourt_chk_exit(t_solution *solution, int size_x, int size_y);
int			fifth_chk_enemy(t_solution *solution, int size_x, int size_y);
int			sixth_chk_colet(t_solution *solution, int size_x, int size_y);
int			find_stuff(t_solution *solution, t_onebyte c, int *x, int *y);
int			last_chk_path(t_input *input, t_solution *solution);
int			edit_map(t_solution *solution, int size_x, int size_y, \
t_random *random);
int			sort_coordinates(t_solution *solution, t_random *random, \
int *x, int *y);
void		secon_step_fillwall(t_solution *solution, int size_x, int size_y);
void		third_step_player(t_solution *solution, t_random *random);
void		fourt_step_exit(t_solution *solution, t_random *random);
void		fifth_step_enemy(t_solution *solution, t_random *random);
int			error(int error);
int			l_printf(const char *str, ...);
void		ft_swap(int *x, int *y);
int			ft_pow(int base, int exponent);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen_newline(char *string);
t_bool		alloc_data(int game_size[2], int seed, int create_or_read, \
char *fn);
t_bool		alloc_data2(t_input **input, t_solution **solution, \
t_random *random);
t_bool		create_map(t_input *input, t_solution *solution, t_random *random);
t_bool		read_map(t_input *input, t_solution *solution);
void		print_solution(t_input *input, t_solution *solution, int x, int y);
void		twist_random(t_random **random, int game_size);
void		twist_random2(t_random **random, int game_size);
void		twist_random3(t_random **random, int game_size);
int			full_reset(int struct_num, ...);
int			save_map(t_solution *solution, int size_x, int size_y);
t_bool		switches(t_input *input, t_solution *solution, t_random *random);

#endif
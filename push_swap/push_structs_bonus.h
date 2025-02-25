/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_structs_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/25 16:02:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_STRUCTS_BONUS_H
# define PUSH_STRUCTS_BONUS_H

typedef unsigned char	t_bool;
typedef long long int	t_very_long;
typedef unsigned char	t_variable;

typedef struct s_data
{
	int		n;
	t_bool	to_push:1;
	int		lowest_bigger;
	int		cost;
	int		pos;
}				t_data;

typedef struct s_stack
{
	t_data		*data;
	int			biggest_num;
	int			first;
	int			last;
	int			size;
	int			half;
	int			max_num_len;
	int			is_sort:1;
	int			moves_num;
	int			command_list_length;
	int			command_list_size;
	int			furthest_position;
	int			nums_to_push;
	int			target_to_search;
	int			temp;
	t_very_long	medium;
	t_bool		order:4;
	char		*command_list;
	t_bool		block_print:1;
	t_bool		switch_1_showbinary:1;
	t_bool		switch_2_indexation:1;
	t_bool		switch_4_choose_beststart_in_insertion:1;
	t_variable	variable_1_mode:3;
	t_variable	variable_2_which_algorythm:2;
}				t_stack;

typedef struct s_settings
{
	t_bool		switch_1_showbinary:1;
	t_bool		switch_2_indexation:1;
	t_bool		switch_3_doctorstrange:1;
	t_bool		switch_4_choose_beststart_in_insertion:1;
	t_bool		switch_5_bonus:1;
	t_bool		switch_5_save_result:1;
	t_variable	variable_1_mode:3;
	t_variable	variable_2_which_algorythm:2;
}				t_settings;

typedef struct s_random
{
	int		*values;
	int		seed;
}				t_random;

#endif
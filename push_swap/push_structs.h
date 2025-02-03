/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/03 22:30:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned char	t_bool;

typedef unsigned char	t_variable;

typedef struct	s_data
{
	int		n;
	t_bool	to_push:1;
	int		lowest_bigger;
	int		cost;
	int		pos;
}				t_data;


typedef struct	s_stack
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
	t_bool		order:4;
	char		*command_list;
	t_bool		switch_1_showbinary:1;
	t_bool		switch_2_indexation:1;
	t_bool		switch_4_choose_beststart_in_insertion:1;
	t_variable	variable_1_mode:2;
	t_variable	variable_2_which_algorythm:2;
}				t_stack;

typedef struct	s_settings
{
	t_bool		switch_1_showbinary:1;
	t_bool		switch_2_indexation:1;
	t_bool		switch_3_doctorstrange:1;
	t_bool		switch_4_choose_beststart_in_insertion:1;
	t_variable	variable_1_mode:2;
	t_variable	variable_2_which_algorythm:2;
}				t_settings;

typedef struct	s_random
{
	int		*values;
	int		seed;
}				t_random;


#endif
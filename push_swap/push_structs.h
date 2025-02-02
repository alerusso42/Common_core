/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/02 18:33:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned char	t_bool;	

typedef struct	s_data
{
	int		n;
	t_bool	to_push;
	int		lowest_bigger;
	int		cost;
}				t_data;


typedef struct	s_stack
{
	t_data			*data;
	int				first;
	int				last;
	int				size;
	int				max_num_len;
	int				is_sort:1;
	int				moves_num;
	int				command_list_length;
	int				command_list_size;
	int				furthest_position;
	int				nums_to_push;
	unsigned int	order:2;
	int				top_one;
	int				bottom_one;
	char			*command_list;
	unsigned int	switch_1_showbinary:1;
	unsigned int	variable_1_mode:2;
	unsigned int	variable_2_which_algorythm:2;
}				t_stack;

typedef struct	s_settings
{
	unsigned int	switch_1_showbinary:1;
	unsigned int	variable_1_mode:2;
	unsigned int	variable_2_which_algorythm:2;
	void			*ptr;
}				t_settings;

typedef struct	s_random
{
	int		*values;
	int		seed;
}				t_random;


#endif
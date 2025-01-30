/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/30 13:59:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_stack
{
	int				*data;
	int				first;
	int				last;
	int				size;
	int				max_num_len;
	int				is_sort:1;
	int				moves_num;
	unsigned int	switch_1_showbinary:1;
	unsigned int	variable_1_mode:2;
}				t_stack;

typedef struct	s_settings
{
	unsigned int	switch_1_showbinary:1;
	unsigned int	variable_1_mode:2;
	void			*ptr;
}				t_settings;

typedef struct	s_random
{
	int		*values;
	int		seed;
	void	*ptr;
}				t_random;


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:41:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/27 00:19:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include "pacman.h"

typedef struct s_data	t_data;
typedef struct s_SDL	t_SDL;

int		init_all(t_data *data);
int		alloc_memory(t_data *data);
void	free_all(t_data *data);
void	free_memory(t_data *data);
int		error(t_data *data, int type);

//SECTION - Game

void	game_loop(t_data *data);

//SECTION - utils

uint32_t	_random(int size);
int			random_color(void);
double		proportion(double a, double b, double c, double d);
double		safe_division(double divisor, double dividend);
uint64_t	elapsed_time(uint64_t start);

#endif
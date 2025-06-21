/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/18 19:37:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H
# include "../header.h"

typedef struct s_data	t_data;

//SECTION - Main functions

int	read_file(t_data *data);
int	write_file(t_data *data);
int	checks(t_data *data);
int	loop(t_data *data);
int	update(t_data *data);

//SECTION - Parsing and memory

int	alloc_memory(t_data *data);
int	free_memory(t_data *data);
int	error(t_data *data);
int	parsing(t_data *data, int argc, char **argv);

//SECTION - Utils

__uint64_t	murmumrhash(const char *key, int len, int seed);

#endif
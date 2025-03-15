/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_function_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:02:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/14 14:38:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FUNCTION_LIST_H
# define Z_FUNCTION_LIST_H
# include "Libft/all.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

int		switch_to_bonus(t_settings *settings);
void	*storage(void *ptr, int mode);
void	reset_memory();
int		switches(t_settings *settings);
int		variables(t_settings *settings);
int		error(int error);

//	DEBUG

int		time_delay_test(void);
int		brute_wait(long long int micros);

//	PRINT

int		p_color(int color, char *s);
int		p_state(t_philo *philo, int state);

//	PARSING

int		parsing(int argc, char *argv[], t_settings *settings);

//	ALLOC MEMORY

int		alloc_memory(long long int philo_num);

//	ITEMS

int		wait(long long int pause);
int		get_current_time(struct timeval *start, long long int *current);

//	THREADS

int		start_threads(void);
int		quit_threads(void);

//	PHILOSOPHERS ROUTINE

int		eat(t_philo *philo);
int		someone_died(t_philo *philo, int lock);
void	*routine(void *ptr);

#endif
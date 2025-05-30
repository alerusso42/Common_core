/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_function_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:02:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/30 16:39:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FUNCTION_LIST_H
# define Z_FUNCTION_LIST_H
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

int		        switch_to_bonus(t_settings *settings);
void	        *storage(void *ptr, int mode);
void	        reset_memory();
int		        switches(t_settings *settings);
int		        variables(t_settings *settings);
int	            error(t_data *data, int error);

//	DEBUG

int		        time_delay_test(void);
int		        brute_wait(long long int micros);

//	PRINT

int		        p_color(int color, char *s);
int		        p_state(t_philo *philo, int state);

//	PARSING

int	            parsing(t_data *data, int argc, char *argv[]);

//	ALLOC MEMORY

int		        alloc_memory(t_data *data, long long int philo_num);

//	ITEMS

int		        ft_wait(long long int pause);
int		        get_current_time(struct timeval *start, long long int *current);
void	        *ft_calloc(size_t nmemb, size_t size);
long long int	ft_atoi(const char *nptr);
int		        fd_printf(int fd, const char *str, ...);
int			    l_printf(const char *str, ...);

//	THREADS

int		        start_threads(t_data *data);
int		        quit_threads(t_data *data);

//	PHILOSOPHERS ROUTINE

int		        eat(t_philo *philo);
int		        someone_else_died(t_philo *philo);
void	        *routine(void *ptr);

#endif
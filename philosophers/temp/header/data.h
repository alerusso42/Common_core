/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 09:36:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "header.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

/*
//	MESSAGES
*/
# define M_THINK "%d %d is thinking\n"
# define M_EAT "%d %d is eating\n"
# define M_SLEEP "%d %d is sleeping\n"
# define M_FORK "%d %d has taken a fork\n"
# define M_DEAD "%d %d died\n"

enum e_error
{
	ER_BAD_ARGC,
	ER_MALLOC,
	ER_NEGATIVE,
	ER_INVALID_ARG,
	ER_GETTIMEOFDAY,
	ER_USLEEP,
	ER_MUTEX_INIT,
	ER_PTHREAD_CREATE,
	ER_MUTEX_LOCK,
	TOTAL_ERROR,
};

enum e_time
{
	MS = 1000,
	MSECONDS = 1000,
	SECONDS = 1000000,
	MINUTES = 6000000,
};

enum e_philo_state
{
	THINK = 0,
	EAT = 1,
	SLEEP = 2,
	FORK = 3,
	DEAD = 4,
};

enum e_color
{
	RESET       = 0,
	BLACK       = 30,
	RED         = 31,
	GREEN       = 32,
	YELLOW      = 33,
	BLUE        = 34,
	MAGENTA     = 35,
	CYAN        = 36,
	WHITE       = 37,
	BOLD_BLACK  = 90,
	BOLD_RED    = 91,
	BOLD_GREEN  = 92,
	BOLD_YELLOW = 93,
	BOLD_BLUE   = 94,
	BOLD_MAGENTA= 95,
	BOLD_CYAN   = 96,
	BOLD_WHITE  = 97,
};

typedef struct s_data t_data;
typedef struct s_philo t_philo;

struct s_data
{
	struct timeval	time;
	t_philo			*philo;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	long long int	philo_num;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	write_mutex;
	int				meals_eaten;
	int				current;
	unsigned char	someone_died;
};

struct s_philo
{
	struct timeval	time;
	unsigned char	*someone_died;
	pthread_mutex_t	*philo_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_mutex;
	long long int	philo_num;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	current_time;
	long long int	last_meal_time;
	int				number_of_times_each_philosopher_must_eat;
	int				meals_eaten;
	int				id;
	unsigned char	state:3;
	unsigned char	last_philo:1;
	unsigned char	turn_to_eat:1;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/27 17:09:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_DATA_H
# define Z_DATA_H
# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif
# include <pthread.h>
# include <sys/time.h>

enum e_error
{
	CAZZI = 0,
	ER_BAD_ARGC = 1,
	ER_MALLOC = 2,
	ER_PARSING = 3,
	ER_ATOI = 4,
	ER_GETTIMEOFDAY = 5,
	ER_USLEEP = 6,
	ER_MUTEX_INIT = 7,
	ER_PTHREAD_CREATE = 8,
	ER_MUTEX_LOCK = 9,
};

enum e_time
{
	MSECONDS = 1000,
	SECONDS = 1000000,
	MINUTES = 6000000
};

enum e_philo_state
{
	THINK = 0,
	EAT = 1,
	SLEEP = 2,
	FORK = 3,
	DEAD = 4,
};

enum e_forks
{
	LEFT = 0,
	RIGHT = 1,
	BOTH = 2,
	NONE = 3,
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

enum e_lock
{
	LOCK = 1,
	DONTLOCK = 0,
};

typedef struct s_settings
{
	unsigned char	switch_1_bonus:1;
}				t_settings;

typedef struct s_data t_data;
typedef struct s_philo t_philo;

struct s_data
{
	struct timeval	time;
	t_settings		*settings;
	t_philo			*philo;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	long long int	philo_num;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	death_mutex;
	int				meals_eaten;
	int				current;
	unsigned char	someone_died;
};

struct s_philo
{
	struct timeval	time;
	unsigned char	*someone_died;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	current_time;
	long long int	last_meal_time;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*death_mutex;
	int				number_of_times_each_philosopher_must_eat;
	int				meals_eaten;
	int				id;
	int				left_fork;
	int				right_fork;
	unsigned char	state:3;
	unsigned char	turn_to_eat:1;
};

#endif
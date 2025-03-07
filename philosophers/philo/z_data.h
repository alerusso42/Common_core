/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:29:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_DATA_H
# define Z_DATA_H
# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

enum e_error
{
	ER_BAD_ARGC = 1,
	ER_MALLOC = 2,
	ER_PARSING = 3,
	ER_ATOI = 4,
};

enum e_philo_state
{
	THINK = 0,
	EAT = 1,
	SLEEP = 2,
	DEAD = 3
};

enum e_fork_state
{
	LOCK = 'L',
	UNLOCK = 'U',
};

typedef struct s_settings
{
	unsigned char	switch_1_bonus:1;
}				t_settings;

typedef struct s_data t_data;
typedef struct s_philo t_philo;

struct s_data
{
	t_settings		*settings;
	t_philo			*philo;
	unsigned char	*forks;
	long long int	philo_num;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	time;
	long long int	number_of_times_each_philosopher_must_eat;
	int				meals_eaten;
};

struct s_philo
{
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	time;
	int				number_of_times_each_philosopher_must_eat;
	int				meals_eaten;
	int				id;
	int				left_fork;
	int				right_fork;
	unsigned char	state:2;
};

#endif
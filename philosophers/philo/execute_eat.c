/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:41:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/30 16:24:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

//static void	block_fork(t_philo *philo, int which_fork);
//static void	unlock_forks(t_philo *philo, int which_fork);

/*
	0 = LEFT
	1 = RIGHT

	If even, take before RIGHT fork;
	If odd, take before LEFT fork.
*/

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_fork);
	p_state(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	get_current_time(&philo->time, &philo->last_meal_time);
	p_state(philo, EAT);
	ft_wait(philo->time_to_eat * MSECONDS);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->philo_fork);
	return (0);
}

/*
int	eat(t_philo *philo)
{
	if (block_fork(philo, philo->id % 2) != 0)
		return (ER_MUTEX_LOCK);
	if (block_fork(philo, !(philo->id % 2)) != 0)
		return (unlock_forks(philo, (philo->id % 2)), ER_MUTEX_LOCK);
	if (p_state(philo, EAT) != 0)
		return (unlock_forks(philo, BOTH), 1);
	if (unlock_forks(philo, (philo->id % 2)) != 0)
		return (ER_MUTEX_LOCK);
	if (unlock_forks(philo, !(philo->id % 2)) != 0)
		return (ER_MUTEX_LOCK);
	return (0);
}*/
/*
static void	block_fork(t_philo *philo, int which_fork)
{
	pthread_mutex_t	*mutex;

	if (which_fork == LEFT || which_fork == BOTH)
	{
		mutex = philo->philo_fork;
	}
	else
	{
		mutex = philo->right_fork;
	}
	pthread_mutex_lock(mutex);
	if (which_fork == BOTH)
	{
		block_fork(philo, RIGHT);
	}
}

static void	unlock_forks(t_philo *philo, int which_fork)
{
	pthread_mutex_t	*mutex;

	if (which_fork == LEFT || which_fork == BOTH)
	{
		mutex = philo->philo_fork;
	}
	else
	{
		mutex = philo->right_fork;
	}
	pthread_mutex_unlock(mutex);
	if (which_fork == BOTH)
	{
		unlock_forks(philo, RIGHT);
	}
}*/
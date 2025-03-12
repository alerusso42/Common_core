/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:41:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/12 16:32:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static int	block_fork(t_philo *philo, int which_fork);
static int	unlock_forks(t_philo *philo, int which_fork);

/*
	0 = LEFT
	1 = RIGHT

	If even, take before RIGHT fork;
	If odd, take before LEFT fork.
*/
int	eat(t_philo *philo)
{
	if (block_fork(philo, (philo->id % 2 == 0)) != 0)
		return (ER_MUTEX_LOCK);
	if (block_fork(philo, !(philo->id % 2 == 0)) != 0)
		return (unlock_forks(philo, (philo->id % 2 == 0)), ER_MUTEX_LOCK);
	if (p_state(philo, EAT) != 0)
		return (unlock_forks(philo, BOTH), 1);
	if (unlock_forks(philo, BOTH) != 0)
		return (ER_MUTEX_LOCK);
	return (0);
}

static int	block_fork(t_philo *philo, int which_fork)
{
	pthread_mutex_t	*mutex;

	if (which_fork == LEFT || which_fork == BOTH)
	{
		mutex = philo->forks[philo->left_fork];
	}
	else
	{
		mutex = philo->forks[philo->right_fork];
	}
	if (pthread_mutex_lock(mutex) != 0)
		return (ER_MUTEX_LOCK);
	if (which_fork == BOTH)
	{
		return (block_fork(philo, RIGHT));
	}
	return (0);
}

static int	unlock_forks(t_philo *philo, int which_fork)
{
	pthread_mutex_t	*mutex;

	if (which_fork == LEFT || which_fork == BOTH)
	{
		mutex = philo->forks[philo->left_fork];
	}
	else
	{
		mutex = philo->forks[philo->right_fork];
	}
	if (pthread_mutex_unlock(mutex) != 0)
		return (ER_MUTEX_LOCK);
	if (which_fork == BOTH)
	{
		return (unlock_forks(philo, RIGHT));
	}
	return (0);
}
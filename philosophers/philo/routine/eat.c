/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:41:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 12:39:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

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
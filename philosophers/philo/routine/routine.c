/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/09 12:01:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	*routine_loop(t_philo *philo, int meals, int max);
void		*lonely_philo(t_philo *philo);

void	*routine(void *ptr)
{
	t_philo	*philo;
	int		meals;
	int		max;

	philo = (t_philo *)ptr;
	if (philo->number_of_times_each_philosopher_must_eat == 0)
		return (NULL);
	if (philo->philo_num == 1)
		return (lonely_philo(philo));
	meals = 0;
	max = philo->number_of_times_each_philosopher_must_eat;
	return (routine_loop(philo, meals, max));
}

void	*lonely_philo(t_philo *philo)
{
	p_state(philo, FORK);
	ft_wait(philo->time_to_die * MSECONDS);
	return (NULL);
}

static void	*routine_loop(t_philo *philo, int meals, int max)
{
	while (meals != max && philo_lives(philo))
	{
		if (philo->turn_to_eat % 2)
		{
			eat(philo);
			++meals;
			p_state(philo, SLEEP);
			ft_wait(philo->time_to_sleep * MSECONDS);
			ft_wait(100);
			p_state(philo, THINK);
		}
		else
		{
			ft_wait(100);
		}
		philo->turn_to_eat++;
	}
	return (NULL);
}

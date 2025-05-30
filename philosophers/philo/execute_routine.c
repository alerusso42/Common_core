/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/30 11:52:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static void	*routine_loop(t_philo *philo, int meals, int max);

void	*lonely_philo(t_philo *philo)
{
	p_state(philo, FORK);
	ft_wait(philo->time_to_die * MSECONDS);
	p_state(philo, DEAD);
	return (NULL);
}

void	*routine(void *ptr)
{
	t_philo	*philo;
	int		meals;
	int		max;

	philo = (t_philo *)ptr;
	if (philo->philo_num == 1)
		return (lonely_philo(philo));
	meals = 0;
	max = philo->number_of_times_each_philosopher_must_eat;
	return (routine_loop(philo, meals, max));
}

static void	*routine_loop(t_philo *philo, int meals, int max)
{
	while (meals != max && philo->state != DEAD)
	{
		if (philo->turn_to_eat == philo->id % 2)
		{
			eat(philo);
			get_current_time(&philo->time, &philo->last_meal_time);
			ft_wait(philo->time_to_eat * MSECONDS);
			++meals;
			p_state(philo, SLEEP);
			ft_wait(philo->time_to_sleep * MSECONDS);
		}
		else
		{
			p_state(philo, THINK);
			ft_wait(100);
		}
		philo->turn_to_eat++;
	}
	return (NULL);
}
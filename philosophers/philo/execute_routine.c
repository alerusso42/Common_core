/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/14 16:34:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static void	*routine_loop(t_philo *philo, int meals, int max);

void	*routine(void *ptr)
{
	t_philo	*philo;
	int		meals;
	int		max;

	philo = (t_philo *)ptr;
	meals = 0;
	max = philo->number_of_times_each_philosopher_must_eat;
	if (get_current_time(&philo->time, &philo->last_meal_time) != 0)
		return (NULL);
	return (routine_loop(philo, meals, max));
	
}

static void	*routine_loop(t_philo *philo, int meals, int max)
{
	while (meals != max && philo->state != DEAD)
	{
		if (philo->turn_to_eat == philo->id % 2)
		{
			eat(philo);
			if (get_current_time(&philo->time, &philo->last_meal_time) != 0)
				return (NULL);
			wait(philo->time_to_eat * MSECONDS);
			++meals;
			p_state(philo, SLEEP);
			wait(philo->time_to_sleep * MSECONDS);
		}
		else
		{
			p_state(philo, THINK);
		}
		philo->turn_to_eat++;
		wait(10);
	}                                                                                 
	return (NULL);
}
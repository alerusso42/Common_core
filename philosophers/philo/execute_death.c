/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:54:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/29 15:08:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	someone_else_died(t_philo *philo)
{
	if (philo->state == DEAD)
		return (NO);
	pthread_mutex_lock(philo->death_mutex);
	get_current_time(&philo->time, &philo->current_time);
	if (*philo->someone_died == YES)
	{
		philo->state = DEAD;
		return (pthread_mutex_unlock(philo->death_mutex), YES);
	}
	if (philo->current_time - philo->last_meal_time > philo->time_to_die * MSECONDS)
	{
		*philo->someone_died = YES;
		philo->state = DEAD;
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (NO);
}

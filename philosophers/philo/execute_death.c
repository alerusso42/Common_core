/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:54:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/27 17:11:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	someone_died(t_philo *philo)
{
	if (philo->state == DEAD)
		return (YES);
	if (get_current_time(&philo->time, &philo->current_time) != 0)
		return (ER_GETTIMEOFDAY);
	if (pthread_mutex_lock(philo->write_mutex) != 0)
		return (ER_MUTEX_LOCK);
	if (philo->current_time - philo->last_meal_time > philo->time_to_die * MSECONDS)
	{
		philo->state = DEAD;
		*philo->someone_died = YES;
	}
	if (pthread_mutex_unlock(philo->write_mutex) != 0)
		return (ER_MUTEX_LOCK);
	if (philo->state == DEAD)
		return (YES);
	return (NO);
}
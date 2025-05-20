/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:54:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/20 16:08:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	someone_died(t_philo *philo, int lock)
{
	int	state;

	if (philo->state == DEAD)
		return (YES);
	if (lock && pthread_mutex_lock(philo->write_mutex) != 0)
		return (ER_MUTEX_LOCK);
	state = philo->state;
	if (lock && pthread_mutex_unlock(philo->write_mutex) != 0)
		return (ER_MUTEX_LOCK);
	if (state == DEAD)
		return (YES);
	return (NO);
}
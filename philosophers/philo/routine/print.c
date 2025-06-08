/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:20:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/08 12:29:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

/*
	Someone_else_died checks if the current philo is died too.
	If it is, updates philo->state
*/
int	p_state(t_philo *philo, int state)
{
	if (philo->state == DEAD)
		return (DEAD);
	pthread_mutex_lock(philo->write_mutex);
	get_current_time(&philo->time, &philo->current_time);
	if (someone_died(philo) == true)
	{
		return (pthread_mutex_unlock(philo->write_mutex));
	}
	get_current_time(&philo->time, &philo->current_time);
	if (state == THINK)
		l_printf(M_THINK, philo->current_time / MS, philo->id);
	else if (state == EAT)
		l_printf(M_EAT, philo->current_time / MS, philo->id);
	else if (state == SLEEP)
		l_printf(M_SLEEP, philo->current_time / MS, philo->id);
	else if (state == FORK)
		l_printf(M_FORK, philo->current_time / MS, philo->id);
	pthread_mutex_unlock(philo->write_mutex);
	return (0);
}

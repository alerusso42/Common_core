/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:54:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/08 12:52:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	philo_lives(t_philo *philo)
{
	int	is_alive;

	is_alive = true;
	pthread_mutex_lock(philo->generic_mutex);
	if (philo->state == DEAD)
		is_alive = false;
	pthread_mutex_unlock(philo->generic_mutex);
	return (is_alive);
}

int	someone_died(t_philo *philo)
{
	if (philo->state == DEAD)
		return (true);
	if (*philo->someone_died == true)
	{
		philo->state = DEAD;
		return (true);
	}
	return (false);
}

void	kill_everyone(t_data *data, int which, bool *everyone_lives)
{
	int	i;

	pthread_mutex_lock(&data->write_mutex);
	i = 0;
	while (i != data->philo_num)
	{
		data->philo[i].state = DEAD;
		++i;
	}
	data->someone_died = true;
	get_current_time(&data->time, &data->current_time);
	l_printf(M_DEAD, data->current_time / MS, which);
	pthread_mutex_unlock(&data->write_mutex);
	*everyone_lives = false;
}

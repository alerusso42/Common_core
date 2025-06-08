/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:54:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/08 16:57:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	philo_lives(t_philo *philo)
{
	int	is_alive;

	if (philo->death)
		return (false);
	is_alive = true;
	pthread_mutex_lock(philo->generic_mutex);
	if (philo->state == DEAD)
		is_alive = false;
	pthread_mutex_unlock(philo->generic_mutex);
	if (is_alive == false)
		philo->death = true;
	return (is_alive);
}

void	kill_everyone(t_data *data, int which, int *everyone_lives)
{
	int	i;

	i = 0;
	while (i != data->philo_num)
	{
		pthread_mutex_lock(&data->generic_mutex[i]);
		data->philo[i].state = DEAD;
		pthread_mutex_unlock(&data->generic_mutex[i]);
		++i;
	}
	data->someone_died = true;
	pthread_mutex_lock(&data->write_mutex);
	get_current_time(&data->time, &data->current_time);
	l_printf(M_DEAD, data->current_time / MS, which);
	pthread_mutex_unlock(&data->write_mutex);
	*everyone_lives = false;
}

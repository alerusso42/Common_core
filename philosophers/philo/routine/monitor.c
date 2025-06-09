/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:24:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/09 21:31:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	monitor_loop(t_data *data, int i, int everyone_lives);

void	*monitor(void *data_ptr)
{
	t_data	*data;
	int		everyone_lives;
	int		i;

	data = (t_data *)data_ptr;
	everyone_lives = true;
	i = 0;
	monitor_loop(data, i, everyone_lives);
	return (NULL);
}

static void	monitor_loop(t_data *data, int i, int everyone_lives)
{
	while (everyone_lives)
	{
		ft_wait(MONITOR_TIMER);
		i = 0;
		while (i != data->philo_num && everyone_lives)
		{
			pthread_mutex_lock(&data->generic_mutex[i]);
			get_current_time(&data->time, &data->current_time);
			if (data->current_time - data->philo[i].last_meal_time >= \
			data->philo[i].time_to_die * MSECONDS)
			{
				pthread_mutex_unlock(&data->generic_mutex[i]);
				kill_everyone(data, i, &everyone_lives);
			}
			else
				pthread_mutex_unlock(&data->generic_mutex[i]);
			++i;
		}
	}
}

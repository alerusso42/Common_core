/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:57:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/11 14:40:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (get_current_time(&philo->time, &philo->current_time) != 0)
		return (NULL);
	pthread_mutex_lock(philo->write_mutex);
	l_printf("\n%d %d:\tEccoci!\n", philo->current_time / MSECONDS, philo->id);
	pthread_mutex_unlock(philo->write_mutex);
	wait(1 * SECONDS);                                                                                                      
	return (NULL);
}

int	init_loop(t_data *data);

int	start_threads(void)
{
	int		i;
	t_data	*data;
	int		err;

	i = 0;
	err = 0;
	data = storage(NULL, 1);
	err = get_current_time(&data->time, NULL);
	if (err != 0)
		return (err);
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
		return (ER_MUTEX_INIT);
	i = 0;
	while (i != data->philo_num)
	{
		data->philo[i].write_mutex = &data->write_mutex;
		++i;
	}
	err = init_loop(data);
	if (err != 0)
		return (err);
	return (0);
}

int	init_loop(t_data *data)
{
	int	i;
	int	j;
	int	err;
	
	i = 0;
	while (i != data->philo_num)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ER_MUTEX_INIT);
		j = -1;
		while (++j != data->philo_num)
			data->philo[j].forks[i] = &data->forks[i];
		data->philo[i].time = data->time;
		if (pthread_create(&data->threads[i], NULL, routine, \
			(void *)&data->philo[i]) != 0)
			return (ER_PTHREAD_CREATE);
		err = wait(3 * MSECONDS);
		if (err != 0)
			return (err);
		(void)err;
		++i;
	}
	return (0);
}

int	quit_threads(void)
{
	int		i;
	t_data	*data;

	i = 0;
	data = storage(NULL, 1);
	while (i != data->philo_num)
	{
		pthread_join(data->threads[i], NULL);
		pthread_mutex_destroy(&data->forks[i]);
		++i;
	}
	pthread_mutex_destroy(&data->write_mutex);
	return (0);
}
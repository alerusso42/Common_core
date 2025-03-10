/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:57:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/10 17:24:11 by alerusso         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->write_mutex);
	l_printf("\nPhilo nbr %d:\tCi sono!\n", philo->id);
	pthread_mutex_unlock(&philo->write_mutex);
	wait(1 * SECONDS);
	return (NULL);
}

int	init_loop(t_data *data);

int	start_threads(void)
{
	int		i;
	t_data	*data;

	i = 0;
	data = storage(NULL, 1);
	pthread_mutex_init(&data->write_mutex, NULL);
	init_loop(data);
	while (i != data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		int	j = -1;
		while (++j != data->philo_num)
			data->philo[j].forks[i] = data->forks[i];
		pthread_create(&data->threads[i], NULL, routine, (void *)&data->philo[i]);
		wait(3);
		++i;
	}
	i = 0;
	while (i != data->philo_num)
	{
		pthread_join(data->threads[i], NULL);
		pthread_mutex_destroy(&data->forks[i]);
		++i;
	}
	pthread_mutex_destroy(&data->write_mutex);
	return (0);
}

int	init_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i != data->philo_num)
	{
		data->philo[i].write_mutex = data->write_mutex;
		++i;
	}
	return (0);
}
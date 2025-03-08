/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:57:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/08 18:59:39 by alerusso         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->mutex);
	l_printf("\nPhilo nbr %d:\tCi sono!\n", philo->id);
	pthread_mutex_unlock(&philo->mutex);
	wait(1 * SECONDS);
	return (NULL);
}

int	start_threads(void)
{
	int		i;
	t_data	*data;

	i = 0;
	data = storage(NULL, 1);
	while (i != data->philo_num)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		data->philo[i].mutex = data->mutex[i];
		pthread_create(&data->threads[i], NULL, routine, (void *)&data->philo[i]);
		wait(3);
		++i;
	}
	i = 0;
	while (i != data->philo_num)
	{
		pthread_join(data->threads[i], NULL);
		pthread_mutex_destroy(&data->mutex[i]);
		++i;
	}
	return (0);
}
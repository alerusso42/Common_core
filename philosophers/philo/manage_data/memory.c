/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:18:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 11:52:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	alloc_memory(t_data *data, long long int philo_num)
{
	int	num;
	int	i;

	num = (int)philo_num;
	data->philo = (t_philo *)ft_calloc(num + 1, sizeof(t_philo));
	if (!data->philo)
		return (ER_MALLOC);
	i = -1;
	while (++i != num)
		data->philo[i] = (t_philo){0};
	num += 1;
	data->forks = (pthread_mutex_t *)ft_calloc(num, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (ER_MALLOC);
	data->threads = (pthread_t *) \
	ft_calloc(num, sizeof(pthread_t));
	if (!data->threads)
		return (ER_MALLOC);
	return (0);
}

/*
static int	alloc_fork_copy(t_data *data, int num)
{
	int	i;

	i = 0;
	while (i != num)
	{
		data->philo[i].forks = (pthread_mutex_t **)\
		ft_calloc(num + 1, sizeof(pthread_mutex_t *));
		if (!data->philo[i].forks)
			return (ER_MALLOC);
		++i;
	}
	return (0);
}
*/	

void	reset_memory(t_data	*data)
{
	if (!data)
		return ;
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
	if (data->threads)
	{
		free(data->threads);
		data->threads = NULL;
	}
}

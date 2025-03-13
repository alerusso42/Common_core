/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:57:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/13 22:21:16 by alerusso         ###   ########.fr       */
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
	int		meals = 0;
	int		max;

	philo = (t_philo *)ptr;
	max = philo->number_of_times_each_philosopher_must_eat;
	if (get_current_time(&philo->time, &philo->last_meal_time) != 0)
		return (NULL);
	while (meals != max && someone_died(philo, LOCK) == NO)
	{
		if (philo->turn_to_eat == philo->id % 2)
		{
			eat(philo);
			if (get_current_time(&philo->time, &philo->last_meal_time) != 0)
				return (NULL);
			wait(philo->time_to_eat * MSECONDS);
			++meals;
			p_state(philo, SLEEP);
			wait(philo->time_to_sleep * MSECONDS);
		}
		else
			p_state(philo, THINK);
		philo->turn_to_eat++;
	}                                                                                 
	return (NULL);
}

int	init_loop(t_data *data);
int	init_mutex(t_data *data);

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
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (ER_MUTEX_INIT);
	i = 0;
	while (i != data->philo_num)
	{
		data->philo[i].write_mutex = &data->write_mutex;
		data->philo[i].death_mutex = &data->death_mutex;
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
	int	err;

	if (init_mutex(data) != 0)
		return (ER_MUTEX_INIT);
	i = 0;
	while (i != data->philo_num)
	{
		data->philo[i].time = data->time;
		if (pthread_create(&data->threads[i], NULL, routine, \
			(void *)&data->philo[i]) != 0)
			return (ER_PTHREAD_CREATE);
		err = wait(3 * MSECONDS);
		if (err != 0)
			return (err);
		++i;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->philo_num)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ER_MUTEX_INIT);
		j = -1;
		while (++j != data->philo_num)
			data->philo[j].forks[i] = &data->forks[i];
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
		++i;
	}
	wait(10 * MSECONDS);
	p_color(GREEN, "TUTTI FORI\n");
	i = 0;
	while (i != data->philo_num)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
		{
			p_color(RED, "\nWARNING! Trying to destroy a lock mutex!\n");
			fd_printf(3, "@@@\tWARNING\t@@@");
		}
		++i;
	}
	pthread_mutex_destroy(&data->write_mutex);
	return (0);
}
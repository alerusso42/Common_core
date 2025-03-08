/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/08 18:24:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static void	reset_memory2(t_data *data);

void	reset_memory()
{
	t_data	*data;

	data = storage(NULL, 1);
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
	reset_memory2(data);
	free(data);
	data = NULL;
	storage(NULL, 0);
}

static void	reset_memory2(t_data *data)
{
	if (data->mutex)
	{
		free(data->mutex);
		data->mutex = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/10 14:34:04 by alerusso         ###   ########.fr       */
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
	reset_memory2(data);
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
	free(data);
	data = NULL;
	storage(NULL, 0);
}

static void	reset_memory2(t_data *data)
{
	int	i;

	i = 0;
	while (data->philo[i].forks)
	{
		free(data->philo[i].forks);
		data->philo[i].forks = NULL;
		++i;
	}
}

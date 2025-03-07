/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:18:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:02:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	alloc_memory(long long int philo_num)
{
	t_data			*data;
	int				num;

	num = (int)philo_num;
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ER_MALLOC);
	storage((void *)data, 0);
	data->philo = (t_philo *)ft_calloc(num + 1, sizeof(t_philo));
	if (!data->philo)
		return (ER_MALLOC);
	data->philo[num] = (t_philo){0};
	data->forks = (unsigned char *)ft_calloc(num + 1, sizeof(t_philo));
	if (!data->forks)
		return (ER_MALLOC);
	return (0);
}

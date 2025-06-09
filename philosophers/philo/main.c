/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/09 22:41:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

/*
	ISSUES: every philo needs a global mutex (to write)
			and a mutex for every fork.
			Change the data struct, the allocation and
			remove the forks string.
*/
int	main(int argc, char *argv[])
{
	int			err_type;
	t_data		data;

	data = (t_data){0};
	err_type = parsing(&data, argc, argv);
	if (err_type != 0)
		return (error(&data, err_type));
	printf("DEBUG: died=%lld ms, eat=%lld ms, sleep=%lld ms\n",data.time_to_die, data.time_to_eat, data.time_to_sleep);
	err_type = start_threads(&data);
	if (err_type != 0)
		return (error(&data, err_type));
	err_type = quit_threads(&data);
	if (err_type != 0)
		return (error(&data, err_type));
	reset_memory(&data);
	return (0);
}

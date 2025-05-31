/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 09:30:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header/header.h"

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
	err_type = start_threads(&data);
	if (err_type != 0)
		return (error(&data, err_type));
	err_type = quit_threads(&data);
	if (err_type != 0)
		return (error(&data, err_type));
	reset_memory(&data);
	return (0);
}

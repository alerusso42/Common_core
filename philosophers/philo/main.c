/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/30 11:20:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

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

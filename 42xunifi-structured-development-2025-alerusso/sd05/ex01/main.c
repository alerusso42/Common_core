/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:46:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/18 19:27:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (parsing(&data, argc, argv) != 0)
		return (data.last_error);
	if (read_file(&data) != 0)
		return (data.last_error);
	if (alloc_memory(&data) != 0)
		return (data.last_error);
	do_something(&data);
	free_memory(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:17:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/03 15:47:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	get_main_struct_data(t_exec *exec, void *data, int debug)
{
	t_debug_data	*debug_data;
	t_debug_data	*dati_da_france;

	exec->main_struct_pointer = data;
	exec->debug = debug;
	if (debug)
	{
		debug_data = (t_debug_data *)data;
		exec->env = &debug_data->env;
		exec->env_size = &debug_data->env_size;
		exec->last_env = &debug_data->last_env;
	}
	(void)dati_da_france;
}

void	close_and_reset(int *fd)
{
	if (*fd >= 3)
		close(*fd);
	*fd = 0;
}
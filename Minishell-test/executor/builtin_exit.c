/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:46:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/05 15:21:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

//NOTE - Linea 26 SI LIBERA MEMORIA DI FRANCI
int	ft_exit(char **args, t_exec *exec)
{
	int	exit_status;

	(void)args;
	exit_status = exec->exit_status;
	storage(exec, STORE);
	if (exec->debug)
		free_debug_data((t_debug_data *)exec->main_struct_pointer);
	else
		(void)args;
	exec->main_struct_pointer = NULL;
	free_memory();
	return (exit(exit_status), 0);
}

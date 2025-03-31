/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:46:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/31 16:39:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_exit(char **args, t_exec *exec)
{
	if (exec->debug)
		free_debug_data((t_debug_data *)exec->main_struct_pointer);
	//Qui si libera memoria di france
	exec->main_struct_pointer = NULL;
	free_memory();
	return (exit(0), 0);
}

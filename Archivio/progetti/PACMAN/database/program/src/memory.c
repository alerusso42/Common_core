/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/04 16:17:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(t_data *data, int err_type)
{
	free_memory(data);
	exit(err_type);
}

void	free_memory(t_data *data)
{
	del_filedata();
	return ;
}

void	alloc_memory(t_data *data)
{
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:51:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/06 08:26:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

//
void	del_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

//////////////////////////////////////////////

//
t_typelist	*store_list(t_typelist *list, int mode)
{
	static t_typelist	*store_list;
	
	if (mode == 0)
	{
		store_list = list;
		return (NULL);
	}
	return (store_list);
}
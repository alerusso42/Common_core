/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:51:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/06 16:14:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

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
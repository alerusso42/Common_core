/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:20:56 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/06 00:52:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ft_malloc.h"

void	free(void *p)
{
	if (p)
		_free(p);
}

#include "../../all.h"

void	_free(void *p)
{
	void	*real_ptr;
	int		size;

	real_ptr = p - sizeof(t_info);
	size = ((t_info *)real_ptr)->bytes;
	ft_printf("$Yfreeing memory$Z %p, $Ysize $Z%d... ", real_ptr, size);
	if (munmap(real_ptr, size))
	{
		err_printf("$RFailure.$Z\n");
		perror("Munmap");
	}
	else
		VALGRIND_FREELIKE_BLOCK(real_ptr, 0);
	ft_printf("$Ydone.$Z\n");
}

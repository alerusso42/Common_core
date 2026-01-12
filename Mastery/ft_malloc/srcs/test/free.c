/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:20:56 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/11 22:16:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "test.h"

void	free(void *p)
{
	if (p)
		_free(p);
}

#include "../../all.h"

void	_free(void *p)
{
	void	*real_ptr;
	size_t	size;

	real_ptr = p - sizeof(t_info);
	size = ((t_info *)real_ptr)->bytes;
	ft_printf("$Yfreeing memory$Z %p, $Ysize $Z%d... ", real_ptr, size);
	if (munmap(real_ptr, size))
	{
		ft_printf("$RFailure: cannot free$Z\n");
		perror("Munmap");
	}
	else
	{
		VALGRIND_FREELIKE_BLOCK(real_ptr, 0);
		_global_data(false)->bytes_freed += size;
	}
	ft_printf("$Ydone.$Z\n");
}

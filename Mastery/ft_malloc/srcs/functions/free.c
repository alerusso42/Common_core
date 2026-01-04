/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:20:56 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/04 10:51:04 by alerusso         ###   ########.fr       */
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
	ft_printf(1, "freeing memory %d... ", (long long)p);
	if (munmap(p, 4096))
		perror("Munmap");
	else
		VALGRIND_FREELIKE_BLOCK(p, 0);
	ft_printf(1, "done.\n");
}

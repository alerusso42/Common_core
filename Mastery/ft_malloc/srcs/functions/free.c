/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:20:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/29 19:58:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ft_malloc.h"

void	free(void *p)
{
	_free(p);
}

void	_free(void *p)
{
	if (munmap(p, 1))
		perror("Munmap error: ");
	else
		VALGRIND_FREELIKE_BLOCK(p, 0);
}
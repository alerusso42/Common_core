/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_del_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:20:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

static void	del_one(void **ptr);

/*
	mode 0: freea e rende NULL un puntatore.
	mode 1: salva un puntatore (massimo 5).
	mode 2: libera tutti i puntatori salvati.
*/
void	*del_pointer(void **ptr, int mode)
{
	static void	*save_1 = NULL;
	static void	*save_2 = NULL;
	static void	*save_3 = NULL;
	static void	*save_4 = NULL;
	static int	count_saves = 0;

	if (mode == 0)
		return (del_one(ptr), NULL);
	if (mode == 1)
	{
		if (count_saves == 0)
			save_1 = *ptr;
		else if (count_saves == 1)
			save_2 = *ptr;
		else if (count_saves == 2)
			save_3 = *ptr;
		else if (count_saves == 3)
			save_4 = *ptr;
		++count_saves;
		return (NULL);
	}
	del_pointer(&save_1, 0);
	del_pointer(&save_2, 0);
	count_saves = 0;
	return (del_pointer(&save_3, 0), del_pointer(&save_4, 0));
}

static void	del_one(void **ptr)
{
	if (!ptr)
		return ;
	FREE(*ptr);
	*ptr = NULL;
}

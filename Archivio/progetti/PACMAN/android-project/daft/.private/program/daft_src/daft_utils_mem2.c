/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_mem2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:38:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/17 23:36:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//REVIEW - 	Takes the ptr of a 3D matrix.
//			Reallocs it, increasing its size.
//			If old size (*size) is == 0, *size becomes 2;
//			Else, *size is doubled.
int	_daft_resize_three_d_matr(char ****old_matr, int *size)
{
	char	***new_matr;
	int		i;

	if (!old_matr || !*old_matr || !size)
		return (DAFT_LOG_MALLOC);
	if (!*size)
		*size = 2;
	else
		*size = *size * 2;
	new_matr = ft_calloc(*size + 1, sizeof(char **));
	if (!new_matr)
		return (SDL_free(*old_matr), DAFT_LOG_MALLOC);
	i = 0;
	while ((*old_matr)[i])
	{
		new_matr[i] = (*old_matr)[i];
		++i;
	}
	SDL_free(*old_matr);
	*old_matr = new_matr;
	return (0);
}

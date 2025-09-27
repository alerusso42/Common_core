/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_free_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:14:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

/*
	Always return NULL
*/
void	*free_matrix(char **matrix)
{
	int	index;

	index = 0;
	if (!matrix)
		return (NULL);
	while (matrix[index])
	{
		if (matrix[index])
			FREE(matrix[index]);
		matrix[index] = NULL;
		++index;
	}
	if (matrix)
		FREE(matrix);
	return (NULL);
}

/*
	Always return NULL
*/
void	*free_three_d_matrix(char ***matrix)
{
	int	index_one;
	int	index_two;

	index_one = 0;
	if (!matrix)
		return (NULL);
	while (matrix[index_one])
	{
		index_two = 0;
		while (matrix[index_one][index_two])
		{
			FREE(matrix[index_one][index_two]);
			matrix[index_one][index_two] = NULL;
			++index_two;
		}
		FREE(matrix[index_one]);
		matrix[index_one] = NULL;
		++index_one;
	}
	FREE(matrix);
	return (NULL);
}

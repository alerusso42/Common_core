/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 23:20:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*REVIEW - _free_matrix

//	Safely free a 2D matrix, even if NULL.
	Always return NULL.
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
			free(matrix[index]);
		matrix[index] = NULL;
		++index;
	}
	if (matrix)
		free(matrix);
	return (NULL);
}

/*REVIEW - _free_three_d_matrix

//	Safely free a 3D matrix, even if NULL.
	Always return NULL.
*/
void	*_free_three_d_matrix(char ***matrix)
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
			free(matrix[index_one][index_two]);
			matrix[index_one][index_two] = NULL;
			++index_two;
		}
		free(matrix[index_one]);
		matrix[index_one] = NULL;
		++index_one;
	}
	free(matrix);
	return (NULL);
}

void	print_matrix(t_data *data, char **matrix, char *filename)
{
	int		fd;
	int		i;

	if (!matrix || !filename)
		return ;
	fd = open(filename, P_CREATE, 0777);
	if (fd < 0)
		error(data, ER_OPEN);
	i = 0;
	while (matrix[i])
	{
		fd_printf(fd, "%s", matrix[i]);
		++i;
	}
	close(fd);
}

/*
//REVIEW - sort_matrix

	A bubble sort algorithm to sort a matrix of strings in 
	ASCII ascending order.
*/
void	sort_matrix(char **matrix)
{
	char	*temp;
	int		i;
	int		j;

	if (!matrix || !matrix[0])
		return ;
	i = 0;
	while (matrix[i + 1])
	{
		j = 0;
		while (matrix[j + 1])
		{
			if (sub_strcmp(matrix[j], matrix[j + 1], SEPARATOR_S) > 0)
			{
				temp = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp;
			}
			++j;
		}
		++i;
	}
}

//REVIEW - 	Takes the ptr of a 2D matrix.
//			Reallocs it, increasing its size.
//			If old size (*size) is == 0, *size becomes 2;
//			Else, *size is doubled.
int	resize_matr(char ***old_matr, int *size)
{
	char	**new_matr;
	int		i;

	if (!old_matr || !size)
		return (1);
	if (!*size)
		*size = 2;
	else
		*size = *size * 2;
	new_matr = ft_calloc(*size + 2, sizeof(char *));
	if (!new_matr)
		return (free(*old_matr), 1);
	i = 0;
	while ((*old_matr) && (*old_matr)[i])
	{
		new_matr[i] = (*old_matr)[i];
		++i;
	}
	free(*old_matr);
	*old_matr = new_matr;
	return (0);
}

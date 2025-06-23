/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:10:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 02:20:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	cmp(char **matrix, char type, int i);
static int	num_cmp(char *s1, char *s2);

void	sort(char **matrix, char type)
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
			if (cmp(matrix, type, j) > 0)
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

/*
//REVIEW - cmp

	Embed of various cmp functions.
*/
static int	cmp(char **matrix, char type, int i)
{
	if (type == 's')
		return (sub_strcmp(matrix[i], matrix[i + 1], SEPARATOR_S));
	else if (type == 'd' || type == 'i')
		return (num_cmp(matrix[i], matrix[i + 1]));
	return (0);
}

static int	num_cmp(char *s1, char *s2)
{
	int	n1;
	int	n2;

	if (!s1 || !s2)
		return (0);
	n1 = ft_atoi(s1);
	n2 = ft_atoi(s2);
	return (n1 - n2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:43:54 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/21 09:18:14 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		map[i] = NULL;
		i++;
	}
	free (map);
}

void	find_p(char **map, int *x, int *y)
{
	while (map[*y])
	{
		while (map[*y][*x] != '\n')
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
}

void	floodfill(char **map, int x, int y)
{
	if ((map[y][x] == '1') || map[y][x] == 'x')
		return ;
	map[y][x] = 'x';
	floodfill (map, (x + 1), y);
	floodfill (map, (x - 1), y);
	floodfill (map, x, (y + 1));
	floodfill (map, x, (y - 1));
}

// int	char_check(char **map)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (map[j])
// 	{
// 		i = 0;
// 		while (map[j][i])
// 		{
// 			if ((map[j][i] != '1') && (map[j][i] != '0') && \
// 			(map[j][i] != 'P') && (map[j][i] != 'C') && (map[j][i] != 'E')\
// 			&& (map[j][i] != '\n'))
// 				return (0);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (1);
// }
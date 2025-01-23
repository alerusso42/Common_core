/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:46:34 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/20 15:47:54 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_sqare(char **map, int lines)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[j][i] == '1')
		i++;
	if (map[j][i] != '\n')
		return (0);
	else
		j++;
	while ((map[j][0] == '1') && (map[j][i - 1] == '1') && (j != lines - 1) \
	&& (map[j][i] == '\n'))
		j++;
	if (j == lines - 1)
	{
		i = 0;
		while (map[j][i] == '1')
			i++;
		if (map[j][i] != '\0')
			return (0);
	}
	else
		return (0);
	return (1);
}

int	search(char **map, int n)
{
	int	j;
	int	i;
	int	nx;

	j = 0;
	i = 0;
	nx = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == n)
				nx++;
			if ((map[j][i] != '1') && (map[j][i] != '0') && \
			(map[j][i] != 'P') && (map[j][i] != 'C') && (map[j][i] != 'E')\
			&& (map[j][i] != '\n'))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (nx);
}

int	required(char **map, t_imma *imma)
{
	int	np;
	int	nc;
	int	ne;

	np = 80;
	nc = 67;
	ne = 69;
	np = search(map, np);
	nc = search(map, nc);
	imma->coll = nc;
	ne = search(map, ne);
	if ((np == 1) && (nc >= 1) && (ne == 1))
		return (1);
	return (0);
}

int	count_lines(void)
{
	char	buffer[2];
	int		n_new_lines;
	int		fd;

	fd = open("map.ber", O_RDONLY, 777);
	buffer[1] = 0;
	n_new_lines = 1;
	while (read (fd, buffer, 1) != 0)
		if (buffer[0] == '\n')
			n_new_lines++;
	close (fd);
	return (n_new_lines);
}

char	**get_map(t_imma *imma)
{
	char			**map;
	int				lines;
	int				fd;
	int				i;
	static int		check;

	(void)imma;
	i = -1;
	lines = count_lines();
	fd = open("map.ber", O_RDONLY, 777);
	map = malloc ((lines + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	if (fd == -1)
		return (free(map), NULL);
	while (i != lines)
		map[++i] = get_next_line (fd);
	close (fd);
	if ((check == 0) && ((is_sqare(map, lines) == 0)\
	|| (required(map, imma) == 0) || (path_finder(map) == 0)))
		return (ft_free (map), NULL);
	if (check++ == 0)
		return (ft_free (map), get_map(imma));
	return (map);
}

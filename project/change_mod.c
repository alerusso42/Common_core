/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 14:33:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int		change_mod(char *argv[], int argc);
int		check_extension_file(char *filename, char *extension);
static t_bool	parsing(int argc, char *argv[], int *seed);

int	change_mod(char *argv[], int argc)
{
	int		seed;
	char	*filename;	

	seed = 0;
	if (argc == 2)
	{
		if (check_file(argv[1], &filename) == 1)
			return (1);
		if (find_mapsize(filename) == 1)
			return (1);
		return (0);
	}
	if (argc < 4)
		return (error(ERROR_BAD_ARGC), 1);
	if (ft_strcmp(argv[1], "gen") == 0)
	{
		if (parsing(argc, argv, &seed) != 0)
			return (ERROR_BAD_ARGC);
	}
	return (0);
}

static t_bool	parsing(int argc, char *argv[], int *seed)
{
	int	game_size[2];
	
	if ((argc == 3) || (argc > 5))
		return (error(ERROR_BAD_ARGC), 1);
	game_size[0] = ft_atoi(argv[2]);
	game_size[1] = ft_atoi(argv[3]);
	if ((game_size[0] < 1) || (game_size[1] < 1))
		return (error(ERROR_BAD_ARGC), 1);
	if (argv[4] != NULL)
	{
		*seed = (ft_atoi(argv[4]));
		if (*seed < 0)
			*seed *= -1;
		else if (*seed == MIN_INT_VALUE)
			*seed = MAX_INT_VALUE;
		else if (*seed == 0)
			*seed = 1;
		*seed = (*seed % 100) + 1;
	}
	else
		*seed = 1;
	return (get_data(CREATE, game_size[0], game_size[1], NULL), 0);
}

t_bool	find_mapsize(char *filename)
{
	int		fd;
	int		size_y;
	int		size_x;
	int		old_size_x;
	char	*line;

	size_y = 0;
	line = NULL;
	fd = open(filename, O_RDONLY, 0666);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	old_size_x = ft_strlen_newline(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size_x = ft_strlen_newline(line);
		if ((size_x != 0) && (old_size_x != size_x))
			return (free(line), close(fd), 1);
		if (size_x != 0)
			old_size_x = size_x;
		++size_y;
	}
	return (get_data(READ, old_size_x, size_y, filename), close(fd), 0);
}

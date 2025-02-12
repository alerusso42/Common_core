/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 15:47:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

int				change_mod(char *argv[], int argc);
int				check_extension_file(char *filename, char *extension);
static t_bool	parsing(int argc, char *argv[], int *seed);

/*
	My so_long has two modes:
	1)	Gen x y: generate a new map, calling it map.ber and
		placing it on the maps folder;
	2)	namemap: you give a map, and you play.
		you can give the name of the map without specifing
		to search it on the maps folder.
		If you do, it finds it anyway.
	
	For every mode, we save the result of the parsing in get_data.
	get_data save the data as static variables, and it'll use
	them later on.
	-	Mode one (CREATE) has the parsing function to parse.
	-	Mode two (READ) has the check_file and find_mapsize
		functions to parse.
		check_file checks if there is a valid extension;
		find_mapsize checks if the map:
		1)	can be read and opened;
		2)	it's size values.
*/
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
			return (free(filename), 1);
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

/*
	parsing for CREATE mod.
*/
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

/*
	parsing for READ mode.
*/
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

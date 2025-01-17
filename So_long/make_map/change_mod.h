/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mod.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/17 12:21:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGE_MOD_H
# define CHANGE_MOD_H
# include "types.h"
# include "general_ft.h"
# include "error_message.h"
# include "get_map.h"
# include "get_next_line_bonus.h"

int		change_mod(char *argv[], int argc);
t_bool	alloc_data(int game_size[2], int seed, int create_or_read, char *fn);
int		check_extension_file(char *filename, char *extension);
t_bool	parsing(int argc, char *argv[], int game_size[2], int *seed);
t_bool	find_mapsize(char *filename, int game_size[2]);

int	change_mod(char *argv[], int argc)
{
	int	game_size[2];
	int	seed;

	game_size[0] = 0;
	game_size[1] = 0;
	seed = 0;
	if (argc == 2)
	{
		if (check_extension_file(argv[1], ".ber") == 1)
			return (1);
		if (find_mapsize(argv[1], game_size) == 1)
			return (1);
		ft_printf("File valido!\n");
		return (alloc_data(game_size, seed, READ, argv[1]));
	}
	if (argc < 4)
		return (error(ERROR_BAD_ARGC));
	if (ft_strcmp(argv[1], "gen") == 0)
	{
		if (parsing(argc, argv, game_size, &seed) != 0)
			return (ERROR_BAD_ARGC);
		if (alloc_data(game_size, seed, CREATE, NULL) == 1)
			return (1);
	}
	return (0);
}

t_bool	parsing(int argc, char *argv[], int game_size[2], int *seed)
{
	if ((argc == 3) || (argc > 5))
		return (error(ERROR_BAD_ARGC));
	game_size[0] = ft_atoi(argv[2]);
	game_size[1] = ft_atoi(argv[3]);
	if ((game_size[0] < 1) || (game_size[1] < 1) || \
	(game_size[0] == game_size[1]))
		return (error(ERROR_BAD_ARGC));
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
	return (0);
}

/*
	What are we doing here?
	1) Check the filename exists and the file can be open;
	2) Check that the file has the same extension as a .ber file.
	To do the second step:

	- We go to the end of the file name (to the null terminator);
	- We go back until we find the "." symbol (the start of extension);
	- We make a strcmp.
*/
int	check_extension_file(char *filename, char *extension)
{
	int	fd;
	int	file_index;
	int	ext_index;

	fd = open(filename, O_RDONLY, 0666);
	if (fd == -1)
		return (1);
	close(fd);
	file_index = 0;
	ext_index = 0;
	while (filename[file_index] != '\0')
		++file_index;
	while ((filename[file_index] != extension[ext_index]) && (file_index != 0))
		--file_index;
	while ((filename[file_index]) && (extension[ext_index]))
	{
		if (filename[file_index] != extension[ext_index])
			return (1);
		++file_index;
		++ext_index;
	}
	return (0);
}

t_bool	find_mapsize(char *filename, int game_size[2])
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
	old_size_x = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size_x = ft_strlen(line);
		if ((size_x != 0) && (old_size_x != size_x))
			return (free(line), close(fd), 1);
		if (size_x != 0)
			old_size_x = size_x;
		++size_y;
	}
	game_size[0] = old_size_x + 1;
	game_size[1] = size_y;
	return (close(fd), 0);
}



#endif
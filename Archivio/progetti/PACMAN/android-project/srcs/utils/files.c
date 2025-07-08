/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:15:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/03 12:29:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

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
	t_fd	fd;
	int		file_index;
	int		ext_index;

	fd = openfd(filename, "r");
	if (!fd.n)
		return (1);
	closefd(fd);
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

int	file_size(int size[2], t_fd fd)
{
	int		y;
	int		x;
	int		max_x;
	char	*line;

	max_x = 0;
	y = 0;
	line = gnl();
	while (line && *line && *line != '\n')
	{
		x = ft_strlen(line);
		if (x > max_x)
			max_x = x;
		SDL_free(line);
		line = gnl();
		++y;
	}
	SDL_free(line);
	reset_fd(fd);
	size[X] = max_x;
	size[Y] = y;
	return (0);
}

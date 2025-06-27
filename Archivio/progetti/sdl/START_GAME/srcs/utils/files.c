/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:15:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/27 15:17:35 by alerusso         ###   ########.fr       */
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
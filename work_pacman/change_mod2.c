/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mod2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 15:49:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

/*
	parsing for READ mode.
	-	before it searches the file, and save it.
	-	If it fails, it tries to add the suffix maps/.
*/
int	check_file(char *argv, char **filename)
{
	if (check_extension_file(argv, ".ber") == 0)
	{
		*filename = ft_strdup(argv);
		if (!(*filename))
			return (l_printf("MALLOC FAILED IN check file!\n"), 1);
		return (0);
	}
	*filename = ft_strjoin("maps/", argv);
	if (!filename)
		return (l_printf("MALLOC FAILED IN check file!\n"), 1);
	if (check_extension_file(*filename, ".ber") == 1)
	{
		free(*filename);
		*filename = NULL;
		return (1);
	}
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
			return (l_printf("BAD EXTENSION FILE\n"), 1);
		++file_index;
		++ext_index;
	}
	return (0);
}

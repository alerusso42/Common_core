/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:33:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/16 16:35:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_FT2_H
# define GENERAL_FT2_H
# include <stdio.h>
# include <malloc.h>
# include "general_ft.h"
# include <unistd.h>
# include <fcntl.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	pointer = NULL;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_memset((void *)pointer, total_size);
	return (pointer);
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
	file_index = 0;
	ext_index = 0;
	while (filename[file_index] != '\0')
		++file_index;
	while ((filename[file_index] != extension[ext_index]) && (file_index != 0))
		--file_index;
	while ((filename[file_index]) && (extension[ext_index]))
	{
		if (filename[file_index] != extension[ext_index])
			return (close(fd), 1);
		++file_index;
		++ext_index;
	}
	return (close(fd), 0);
}

#endif
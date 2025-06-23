/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_get_next_line_original.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 12:19:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
int	main()
{
	char	*new_line;
	int		fd;
	int		max_fd;
	size_t	counter;
	size_t	initial_counter;

	//fd = 3;
	fd = open("updated_pokedex.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	//fd = 4;
	fd = open("tagliatelledinonnapinalyrics.txt", O_RDONLY);
	if (fd == -1)
	{
		fd = 3;
		while (fd != 2)
		{
			close(fd--);
		}
		return (1);
	}
	//fd = 5;
	fd = open("lore_di_bloodborne.txt", O_RDONLY);
	if (fd == -1)
	{
		fd = 4;
		while (fd != 2)
		{
			close(fd--);
		}
		return (1);
	}
	//fd = 6;
	fd = open("empty.txt", O_CREAT);
	if (fd == -1)
	{
		fd = 5;
		while (fd != 2)
		{
			close(fd--);
		}
		return (1);
	}
	max_fd = fd;
	fd = 3;
	counter = COUNTER;
	if (FORCE_READ_ONE_TEXT)
		fd = FORCE_READ_ONE_TEXT;
	initial_counter = counter;
	while (fd < max_fd + 1)
	{
		while (counter--)
		{
			new_line = get_next_line(fd);
			printf("\nNEXT LINE(%zu): \\\\\"%s\"\\\\", \
			initial_counter - counter, new_line);
			if (!new_line)
				break ;
			if (new_line)
				free(new_line);
		}
		if (FORCE_READ_ONE_TEXT)
			break ;
		if (fd != max_fd)
		{
			printf("\n\n\n---------\n\\\\GO TO NEXT TEXT\\\\\n---------\n\n");
		}
		
		counter = initial_counter;
		++fd;
	}
	printf("\n\n\\\\END OF READING\\\\\n\n");
	while (fd != 3)
	{
		close(fd--);
	}
	return (0);
}
*/

char	*gnl(int fd)
{
	static char	buffer[1048][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	return (get_next_line_main_function(fd, buffer[fd]));
}

char	*gnl_original_main_function(int fd, char buffer[BUFFER_SIZE + 1])
{
	char	*new_line;
	int		check_newline;
	char	*store_readbytes;

	new_line = NULL;
	check_newline = 0;
	while (buffer[check_newline] && buffer[check_newline] != '\n')
		++check_newline;
	if ((buffer[check_newline] == EMPTY_BUFFER) && (check_newline == 0))
	{
		if (go_read(fd, buffer, &new_line) == END_OR_CORRUPTION)
			return (NULL);
	}
	else
	{
		new_line = get(&store_readbytes, buffer, check_newline, fd);
		if (!new_line)
			return (NULL);
	}
	return (new_line);
}

//	Temporanea: serve per fare Minishell con Francesco.
//	Eliminare in futuro.
char	*get_next_line_bonus(int fd)
{
	return (gnl(fd));
}

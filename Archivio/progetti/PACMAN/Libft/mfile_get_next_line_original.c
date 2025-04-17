/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_get_next_line_original.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 22:04:45 by alerusso         ###   ########.fr       */
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

char	*gnl(SDL_RWops *fd)
{
	static char			buffer[MAX_FILES + 1][BUFFER_SIZE + 1];
	static SDL_RWops	*fds[MAX_FILES + 1];
	int					i;

	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	i = 0;
	while (i != MAX_FILES)
	{
		if (!fds[i] || fd == fds[i])
		{
			fds[i] = fd;
			break ;
		}
		++i;
	}
	if (i == MAX_FILES)
		return (NULL);
	return (get_next_line_main_function(fd, buffer[i]));
}

char	*gnl_original_main_function(SDL_RWops *fd, char buffer[BUFFER_SIZE + 1])
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

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:48:33 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/07 10:15:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int	main()
{
	char	*new_line;
	int		fd;
	int		max_fd;
	size_t	counter;

	//fd = 3;
	fd = open("updated_pokedex.txt", O_RDONLY);
	if (fd == -1)
	{
		while (fd != 3)
		{
			close(fd--);
		}
		return (1);
	}
	//fd = 4;
	fd = open("tagliatelledinonnapinalyrics.txt", O_RDONLY);
	if (fd == -1)
	{
		while (fd != 3)
		{
			close(fd--);
		}
		return (1);
	}
	//fd = 5;
	fd = open("lore_di_bloodborne.txt", O_RDONLY);
	if (fd == -1)
	{
		while (fd != 3)
		{
			close(fd--);
		}
		return (1);
	}
	max_fd = fd;
	fd = 5;
	counter = 1000000;
	while (counter--)
	{
		new_line = get_next_line(fd);
		printf("%s", new_line);
		if (!new_line)
			break ;
		//printf("\n--COUNTER: %zu", counter);
		if (new_line)
			free(new_line);
		++fd;
		if (fd == max_fd + 1)
			fd = 3;
	}
	printf("\n");
	while (fd != 3)
	{
		close(fd--);
	}
	return (0);
}

char 	*get_next_line(int fd)
{
	static char	buffer[4000][BUFFER_SIZE + 3];
	
	return (get_next_line_main_function(fd, buffer[fd]));
}

char 	*get_next_line_main_function(int fd, char buffer[BUFFER_SIZE + 3])
{
	char	*new_line;
	int		check_newline;
	char	*store_readbytes;

	new_line = NULL;	
	check_newline = -1;
	while (buffer[++check_newline] && buffer[check_newline] != '\n');
	if ((buffer[check_newline] == EMPTY_BUFFER) && (check_newline == 0))
	{
		check_newline = 0;
		while (check_newline != BUFFER_SIZE)
			buffer[check_newline++] = 0;
		if (go_read(fd, buffer, &new_line) == END_OR_CORRUPTION)
			return (NULL);
	}
	else if (buffer[check_newline] == NO_NEWLINE_FOUND)
	{
		if (alloc_ft((void **)&store_readbytes, NULL, check_newline + 1, MALLOC) == FULL_MEMORY)
			return (NULL);
		ft_memcpy(store_readbytes, buffer, check_newline);
		if (go_read(fd, buffer, &new_line) == END_OR_CORRUPTION)
		{
			free(new_line);
			return (NULL);
		}
		new_line = ft_strjoin(store_readbytes, new_line);
		if (!new_line)
			return (NULL);
		//printf("\nPARTIAL_READ: \"%s\"\n", buffer);
		//printf("\n\n----NEXT LINE!----\n\n");
		//trim_readbytes(buffer);
	}
	else if (buffer[check_newline] != NO_NEWLINE_FOUND)
	{
		if (alloc_ft((void **)&new_line, NULL, check_newline + 1, MALLOC) == FULL_MEMORY)
			return (NULL);
		ft_memcpy(new_line, buffer, check_newline + 1);
		//printf("\nNOTHING_READ: \"%s\"\n", buffer);
		//printf("\n\n----NEXT LINE!----\n\n");
		trim_readbytes(buffer);
	}
	return (new_line);
}

int	go_read(int fd, char buffer[BUFFER_SIZE + 3], char **new_line)
{
	int		control_read;
	size_t	end;
	size_t	size;

	end = 0;
	size = BUFFER_SIZE;
	if (alloc_ft((void **)new_line, NULL, size, MALLOC) == FULL_MEMORY)
		return (alloc_ft((void **)new_line, NULL, 0, FREE));
	while ("I loop until I find the first occurence of \n or \0 after start:)")
	{
		control_read = read(fd, *new_line + end, BUFFER_SIZE);
		if ((control_read == -1) || ((control_read == 0) && (end == 0)))
			return (alloc_ft((void **)new_line, 0, 0, FREE));
		if (control_read == 0)
			break ;
		end += control_read;
		if (end >= size)
		{
			size *= 2;
			if (alloc_ft((void **)new_line, (void *)*new_line, size + 2, REALLOC) == FULL_MEMORY)
				return (alloc_ft((void **)new_line, 0, 0, FREE));
		}
		(*new_line)[end] = 0;
		control_read = end;
		if (find_end_line(&end, *new_line) == EOF_OR_NEWLINE_FOUND)
			break ;
	}
	ft_memcpy(buffer, *new_line + end + 1, control_read - end - 1);
	if (alloc_ft((void **)new_line, (void *)*new_line, end, REALLOC) == FULL_MEMORY)
		return (alloc_ft((void **)new_line, 0, 0, FREE));
	
	return (0);
}






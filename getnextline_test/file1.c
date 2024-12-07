/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:48:33 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/04 14:23:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int	main()
{
	char	*new_line;
	int		fd;
	size_t	counter;

	fd = open("updated_pokedex.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	counter = 30;
	while (counter--)
	{
		new_line = get_next_line(fd);
		printf("\n%s\n", new_line);
		free(new_line);
	}
	close(fd);
	return (0);
}

char *get_next_line(int fd)
{
	
}

char *get_line(unsigned char *line_content, size_t line_num)
{
	
}

int	find_end_line(size_t *start, size_t end, char *string, int bytes_read)
{
	int	save;
	int	index;
	
	save = 0;
	index = bytes_read;
	while (index > (int)end)
	{
		if ((string[index] == '\0') || (string[index] == '\n'))
			save = index;
		index -= 1;
	}
	if (index == (int)end - 1)
		return (EOF_OR_NEWLINE_NOT_FOUND);
	*start = (size_t)save;
	return (end);
}

int	ft_readfile(char **string, int fd, size_t *start, int *bytes_read)
{
	(*string) = (char *)alloc_system((*string), *start + CHUNK, 0, REALLOC);
	if (!(*string))
		return (1);
	*bytes_read = read(fd, (*string), CHUNK);
	if (*bytes_read == -1)
		return (ERROR_READING_FILE);
	if (*bytes_read == 0)
		return (END_OF_FILE);
	*start += *bytes_read;
	return (*bytes_read);
}

void	*alloc_system(void *content, size_t start, size_t end, short int mode)
{
	void	*new_content;
	size_t	nmemb;

	nmemb = (start + 1) - end;
	if (mode == MALLOC)
	{
		content = ft_calloc(CHUNK, sizeof(char));
		if (!content)
			return (NULL);
		return (content);
	}
	if (mode == REALLOC)
	{
		if (!content)
			return (NULL);
		new_content = ft_calloc(nmemb, sizeof(char));
		if (!new_content)
			return (NULL);
		ft_memcpy(new_content, content + end, nmemb * sizeof(char));
		free(content);
		return (new_content);
	}
	if ((mode == FREE) && (content))
		free(content);
	return (NULL);
}




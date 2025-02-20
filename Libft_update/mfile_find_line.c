/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_find_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:42:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 15:19:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

int	move_cursor(int line_num)
{
	char	*search;
	int		fd;
	char	*filename;

	get_filedata(&fd, &filename);
	if ((fd == -1) || (!filename) || (line_num < 1))
		return (-1);
	reset_fd(fd, filename);
	if (line_num == 1)
		return (0);
	search = get_n_line(fd, line_num - 1);
	if (!search)
		return (1);
	free(search);
	return (0);
}

/*
Flags list
Find = 0 ---> finds where a line is located in a file text (in a string format)
Get  = 1 ---> Finds and give back the content of a line
Move = 2 ---> Moves the cursor to the line

Example:
find_line(GET, "[BEHOLDER]", "max_hp = ")

In this way, find_line finds before the line "[BEHOLDER]", then "max_hp".
If it finds both, it return the line of the last content, else return NULL.
*/
int	find_line(int fd, int num_search, va_list list)
{
	char	*string;
	char	*search;
	int		counter;

	counter = 1;
	string = get_next_line(fd, 0);
	if (!string)
		return (-1);
	search = va_arg(list, char *);
	while ((search) && (string) && (num_search--))
	{
		while (ft_strnstr(string, search, ft_strlen(search)) == NULL)
		{
			free(string);
			string = get_next_line(fd, 0);
			if (!string)
				break ;
			++counter;
		}
		search = va_arg(list, char *);
	}
	if (!string)
		return (-1);
	free(string);
	return (counter);
}

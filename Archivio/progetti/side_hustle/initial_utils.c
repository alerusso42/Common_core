/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:01 by negambar          #+#    #+#             */
/*   Updated: 2024/12/14 17:29:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"

int	write_in_file(char *s, int fd, int j)
{
	int i = 0;

	if (!fd)
		return 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (j == 1)
		write(fd, "\n", 1);
	return 1;
}

char	*get_that_line(int fd, char *s, char *s1)
{
	reset_fd(fd, "player_info.txt");
	char *lultimasponda = NULL;
	char *temp_ptr;
	
	if (s1)
		free(s1);
	s1 = get_next_line(fd, 0);
	while (s1)
	{
		if (strncmp(s, s1, strlen(s)) == 0)
		{
			lultimasponda = strtrim(s1, "\n,_ ");
			temp_ptr = lultimasponda;
			lultimasponda = ft_strchr1(lultimasponda, ' ');
			if (temp_ptr)
				free(temp_ptr);
			break ;
		}
		if (s1)
			free(s1);
		s1 = get_next_line(fd, 0);
	}
	if (s1)
		free(s1);
	return(lultimasponda);
}

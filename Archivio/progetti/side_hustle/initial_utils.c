/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:01 by negambar          #+#    #+#             */
/*   Updated: 2024/12/18 15:20:19 by negambar         ###   ########.fr       */
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
	s1 = get_next_line(fd, 0);
	while (s1)
	{
		if (strncmp(s, s1, strlen(s)) == 0)
		{
			char *temp = strtrim(s1, "\n,_ ");
			free(s1);
			if (!temp)
				break;
			lultimasponda = ft_strchr1(temp, ' ');
			free(temp);
			break ;
		}
		free(s1);
		s1 = get_next_line(fd, 0);
	}
	return(lultimasponda);
}

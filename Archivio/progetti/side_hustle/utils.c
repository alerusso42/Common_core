/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:46:50 by negambar          #+#    #+#             */
/*   Updated: 2024/12/18 17:59:18 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"

void	normalise_text(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[0] >= 'a' && s[0] <= 'z')
			s[i] -= 32;
		else if ((i != 0 && s[i - 1] != 32) && (s[i] >= 'A' && s[i] <= 'Z'))
		{
			s[i] += 32;
		}
		else
		{
			i++;
			continue;
		}
		i++;
	}
}

int mi_serve(all *this)
{
	int fd = open("player_info.txt", O_RDONLY);
	char *s = get_next_line(fd, 0);
	char *mynameis;
	char *first = get_that_line(fd, "Name = ", s);
	this->p->class = get_that_line(fd, "Class = ", s);
	// printf("\ns:%s", s);
	if (!first)
		return (free(s), freeall(this), 1);
	mynameis = first;
	first = strtrim(mynameis, "\n ");
	this->p->name->first_name = first;
	char *class = this->p->class;
	this->p->class = strtrim(class, "\n ");
	free(mynameis);
	free(class);
	if (!first)
		return (free(s), freeall(this), 1);
	return(0);
}

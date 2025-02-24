/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_initiate_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:58:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/24 11:46:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
initiate_file riceve:
1) fd;
2) il nome del giocatore.
	
	initiate_file inizializza il file del giocatore.

	initiate_file non torna niente.
*/
void	initiate_file_demo(int fd, char *name)
{
	int	counter;

	counter = MIDWORDS_LEN * 10;
	write(fd, "[TYPE_", 6);
	write(fd, name, ft_strlen(name));
	write(fd, "]", 1);
	write(fd, "\n\n", 2);
	write(fd, "Name = ", 7);
	hold_space(counter, fd);
	write(fd, "Age = ", 6);
	hold_space(counter, fd);
	write(fd, "Class = ", 8);
	hold_space(counter, fd);
	write(fd, "Species = ", 10);
	hold_space(counter, fd);
	write(fd, "Friends = ", 10);
	hold_space(counter, fd);
	write(fd, "[_ENDPLAYER_1]\n", 15);
	write(fd, "EOF\n", 4);
}

/*
initiate_file riceve:
1) fd;
2) il nome del tipo di dati;
3) la matrice con tutte le linee da inizializzare.

MOLTO IMPORTANTE: le stringhe della matrice non devono
avere ' ' e '='.
*/
void	initiate_file(int fd, char *name, char **matrix)
{
	int		counter;
	char	*temp;

	counter = set_maximum_word_len(-1) * set_maximum_words(-1);
	write(fd, "[", 1);
	write(fd, name, ft_strlen(name));
	write(fd, "]\n", 2);
	while ((matrix) && (*matrix))
	{
		temp = ft_strjoin(*matrix, " = ");
		if (!temp)
			return ;
		write(fd, temp, ft_strlen(temp));
		free(temp);
		temp = NULL;
		hold_space(counter, fd);
		++matrix;
	}
	write(fd, "[END]\n\n", 7);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_write_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:02:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 11:29:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

static int	move_cursor_buffer_one(int line_num, int fd, char *filename);
static int	skip_to_printzone(char **temp, int fd);
static int	print_file(char *string, char *temp, int fd);
static void	erase(char **ptr);

/*
	write_line riceve:
1) il numero della linea;
2) la posizione, nella linea, nel quale inserire la stringa;
3) la stringa da inserire.
	
	Scrive una stringa all'interno del file, ad una data linea (line_num),
	ad una certa posizione orizzontale (position).
	Esempio:
	write_line(2, 2, "Rossi"); 
	//Scrive alla linea 2, posizione 2.
1. [NPC_list]
2. Nome = Mario______, Rossi______, 

Ritorno:
		Il numero della linea dove si trova la corrispondenza;
		-1, se la ricerca fallisce oppure in caso di errori di malloc.

	Write_line ha un limite massimo di caratteri (10).
	Può essere cambiato in fase di esecuzione, con la
	funzione "set_maximum_word_len".
	Stessa cosa per le parole massime per linea,
	che puoi settare con "set_maximum_word".
*/
int	write_line(int line_num, int position, char *string)
{
	char	*temp;
	int		fd;
	char	*filename;
	int		max_words;

	get_filedata(&fd, &filename);
	if ((fd == -1) || (!string) || (position < 0) || (line_num < 0))
		return (-1);
	if (move_cursor_buffer_one(line_num, fd, filename) != 0)
		return (-2);
	temp = get_next_line(fd, 1);
	if (skip_to_printzone(&temp, fd) != 0)
		return (-4);
	max_words = position - set_maximum_words(-1);
	while (position--)
	{
		erase(&temp);
		if (position < max_words)
			return (-5);
		temp = get_next_line(fd, 1);
		if (skip_to_printzone(&temp, fd) != 0)
			return (-4);
	}
	return (print_file(string, temp, fd));
}

static void	erase(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static int	print_file(char *string, char *temp, int fd)
{
	int		counter;
	int		maximum_word_len;

	counter = 0;
	maximum_word_len = set_maximum_word_len(-1);
	while (counter != maximum_word_len)
	{
		if (*string)
		{
			write(fd, string, 1);
			string++;
		}
		else
			write(fd, "_", 1);
		++counter;
	}
	write (fd, ", ", 1);
	while ((temp[0] == '\n') || (temp[0] == '\0'))
	{
		erase(&temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
	}
	return (erase(&temp), 0);
}

static int	move_cursor_buffer_one(int line_num, int fd, char *filename)
{
	char	*temp;

	reset_fd(fd, filename);
	if (line_num != 1)
	{
		while ("move the cursor to the start of the line")
		{
			if (line_num == 1)
				break ;
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
			if (*temp == '\n')
				--line_num;
			erase(&temp);
		}
	}
	return (0);
}

static int	skip_to_printzone(char **temp, int fd)
{
	if ((!*temp) || (fd < 0))
		return (-1);
	while (((*temp)[0] != ' ') && ((*temp)[0] != '\n') && ((*temp)[0] != '\0'))
	{
		erase(temp);
		*temp = get_next_line(fd, 1);
		if (!*temp)
			return (-1);
	}
	if (((*temp)[0] == '\n') || ((*temp)[0] == '\0'))
		return (erase(temp), -1);
	return (0);
}

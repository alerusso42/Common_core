/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:30:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/28 15:12:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

static int	verify_line(char **matrix, int *counter, int position);
static char	*case_position_zero(char **matrix, int counter, char *temp);
static char	*case_position_one(char **matrix, int counter, char *temp);
static char	*case_others_position(char **matrix, int counter, int position);

/*	read_line riceve:
1) il numero della linea;
2) la posizione, nella linea, nel quale inserire la stringa.
	
	Legge una stringa all'interno del file, ad una data linea (line_num),
	ad una certa posizione orizzontale (position).
	Esempio:
	read_line(3, "file.txt", 2, 2); //Legge alla linea 2, posizione 2.
1. [NPC_list]
2. Nome = Mario______, Rossi______,  // Legge e torna "Rossi".

Ritorno:
		La stringa richiesta, senza , e _ finali;
		NULL, se la ricerca fallisce oppure in caso di errori di malloc.
*/
char	*read_line(int line_num, int position)
{
	int		counter;
	char	*temp;
	char	**matrix;
	int		fd;
	char	*filename;

	get_filedata(&fd, &filename);
	if ((fd == -1) || (position < 0) || (line_num < 0))
		return (NULL);
	reset_fd(fd, filename);
	if (line_num != 1)
		move_cursor(line_num);
	temp = get_next_line(fd, 0);
	matrix = ft_split(temp, ',');
	free(temp);
	if ((!matrix) || !(*matrix))
		return (NULL);
	if (verify_line(matrix, &counter, position) != 0)
		return (NULL);
	if (position == 0)
		return (case_position_zero(matrix, counter, temp));
	if (position == 1)
		return (case_position_one(matrix, counter, temp));
	return (case_others_position(matrix, counter, position));
}

/*Passaggi: 
			1)Splitta la linea ottenuta con ft_split;
			2)Se position è zero, torna quello che c'è prima di '='
			3)Se position è uno, elimina quello che c'è prima di "= "
			4)Altrimenti, scorre fino a trovare la posizione.
*/
static int	verify_line(char **matrix, int *counter, int position)
{
	*counter = 0;
	while (*counter != position)
	{
		if (!(matrix[*counter]))
			return (free_matrix(matrix), 1);
		if (*counter == 0)
		{
			(*counter)++;
			if (!(matrix[*counter]))
				return (free_matrix(matrix), 1);
			if (*counter == position)
				break ;
		}
		++(*counter);
	}
	return (0);
}

static char	*case_position_zero(char **matrix, int counter, char *temp)
{
	while ((matrix[0][counter] != '=') || (matrix[0][counter + 1] != ' '))
		++counter;
	++counter;
	cut_string(matrix[0], counter, ft_strlen(matrix[0]));
	temp = ft_strdup(matrix[0]);
	return (free_matrix(matrix), temp);
}

static char	*case_position_one(char **matrix, int counter, char *temp)
{
	while ((matrix[1][counter] != '=') || (matrix[1][counter + 1] != ' '))
		++counter;
	++counter;
	cut_string((matrix[1]), 0, counter);
	temp = ft_strdup(matrix[1]);
	return (free_matrix(matrix), temp);
}

static char	*case_others_position(char **matrix, int counter, int position)
{
	char	*temp;

	counter = 0;
	position--;
	while (matrix[position][counter])
		++counter;
	if (counter == 0)
		return (free_matrix(matrix), NULL);
	--counter;
	while (matrix[position][counter] == '_')
		--counter;
	++counter;
	cut_string((matrix[position]), counter, ft_strlen(matrix[position]));
	temp = ft_strdup(matrix[position]);
	if (temp[0] == ' ')
		cut_string(temp, 0, 0);
	return (free_matrix(matrix), temp);
}

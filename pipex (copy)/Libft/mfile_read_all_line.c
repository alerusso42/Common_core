/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_read_all_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:30:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/24 11:24:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

static int	skip_separators(char **matrix, int counter);
static char	**make_matrix_beautiful(char **matrix, int counter);

/*	read_line riceve:
1) fd;
2) il nome del file;
3) il numero della linea.
	
	Legge le stringhe all'interno del file, salvandole in una  
	matrice, ad una data linea (line_num).
	Esempio:
	read_all_line(3, "file.txt", 2); //Legge la linea 2.
1. [NPC_list]
2. Nome = Mario______, Rossi______,  // Legge e torna "Mario", "Rossi".

Ritorno:
		La matrice richiesta, senza , e _ finali;
		NULL, se la ricerca fallisce oppure in caso di errori di malloc.
*/
char	**read_all_line(int line_num)
{
	int		counter;
	char	*temp;
	char	**matrix;
	int		fd;
	char	*filename;

	get_filedata(&fd, &filename);
	if ((fd == -1) || (line_num < 0))
		return (NULL);
	reset_fd(fd, filename);
	if (line_num != 1)
		move_cursor(line_num);
	temp = get_next_line(fd, 0);
	matrix = ft_split(temp, ',');
	free(temp);
	if ((!matrix) || !(*matrix))
		return (NULL);
	if (!matrix[1])
		return (free_matrix(matrix), NULL);
	counter = 0;
	if (skip_separators(matrix, counter) != 0)
		return (NULL);
	return (make_matrix_beautiful(matrix, counter));
}

static int	skip_separators(char **matrix, int counter)
{
	while ((matrix[0][counter] != '=') || (matrix[0][counter + 1] != ' '))
		++counter;
	++counter;
	cut_string((matrix[0]), 0, counter);
	if (!matrix[0])
		return (free_matrix(matrix), 1);
	return (0);
}

static char	**make_matrix_beautiful(char **matrix, int counter)
{
	int	position;

	position = 0;
	while (matrix[position])
	{
		counter = 0;
		while (matrix[position][counter])
			++counter;
		if (counter == 0)
			return (free_matrix(matrix), NULL);
		counter -= 1;
		while (matrix[position][counter] == '_')
			--counter;
		++counter;
		cut_string((matrix[position]), counter, ft_strlen(matrix[position]));
		if (matrix[position][0] == ' ')
			cut_string((matrix[position]), 0, 0);
		if (matrix[position][0] == '\n')
		{
			free(matrix[position]);
			matrix[position] = NULL;
		}
		++position;
	}
	return (matrix);
}

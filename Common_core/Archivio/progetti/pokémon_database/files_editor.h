/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_editor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:36:12 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/24 12:07:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_EDITOR_H
# define FILES_EDITOR_H
# include "structs_info.h"
# include "general_ft.h"
# include "general_ft2.h"
# include "init_mon.h"
# include <unistd.h>
# include <malloc.h>
# include <string.h>
# include <fcntl.h>

int	end_char(char **pokedex_copy, char *temp, int size);
int	erase_pokedex(char **pokedex_copy);
int	insert_pkmn_index(char **pokedex_copy);
int	generate_newpokedex(char **pokedex_update, char *pokedex_copy, int n_file);
int	fill(char **pokedex_update, char *pokedex_copy, int n_file, char *temp);
int	read_new_pokedex(char **pokedex_update, int *index, char *s, int *size);

int	insert_pkmn_index(char **pokedex_copy)
{
	char	*pokedex_update;
	int		n_file;

	n_file = 0;
	if (generate_newpokedex(&pokedex_update, *pokedex_copy, n_file) != 0)
		return (1);
	ft_printf("\n%s\n", (*pokedex_update));
	free(*pokedex_copy);
	(*pokedex_copy) = NULL;
	(*pokedex_copy) = pokedex_update;
	return (0);
}

int	generate_newpokedex(char **pokedex_update, char *pokedex_copy, int n_file)
{
	char	*temp;

	if (alloc(&temp, 14) == 1)
		return (1);
	pokedex_update = (char **)malloc(sizeof(char *));
	(*pokedex_update) = (char *)malloc(ft_strlen(pokedex_copy));
	if (pokedex_update == NULL)
		return (free_update(pokedex_update, &temp));
	if ((*pokedex_update) == NULL)
		return (erase_pokedex(pokedex_update));
	n_file = open("updated_pokedex.txt", O_RDWR);
	if (n_file == -1)
	{
		close(n_file);
		return (free_update(pokedex_update, &temp));
	}
	if (fill(pokedex_update, pokedex_copy, n_file, temp) != 0)
	{
		close(n_file);
		return (free_update(pokedex_update, &temp));
	}
	close(n_file);
	return (0);
}

int	fill(char **pokedex_update, char *pokedex_copy, int n_file, char *temp)
{
	int		index;
	int		index_update;
	int		pkmn_nbr;
	int		size;

	size = ft_strlen(pokedex_copy);
	index = -1 + (n_file - n_file);
	index_update = -1;
	pkmn_nbr = 1;
	while ((pokedex_copy[++index] != '\0'))
	{
		++index_update;
		write(n_file, &pokedex_copy[index], 1);
		(*pokedex_update)[index] = pokedex_copy[index];
		if (pokedex_copy[index] == ']')
		{
			++index_update;
			temp = ft_itoa(pkmn_nbr, temp);
			write(n_file, temp, ft_strlen(temp));
			read_new_pokedex(pokedex_update, &index_update, temp, &size);
			++pkmn_nbr;
		}
	}
	end_char(pokedex_update, temp, index);
	return (0);
}

int	read_new_pokedex(char **pokedex_update, int *index, char *s, int *size)
{
	char	*temp;
	int		number;

	number = 0;
	*size += ft_strlen(s);
	temp = (char *)realloc((*pokedex_update), *size);
	if (!temp)
		return (1);
	(*pokedex_update) = temp;
	while (s[number] != '\0')
	{
		(*pokedex_update)[*index] = s[number];
		++(*index);
		++number;
	}
	return (0);
}
/*int	read_new_pokedex(char **pokedex_update, int n_file, int size)
{
	int		size;
	int		bytes_read;
	char	*temp;

	size = 0;
	bytes_read = 1;
	while (1)
	{
		bytes_read = read(n_file, (*pokedex_update) + size, CHUNK);
		if (bytes_read < 0)
			return (2);
		if (bytes_read == 0)
			break ;
		size += bytes_read;
		if (size + CHUNK > size)
		{
			size *= 2;
			temp = (char *)realloc((*pokedex_update), size);
			if (!temp)
				return (1);
			(*pokedex_update) = temp;
		}
	}
	end_char(pokedex_update, temp, size);
	return (0);
}*/

// 1236279

#endif
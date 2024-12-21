/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_alloc_pkmn_memory.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/20 17:47:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_ALLOC_PKMN_MEMORY_H
# define MALLOC_ALLOC_PKMN_MEMORY_H
# define STRING_NOT_FOUND -1
# include "general_ft2.h"
# include "malloc_alloc_pkmn_memory2.h"
# include "get_next_line_bonus.h"
# include <unistd.h>
# include <malloc.h>

int	count_nums(int index, char *pokedex);
int	alloc_nums_int(int **nums, int size);
int	alloc_nums_uchar(unsigned char **nums, int size);
int	alloc_str(char **string, int size);
int	alloc_strs(int index, char *pokedex, char ***strings, int position);

// Programmi per allocare memoria in fase di inizializzazione.
int	count_nums(int index, char *pokedex)
{
	int	count;

	count = 0;
	while ((*pokedex) && (pokedex[index] != '\n'))
	{
		if ((pokedex[index] >= '0') && (pokedex[index] <= '9'))
		{
			++count;
		}
		while ((pokedex[index] >= '0') && (pokedex[index] <= '9'))
		{
			++index;
		}
		if (pokedex[index] != '\n')
			++index;
	}
	return (count);
}

int	alloc_nums_int(int **nums, int size)
{
	(*nums) = (int *)ft_calloc(size + 1, sizeof(int));
	if ((*nums) == NULL)
		return (2);
	return (0);
}

int	alloc_nums_uchar(unsigned char **nums, int size)
{
	(*nums) = (unsigned char *)ft_calloc(size + 1, sizeof(unsigned char));
	if ((*nums) == NULL)
		return (2);
	return (0);
}

int	alloc_str(char **string, int size)
{
	(*string) = (char *)ft_calloc(size + 1, sizeof(char));
	if ((*string) == NULL)
		return (2);
	return (0);
}

int	alloc_strs(int index, char *pokedex, char ***strings, int position)
{
	int	count;

	count = 0;
	if (index == STRING_NOT_FOUND)
		return (1);
	if (alloc_strings_ptr(index, pokedex, strings) != 0)
		return (2);
	while (pokedex[index] != '\n')
	{
		if (((pokedex[index] >= 'a') && (pokedex[index] <= 'z'))
			|| ((pokedex[index] >= 'A') && (pokedex[index] <= 'Z')))
		{
			count = index;
			while (((pokedex[index] >= 'a') && (pokedex[index] <= 'z'))
			|| ((pokedex[index] >= 'A') && (pokedex[index] <= 'Z'))
			|| ((pokedex[index] >= '0') && (pokedex[index] <= '9'))
			|| (pokedex[index] >= '_'))
				++index;
			count = index - count;
			if (alloc_str(&(*strings)[position++], count + 1) != 0)
				return (2);
		}
		if (pokedex[index] != '\n')
			++index;
	}
	(*strings)[position] = NULL;
	return (0);
}

#endif
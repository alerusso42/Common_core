/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_alloc_pkmn_memory2.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/20 17:47:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_ALLOC_PKMN_MEMORY2_H
# define MALLOC_ALLOC_PKMN_MEMORY2_H
# include "general_ft2.h"
# include "get_next_line_bonus.h"
# include <unistd.h>
# include <malloc.h>

int			count_strings(int index, char *pokedex);
int			alloc_strings_ptr(int index, char *pokedex, char ***strings);
static void	*ft_calloc(size_t nmemb, size_t size);

int	count_strings(int index, char *pokedex)
{
	int	count;

	count = 0;
	while (pokedex[index] != '\n')
	{
		if (((pokedex[index] >= 'a') && (pokedex[index] <= 'z'))
			|| ((pokedex[index] >= 'A') && (pokedex[index] <= 'Z')))
		{
			while (((pokedex[index] >= 'a') && (pokedex[index] <= 'z'))
				|| ((pokedex[index] >= 'A') && (pokedex[index] <= 'Z'))
				|| ((pokedex[index] >= '0') && (pokedex[index] <= '9')))
			{
				++index;
			}
			++count;
		}
		if (pokedex[index] != '\n')
			++index;
	}
	return (count + 1);
}

int	alloc_strings_ptr(int index, char *pokedex, char ***strings)
{
	int	size;

	size = count_strings(index, pokedex);
	(*strings) = (char **)ft_calloc(sizeof(char *), size + 1);
	if ((*strings) == NULL)
		return (2);
	return (0);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	else
	{
		ft_memset(pointer, nmemb);
		return (pointer);
	}
}

#endif
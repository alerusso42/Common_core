/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 11:44:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_FT2_H
# define GENERAL_FT2_H
# include <unistd.h>
# include <malloc.h>

int	free_update(char **str1, char **str2);
int	alloc(char **str, int size);
int	sub_strcpy(char **dest, char *src);
int	sub_strlen(int i, int which_s, char *pokedex_copy);
int	sub_strlen2(char *src);

// Funzioni per allocare e liberare memoria quando il programma
// edita un file.
int	alloc(char **str, int size)
{
	(*str) = (char *)malloc(size);
	if (str == NULL)
		return (1);
	return (0);
}

int	free_update(char **str1, char **str2)
{
	free(*str1);
	free(*str2);
	return (1);
}

// Copia una sottostringa. Si ferma quando trova un carattere
// NON alfanumerico.
int	sub_strcpy(char **dest, char *src)
{
	int	i;

	i = 0;
	while ((((src[i] >= 'a') && (src[i] <= 'z'))
		|| ((src[i] >= 'A') && (src[i] <= 'Z'))
		|| ((src[i] >= '0') && (src[i] <= '9'))
		|| ((src[i] == ' ') || (src[i] == '_')))
		&& ((src[i] != '\0')) && ((*dest)[i] != '\0'))
	{
		(*dest)[i] = src[i];
		++i;
	}
	(*dest)[i] = '\0';
	return (0);
}

int	sub_strlen(int i, int which_s, char *pokedex_copy)
{
	int	len;

	if (i == -1)
		return (0);
	while (pokedex_copy[i] != '\n')
	{
		if ((((pokedex_copy[i] >= 'a') && (pokedex_copy[i] <= 'z'))
				|| ((pokedex_copy[i] >= 'A') && (pokedex_copy[i] <= 'Z')))
			&& (which_s == 1))
		{
			len = sub_strlen2(&pokedex_copy[i]);
			return (len + 1);
		}
		else if ((((pokedex_copy[i] >= 'a') && (pokedex_copy[i] <= 'z'))
				|| ((pokedex_copy[i] >= 'A') && (pokedex_copy[i] <= 'Z')))
			&& (which_s != 1))
			--which_s;
		while (((pokedex_copy[i] >= 'a') && (pokedex_copy[i] <= 'z'))
			|| ((pokedex_copy[i] >= 'A') && (pokedex_copy[i] <= 'Z'))
			|| ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9')))
			++i;
		if (pokedex_copy[i] != '\n')
			++i;
	}
	return (0);
}

int	sub_strlen2(char *src)
{
	int	i;

	i = 0;
	while (((src[i] >= 'a') && (src[i] <= 'z'))
		|| ((src[i] >= 'A') && (src[i] <= 'Z'))
		|| ((src[i] >= '0') && (src[i] <= '9')))
	{
		++i;
	}
	return (i);
}

#endif
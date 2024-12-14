/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mon2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/10 17:01:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MON2_H
# define INIT_MON2_H
# include "ft_printf.h"
# include "structs_info.h"
# include "general_ft.h"
# include "files_editor.h"
# include "atoi.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>

int	find_mon(struct s_pkmn **pkmn, char **pokedex_copy, char *input);
int	find_data(char *data, char *pokedex_copy, int index);

int	find_mon(struct s_pkmn **pkmn, char **pokedex_copy, char *input)
{
	int		i;
	char	pkmn_name[40];
	int		temp_i;

	i = 0;
	temp_i = 0;
	while (((*pokedex_copy)[i] != '\0') && ((*pkmn)->nbr == 0))
	{
		if ((*pokedex_copy)[i] == '[')
		{
			while ((*pokedex_copy)[++i] != ']')
			{
				pkmn_name[temp_i] = (*pokedex_copy)[i];
				++temp_i;
			}
			pkmn_name[temp_i] = '\0';
			temp_i = 0;
			if (ft_strcmp(input, pkmn_name) < 2)
				(*pkmn)->nbr = ft_atoi(&(*pokedex_copy)[i + 1]);
		}
		++i;
	}
	return (i);
}

int	find_data(char *data, char *pokedex_copy, int index)
{
	char 	store_tempdata[20];
	int		temp_index;

	temp_index = -1;
	while ((pokedex_copy[index] != '#') && (pokedex_copy[index] != '\0'))
	{
		if ((pokedex_copy[index] == '\n')
			&& (pokedex_copy[index + 1] != '\0')
			&& (pokedex_copy[index + 1] != '#'))
		{
			while (pokedex_copy[++index] != ' ')
				store_tempdata[++temp_index] = pokedex_copy[index];
			store_tempdata[++temp_index] = '\0';
			if (ft_strcmp(store_tempdata, data) == 0)
			{
				while (pokedex_copy[index] != '=')
					++index;
				++index;
				return (index);
			}
			temp_index = -1;
		}
		++index;
	}
	return (-1);
}

#endif
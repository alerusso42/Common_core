/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mon.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/22 09:09:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MON_H
# define INIT_MON_H
# include "ft_printf.h"
# include "structs_info.h"
# include "general_ft.h"
# include "files_editor.h"
# include "init_mon2.h"
# include "init_mon3.h"
# include "init_mon4.h"
# include "malloc_free_pkmn_memory.h"
# include "malloc_alloc_pkmn_memory.h"
# include "malloc_alloc_pkmn_memory2.h"
# include "atoi.h"
# include "ft_printf.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>

int	read_pokedex(char **pokedex_copy, int pokedex, int capacity);
int	end_char(char **pokedex_copy, char *temp, int size);
int	erase_pokedex(char **pokedex);
int	fake_main(struct s_pkmn **pkmn, char *input);

// pokedex = open("pokedex.txt", O_RDWR);
int	fake_main(struct s_pkmn **pkmn, char *input)
{
	char	**pokedex_copy;
	int		pokedex;

	pokedex_copy = (char **)malloc(sizeof(char *));
	(*pokedex_copy) = (char *)malloc(CHUNK);
	if (pokedex_copy == NULL)
	{
		free(pokedex_copy);
		return (1);
	}
	if ((*pokedex_copy) == NULL)
		return (erase_pokedex(pokedex_copy));
	pokedex = open("updated_pokedex.txt", O_RDWR);
	if (pokedex == -1)
		return (1);
	if (read_pokedex(pokedex_copy, pokedex, CHUNK) == 1)
		return (erase_pokedex(pokedex_copy));
	//ft_printf("\n%s\n", (*pokedex_copy));
	register_mon1(pkmn, pokedex_copy, input);
	erase_pokedex(pokedex_copy);
	free_all_init(pkmn);
	close(pokedex);
	(*pkmn)->nbr = 0;
	return (0);
}

int	read_pokedex(char **pokedex_copy, int pokedex, int capacity)
{
	int		size;
	int		bytes_read;
	char	*temp;

	size = 0;
	bytes_read = 1;
	while (1)
	{
		bytes_read = read(pokedex, (*pokedex_copy) + size, CHUNK);
		if (bytes_read < 0)
			return (2);
		if (bytes_read == 0)
			break ;
		size += bytes_read;
		if (size + CHUNK > capacity)
		{
			capacity *= 2;
			temp = (char *)realloc((*pokedex_copy), capacity);
			if (!temp)
				return (1);
			(*pokedex_copy) = temp;
		}
	}
	return (end_char(pokedex_copy, temp, size));
}

int	end_char(char **pokedex_copy, char *temp, int size)
{
	temp = (char *)realloc((*pokedex_copy), size + 1);
	if (!temp)
	{
		erase_pokedex(pokedex_copy);
		return (1);
	}
	(*pokedex_copy) = temp;
	(*pokedex_copy)[size] = '\0';
	return (0);
}

int	erase_pokedex(char **pokedex)
{
	free((*pokedex));
	free(pokedex);
	return (1);
}

// insert_pkmn_index(pokedex_copy);
/*int	register_mon(struct s_pkmn **pkmn, char **pokedex_copy, char *input)
{
	int	index;
	int	temp_index;

	(*pkmn)->nbr = 0;
	index = find_mon(pkmn, pokedex_copy, input);
	if ((*pkmn)->nbr == 0)
		return (1);
	(*pkmn)->index = index;
	ft_printf("\nNBR:%d\n", (*pkmn)->nbr);
	temp_index = find_data("generation", *pokedex_copy, index);
	(*pkmn)->gen = find_1num(temp_index, 1, *pokedex_copy);
	ft_printf("\ngen:%d\n", (*pkmn)->gen);
	temp_index = find_data("Basestats", *pokedex_copy, index);
	(*pkmn)->base_hp = find_1num(temp_index, 1, *pokedex_copy);
	(*pkmn)->base_atk = find_1num(temp_index, 2, *pokedex_copy);
	(*pkmn)->base_def = find_1num(temp_index, 3, *pokedex_copy);
	(*pkmn)->base_spatk = find_1num(temp_index, 5, *pokedex_copy);
	(*pkmn)->base_spdef = find_1num(temp_index, 6, *pokedex_copy);
	(*pkmn)->base_vel = find_1num(temp_index, 4, *pokedex_copy);
	ft_printf("\nhp:%d\n", (*pkmn)->base_hp);
	ft_printf("\natk:%d\n", (*pkmn)->base_atk);
	ft_printf("\ndef:%d\n", (*pkmn)->base_def);
	ft_printf("\nspatk:%d\n", (*pkmn)->base_spatk);
	ft_printf("\nspdef:%d\n", (*pkmn)->base_spdef);
	ft_printf("\nvel:%d\n", (*pkmn)->base_vel);
	temp_index = find_data("Moves", *pokedex_copy, index);
	alloc_nums_uchar(&(*pkmn)->move_level, count_nums(temp_index, *pokedex_copy));
	(*pkmn)->move_level = find_nums_uchar(temp_index, (*pkmn)->move_level, *pokedex_copy);
	for (int i = 0; (*pkmn)->move_level[i] != 0; ++i)
		ft_printf("\nmove_level:%d\n", (*pkmn)->move_level[i]);
	temp_index = find_data("Moves", *pokedex_copy, index);
	alloc_strs(temp_index, *pokedex_copy, &(*pkmn)->move_lup, 0);
	(*pkmn)->move_lup = find_strs(temp_index, (*pkmn)->move_lup, *pokedex_copy);
	ft_printf("\nmove_level_list: ");
	for (int i = 0; (*pkmn)->move_lup[i] != 0; ++i)
		ft_printf("%s, ", (*pkmn)->move_lup[i]);
	ft_printf("\b\b.\n");
	return (0);
}*/

/*(*pkmn)->nbr = 1;
	size_name = ft_strlen("Bulbasaur") + 1;
	(*pkmn)->name = (char *)malloc(size_name);
	ft_memset((*pkmn)->name, size_name);
	ft_strcpy((*pkmn)->name, "Bulbasaur");
	(*pkmn)->base_hp = 45;
	(*pkmn)->base_atk = 49;
	(*pkmn)->base_def = 49;
	(*pkmn)->base_spatk = 65;
	(*pkmn)->base_spdef = 65;
	(*pkmn)->base_vel = 45;
	(*pkmn)->gender_ratio = femaleoneeighth;
	(*pkmn)->types = (t_ob *)malloc(sizeof(t_ob) * 3);
	(*pkmn)->types[0] = grass;
	(*pkmn)->types[1] = poison;
	(*pkmn)->types[2] = 0;
	(*pkmn)->abilities[0] = overgrow;
	(*pkmn)->abilities[1] = chlorophyll;
	(*pkmn)->abilities[2] = 0;
	(*pkmn)->move_lup = tackle, growl, vinewhip, growth, leechseed, razorleaf, poisonpowder, sleeppowder, seedbomb, takedown, sweetscent, syntesis, worryseed, doubleedge, solarbeam);
	(*pkmn)->move_level = 1, 1, 3, 6, 9, 12, 15, 15, 18, 21, 24, 27, 30, 33, 36);
	(*pkmn)->height = 0.7;
	(*pkmn)->weight = 6.9;
	(*pkmn)->color = (char *)malloc(ft_strlen("Green") + 1);
	ft_strcpy((*pkmn)->color, "Green");
	(*pkmn)->evolutions[0] = (char *)malloc(ft_strlen("Ivysaur") + 1);
	ft_strcpy((*pkmn)->evolutions[0], "Ivysaur");
	(*pkmn)->egg_groups[0] = (char *)malloc(ft_strlen("Monster") + 1);
	ft_strcpy((*pkmn)->egg_groups[0], "Monster");
	(*pkmn)->egg_groups[1] = (char *)malloc(ft_strlen("Grass") + 1);
	ft_strcpy((*pkmn)->egg_groups[1], "Grass");*/

#endif
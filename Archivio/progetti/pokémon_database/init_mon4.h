/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mon4.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 12:02:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MON4_H
# define INIT_MON4_H
# include "ft_printf.h"
# include "structs_info.h"
# include "general_ft.h"
# include "files_editor.h"
# include "init_mon2.h"
# include "init_mon3.h"
# include "print_init_mon.h"
# include "malloc_free_pkmn_memory.h"
# include "malloc_alloc_pkmn_memory.h"
# include "atoi.h"
# include "ft_printf.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>

int	alloc_init_data1(struct s_pkmn **pkmn, char **pokedex);
int	alloc_init_data2(struct s_pkmn **pkmn, char **pokedex);
int	register_mon1(struct s_pkmn **pkmn, char **pokedex, char *input);
//int	register_mon2(struct s_pkmn **pkmn, char **pokedex);

int	alloc_init_data1(struct s_pkmn **pkmn, char **pokedex)
{
	int	index;
	int	temp_index;

	index = (*pkmn)->index;
	temp_index = find_data("name", *pokedex, index);
	alloc_str(&(*pkmn)->name, sub_strlen(temp_index, 1, *pokedex));
	temp_index = find_data("types", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->types_print, 0);
	temp_index = find_data("abilities", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->abilities_print, 0);
	temp_index = find_data("hiddenabilities", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->hid_abilities_print, 0);
	temp_index = find_data("moves", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->move_lup, 0);
	temp_index = find_data("moves", *pokedex, index);
	alloc_nums_uchar(&(*pkmn)->move_level, count_nums(temp_index, *pokedex));
	temp_index = find_data("tutormoves", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->move_tutor, 0);
	temp_index = find_data("eggmoves", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->move_egg, 0);
	alloc_init_data2(pkmn, pokedex);
	return (0);
}

int	alloc_init_data2(struct s_pkmn **pkmn, char **pokedex)
{
	int	index;
	int	temp_index;

	index = (*pkmn)->index;
	temp_index = find_data("evs", *pokedex, index);
	alloc_nums_uchar(&(*pkmn)->evs_given_val, count_nums(temp_index, *pokedex));
	alloc_strs(temp_index, *pokedex, &(*pkmn)->evs_given_type, 0);
	temp_index = find_data("eggGroups", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->egg_groups, 0);
	temp_index = find_data("GenderRatio", *pokedex, index);
	alloc_str(&(*pkmn)->gender_ratio, sub_strlen(temp_index, 1, *pokedex));
	temp_index = find_data("GrowthRate", *pokedex, index);
	alloc_str(&(*pkmn)->growth_rate, sub_strlen(temp_index, 1, *pokedex));
	temp_index = find_data("color", *pokedex, index);
	alloc_str(&(*pkmn)->color, sub_strlen(temp_index, 1, *pokedex));
	temp_index = find_data("shape", *pokedex, index);
	alloc_str(&(*pkmn)->shape, sub_strlen(temp_index, 1, *pokedex));
	temp_index = find_data("evolutions", *pokedex, index);
	alloc_strs(temp_index, *pokedex, &(*pkmn)->evolutions, 0);
	alloc_nums_int(&(*pkmn)->evo_level, count_nums(temp_index, *pokedex));
	temp_index = find_data("pokedex", *pokedex, index);
	alloc_str(&(*pkmn)->pokedex_entry, sub_strlen(temp_index, 1, *pokedex));
	return (0);
}

int	register_mon1(struct s_pkmn **pkmn, char **pokedex, char *input)
{
	int	index;
	int	temp_index;

	(*pkmn)->nbr = 0;
	index = find_mon(pkmn, pokedex, input);
	if ((*pkmn)->nbr == 0)
		return (1);
	(*pkmn)->index = index;

	alloc_init_data1(pkmn, pokedex);
	temp_index = find_data("Name", *pokedex, index);
	(*pkmn)->name = find_1str(temp_index, 1, (*pkmn)->name, *pokedex);
	temp_index = find_data("Types", *pokedex, index);
	(*pkmn)->types_print = find_strs(temp_index, (*pkmn)->types_print, *pokedex);
	temp_index = find_data("Basestats", *pokedex, index);
	(*pkmn)->base_hp = find_1num(temp_index, 1, *pokedex);
	(*pkmn)->base_atk = find_1num(temp_index, 2, *pokedex);
	(*pkmn)->base_def = find_1num(temp_index, 3, *pokedex);
	(*pkmn)->base_spatk = find_1num(temp_index, 5, *pokedex);
	(*pkmn)->base_spdef = find_1num(temp_index, 6, *pokedex);
	(*pkmn)->base_vel = find_1num(temp_index, 4, *pokedex);
	temp_index = find_data("GenderRatio", *pokedex, index);
	(*pkmn)->gender_ratio = find_1str(temp_index, 1, (*pkmn)->gender_ratio, *pokedex);
	temp_index = find_data("GrowthRate", *pokedex, index);
	(*pkmn)->growth_rate = find_1str(temp_index, 1, (*pkmn)->growth_rate, *pokedex);
	temp_index = find_data("EVs", *pokedex, index);
	(*pkmn)->evs_given_type = find_strs(temp_index, (*pkmn)->evs_given_type, *pokedex);
	(*pkmn)->evs_given_val = find_nums_uchar(temp_index, (*pkmn)->evs_given_val, *pokedex);
	temp_index = find_data("Catchrate", *pokedex, index);
	(*pkmn)->catchrate = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Happiness", *pokedex, index);
	(*pkmn)->base_happiness = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Abilities", *pokedex, index);
	(*pkmn)->abilities_print = find_strs(temp_index, (*pkmn)->abilities_print, *pokedex);
	temp_index = find_data("HiddenAbilities", *pokedex, index);
	(*pkmn)->hid_abilities_print = find_strs(temp_index, (*pkmn)->hid_abilities_print, *pokedex);
	temp_index = find_data("Moves", *pokedex, index);
	(*pkmn)->move_lup = find_strs(temp_index, (*pkmn)->move_lup, *pokedex);
	(*pkmn)->move_level = find_nums_uchar(temp_index, (*pkmn)->move_level, *pokedex);
	temp_index = find_data("TutorMoves", *pokedex, index);
	(*pkmn)->move_tutor = find_strs(temp_index, (*pkmn)->move_tutor, *pokedex);
	temp_index = find_data("EggMoves", *pokedex, index);
	(*pkmn)->move_egg = find_strs(temp_index, (*pkmn)->move_egg, *pokedex);
	temp_index = find_data("EggGroups", *pokedex, index);
	(*pkmn)->egg_groups = find_strs(temp_index, (*pkmn)->egg_groups, *pokedex);
	(*pkmn)->hatchsteps = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Color", *pokedex, index);
	(*pkmn)->color = find_1str(temp_index, 1, (*pkmn)->color, *pokedex);
	temp_index = find_data("Shape", *pokedex, index);
	(*pkmn)->shape = find_1str(temp_index, 1, (*pkmn)->shape, *pokedex);
	temp_index = find_data("Pokedex", *pokedex, index);
	(*pkmn)->pokedex_entry = find_1str(temp_index, 1, (*pkmn)->pokedex_entry, *pokedex);
	temp_index = find_data("Generation", *pokedex, index);
	(*pkmn)->gen = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Evolutions", *pokedex, index);
	(*pkmn)->evolutions = find_strs(temp_index, (*pkmn)->evolutions, *pokedex);
	(*pkmn)->evo_level = find_nums_int(temp_index, (*pkmn)->evo_level, *pokedex);
	print_pkmn_init1(*pkmn);
	return (0);
}
/*
int	register_mon2(struct s_pkmn **pkmn, char **pokedex)
{

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
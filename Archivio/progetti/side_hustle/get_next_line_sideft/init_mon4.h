/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mon4.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/20 18:10:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MON4_H
# define INIT_MON4_H
# include "general_ft.h"
# include "init_mon3.h"
# include "get_next_line_bonus.h"
# include "malloc_alloc_pkmn_memory.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>

int	alloc_init_data1(random_encounter **npc, char **pokedex);
int	alloc_init_data2(random_encounter **npc, char **pokedex);
int	register_mon1(random_encounter **npc, int fd, char *input);
//int	register_mon2(random_encounter **npc, char **pokedex);

int	alloc_init_data1(random_encounter **npc, int fd)
{
	char	*line;
	int		line_num;

	line = line_fgm(GET, fd, 1, "name = ");
	alloc_str(&(*npc)->name, sub_strlen(temp_index, 1, *pokedex));

	alloc_strs(0, *pokedex, &(*npc)->types_print, 0);

	alloc_strs(0, *pokedex, &(*npc)->abilities_print, 0);
	
	alloc_strs(0, *pokedex, &(*npc)->hid_abilities_print, 0);

	alloc_strs(0, *pokedex, &(*npc)->move_lup, 0);

	alloc_nums_uchar(&(*npc)->move_level, count_nums(0, *pokedex));

	alloc_strs(0, *pokedex, &(*npc)->move_tutor, 0);

	alloc_strs(0, *pokedex, &(*npc)->move_egg, 0);
	alloc_init_data2(npc, pokedex);
	return (0);
}

int	alloc_init_data2(random_encounter **npc, char **pokedex)
{
	int	index;

	index = (*npc)->index;

	alloc_nums_uchar(&(*npc)->evs_given_val, count_nums(0, *pokedex));
	alloc_strs(0, *pokedex, &(*npc)->evs_given_type, 0);

	alloc_strs(0, *pokedex, &(*npc)->egg_groups, 0);

	alloc_str(&(*npc)->gender_ratio, sub_strlen(0, 1, *pokedex));

	alloc_str(&(*npc)->growth_rate, sub_strlen(0, 1, *pokedex));

	alloc_str(&(*npc)->color, sub_strlen(0, 1, *pokedex));

	alloc_str(&(*npc)->shape, sub_strlen(0, 1, *pokedex));

	alloc_strs(0, *pokedex, &(*npc)->evolutions, 0);
	alloc_nums_int(&(*npc)->evo_level, count_nums(0, *pokedex));

	alloc_str(&(*npc)->pokedex_entry, sub_strlen(0, 1, *pokedex));
	return (0);
}

int	register_mon1(random_encounter **npc, int fd, char *filename, char *input)
{
	int		index;
	int		temp_index;
	char	*line;
	int		line_num;

	if (fd == -1)
		return (1);
	reset_fd(fd, filename);
	line = line_fgm(GET, fd, 1, input);
	if (!line)
		return (1);
	alloc_init_data1(npc, fd);
	temp_index = find_data("Name", *pokedex, index);
	(*npc)->name = find_1str(temp_index, 1, (*npc)->name, *pokedex);
	temp_index = find_data("Types", *pokedex, index);
	(*npc)->types_print = find_strs(temp_index, (*npc)->types_print, *pokedex);
	temp_index = find_data("Basestats", *pokedex, index);
	(*npc)->base_hp = find_1num(temp_index, 1, *pokedex);
	(*npc)->base_atk = find_1num(temp_index, 2, *pokedex);
	(*npc)->base_def = find_1num(temp_index, 3, *pokedex);
	(*npc)->base_spatk = find_1num(temp_index, 5, *pokedex);
	(*npc)->base_spdef = find_1num(temp_index, 6, *pokedex);
	(*npc)->base_vel = find_1num(temp_index, 4, *pokedex);
	temp_index = find_data("GenderRatio", *pokedex, index);
	(*npc)->gender_ratio = find_1str(temp_index, 1, (*npc)->gender_ratio, *pokedex);
	temp_index = find_data("GrowthRate", *pokedex, index);
	(*npc)->growth_rate = find_1str(temp_index, 1, (*npc)->growth_rate, *pokedex);
	temp_index = find_data("EVs", *pokedex, index);
	(*npc)->evs_given_type = find_strs(temp_index, (*npc)->evs_given_type, *pokedex);
	(*npc)->evs_given_val = find_nums_uchar(temp_index, (*npc)->evs_given_val, *pokedex);
	temp_index = find_data("Catchrate", *pokedex, index);
	(*npc)->catchrate = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Happiness", *pokedex, index);
	(*npc)->base_happiness = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Abilities", *pokedex, index);
	(*npc)->abilities_print = find_strs(temp_index, (*npc)->abilities_print, *pokedex);
	temp_index = find_data("HiddenAbilities", *pokedex, index);
	(*npc)->hid_abilities_print = find_strs(temp_index, (*npc)->hid_abilities_print, *pokedex);
	temp_index = find_data("Moves", *pokedex, index);
	(*npc)->move_lup = find_strs(temp_index, (*npc)->move_lup, *pokedex);
	(*npc)->move_level = find_nums_uchar(temp_index, (*npc)->move_level, *pokedex);
	temp_index = find_data("TutorMoves", *pokedex, index);
	(*npc)->move_tutor = find_strs(temp_index, (*npc)->move_tutor, *pokedex);
	temp_index = find_data("EggMoves", *pokedex, index);
	(*npc)->move_egg = find_strs(temp_index, (*npc)->move_egg, *pokedex);
	temp_index = find_data("EggGroups", *pokedex, index);
	(*npc)->egg_groups = find_strs(temp_index, (*npc)->egg_groups, *pokedex);
	(*npc)->hatchsteps = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Color", *pokedex, index);
	(*npc)->color = find_1str(temp_index, 1, (*npc)->color, *pokedex);
	temp_index = find_data("Shape", *pokedex, index);
	(*npc)->shape = find_1str(temp_index, 1, (*npc)->shape, *pokedex);
	temp_index = find_data("Pokedex", *pokedex, index);
	(*npc)->pokedex_entry = find_1str(temp_index, 1, (*npc)->pokedex_entry, *pokedex);
	temp_index = find_data("Generation", *pokedex, index);
	(*npc)->gen = find_1num(temp_index, 1, *pokedex);
	temp_index = find_data("Evolutions", *pokedex, index);
	(*npc)->evolutions = find_strs(temp_index, (*npc)->evolutions, *pokedex);
	(*npc)->evo_level = find_nums_int(temp_index, (*npc)->evo_level, *pokedex);
	print_npc_init1(*npc);
	return (0);
}
/*
int	register_mon2(random_encounter **pkmn, char **pokedex)
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
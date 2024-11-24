/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init_mon.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/22 09:56:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_INIT_MON_H
# define PRINT_INIT_MON_H
# include "ft_printf.h"
# include "structs_info.h"
# include "general_ft.h"
# include "files_editor.h"
# include "init_mon2.h"
# include "init_mon3.h"
# include "malloc_free_pkmn_memory.h"
# include "malloc_alloc_pkmn_memory.h"
# include "atoi.h"
# include "ft_printf.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>

void	print_pkmn_init1(struct s_pkmn *pkmn);
void	print_pkmn_init2(struct s_pkmn *pkmn);
void	print_pkmn_init3(struct s_pkmn *pkmn);
void	print_pkmn_init4(struct s_pkmn *pkmn);

void	print_pkmn_init1(struct s_pkmn *pkmn)
{
	int	i;

	ft_printf("\nNBR:%d\n", pkmn->nbr);
	ft_printf("\nName:%s\n", pkmn->name);
	ft_printf("\nSTATS:");
	ft_printf("hp:%d\n", pkmn->base_hp);
	ft_printf("atk:%d\n", pkmn->base_atk);
	ft_printf("def:%d\n", pkmn->base_def);
	ft_printf("spatk:%d\n", pkmn->base_spatk);
	ft_printf("spdef:%d\n", pkmn->base_spdef);
	ft_printf("vel:%d\n", pkmn->base_vel);
	if (pkmn->types_print != NULL)
	{
		ft_printf("\nTYPES:");
		i = -1;
		while (pkmn->types_print[++i] != NULL)
			ft_printf("%s, ", pkmn->types_print[i]);
		ft_printf("\b\b.\n");
	}
	if (pkmn->abilities_print != NULL)
	{
		ft_printf("\nABILITIES:");
		i = -1;
		while (pkmn->abilities_print[++i] != NULL)
			ft_printf("%s, ", pkmn->abilities_print[i]);
		ft_printf("\b\b.\n");
	}
	print_pkmn_init2(pkmn);
}

void	print_pkmn_init2(struct s_pkmn *pkmn)
{
	int	i;

	if (pkmn->hid_abilities_print != NULL)
	{
		ft_printf("\nHIDDEN ABILITIES:");
		i = -1;
		while (pkmn->hid_abilities_print[++i] != NULL)
			ft_printf("%s, ", pkmn->hid_abilities_print[i]);
		ft_printf("\b\b.\n");
	}
	if (pkmn->move_lup != NULL)
	{
		ft_printf("\nMOVE_LEVEL_LIST: ");
		i = -1;
		while (pkmn->move_lup[++i] != NULL)
		{
			ft_printf("%d:", pkmn->move_level[i]);
			ft_printf("%s, ", pkmn->move_lup[i]);
		}
		ft_printf("\b\b.\n");
	}
	if (pkmn->move_tutor != NULL)
	{
		ft_printf("\nMOVE_TUTOR_LIST: ");
		i = -1;
		while (pkmn->move_tutor[++i] != NULL)
			ft_printf("%s, ", pkmn->move_tutor[i]);
		ft_printf("\b\b.\n");
	}
	print_pkmn_init3(pkmn);
}

void	print_pkmn_init3(struct s_pkmn *pkmn)
{
	int	i;

	if (pkmn->move_egg != NULL)
	{
		ft_printf("\nMOVE_EGG_LIST: ");
		i = -1;
		while (pkmn->move_egg[++i] != NULL)
			ft_printf("%s, ", pkmn->move_egg[i]);
		ft_printf("\b\b.\n");
	}
	ft_printf("\nGrowth rate:%s\n", pkmn->growth_rate);
	if (pkmn->evs_given_type != NULL)
	{
		ft_printf("\nEVS given: ");
		i = -1;
		while (pkmn->evs_given_type[++i] != NULL)
		{
			ft_printf("%d:", pkmn->evs_given_val[i]);
			ft_printf("%s, ", pkmn->evs_given_type[i]);
		}
		ft_printf("\b\b.\n");
	}
	if (pkmn->evolutions != NULL)
	{
		ft_printf("\nEVOLUTIONS:");
		i = -1;
		while (pkmn->evs_given_type[++i] != NULL)
		{
			ft_printf("%s:", pkmn->evolutions[i]);
			ft_printf("%d, ", pkmn->evo_level[i / 2]);
		}
		ft_printf("\b\b.\n");
	}
	print_pkmn_init4(pkmn);
}

void	print_pkmn_init4(struct s_pkmn *pkmn)
{
	int	i;

	if (pkmn->evolutions != NULL)
	{
		ft_printf("\nEGG GROUPS: ");
		i = -1;
		while (pkmn->egg_groups[++i] != NULL)
			ft_printf("%s, ", pkmn->egg_groups[i]);
		ft_printf("\b\b.\n");
	}
	ft_printf("Gender ratio:%s\n", pkmn->gender_ratio);
	ft_printf("Shape:%s\n", pkmn->shape);
	ft_printf("Color:%s\n", pkmn->color);
	ft_printf("Pokedex_entry:%s.\n", pkmn->pokedex_entry);
	ft_printf("\nGeneration: %d\n", pkmn->gen);
	ft_printf("Base happiness: %d\n", pkmn->base_happiness);
	ft_printf("\nCatchrate: %d\n", pkmn->catchrate);
	ft_printf("\nHatchsteps: %d\n", pkmn->hatchsteps);
	ft_printf("\nINDEX: %d\n", pkmn->index);
	ft_printf("\n--END OF LIST--\n");
}

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/22 11:56:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_INFO_H
# define STRUCTS_INFO_H
# define CHUNK 1024

typedef unsigned char	t_ob;

struct	s_pkmn
{
	int		nbr;
	char	*name;
	t_ob	level;
	int		experience;
	t_ob	base_hp;
	t_ob	base_atk;
	t_ob	base_def;
	t_ob	base_spatk;
	t_ob	base_spdef;
	t_ob	base_vel;
	t_ob	iv_hp:5;
	t_ob	iv_atk:5;
	t_ob	iv_def:5;
	t_ob	iv_spatk:5;
	t_ob	iv_spdef:5;
	t_ob	iv_vel:5;
	t_ob	ev_hp;
	t_ob	ev_atk;
	t_ob	ev_def;
	t_ob	ev_spatk;
	t_ob	ev_spdef;
	t_ob	ev_vel;
	t_ob	nature:5;
	t_ob	hp;
	t_ob	atk;
	t_ob	def;
	t_ob	spatk;
	t_ob	spdef;
	t_ob	vel;
	t_ob	*types;
	char	**types_print;
	int		*abilities;
	char	**abilities_print;
	int		*hid_abilities;
	char	**hid_abilities_print;
	t_ob	*ability;
	char	*ability_print;
	int		*move_set;
	char	**move_lup;
	t_ob	*move_level;
	char	**move_tutor;
	char	**move_egg;
	int		*item_hold;
	char	*growth_rate;
	char	**evs_given_type;
	t_ob	*evs_given_val;
	char	**evolutions;
	int		*evo_level;
	char	**egg_groups;
	char	*gender_ratio;
	t_ob	gender:2;
	float	height;
	float	weight;
	char	*shape;
	char	*color;
	char	*pokedex_entry;
	t_ob	gen:4;
	t_ob	base_happiness;
	t_ob	catchrate;
	int		hatchsteps;
	int		index;
};

#endif

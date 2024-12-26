/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:14:09 by negambar          #+#    #+#             */
/*   Updated: 2024/12/24 03:51:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_classes
{
	unsigned int	classes:4;
} classes;

typedef struct s_names //done
{
	char	*first_name;
	char	*m_nicknames;
	char	*last_name;
}	names;

typedef struct s_player
{
	names			*name; //done
	size_t			age;
	int				honor; // estremi +-100
	unsigned int	*status;
	unsigned int	respect;	
	classes			*job; //16 classi
	unsigned int	races:1; // 2 razze iniziale
	char			*class;
	int				allignment:3;
}	player;

/*
typedef struct s_skills
{
	;
}	skills;

typedef struct s_weapon
{
	char			*name;
	unsigned int	damage_type:3;
	unsigned int	damage;
	unsigned int	range:8;
}	weapon;
*/
typedef struct	s_temp_stats
{
	unsigned char	buff_stats[6];
	unsigned int	cur_hitpoints;
	unsigned int	initiative_score:7;
	bool			death_saves[3];
}				temp_stats;

typedef struct s_sheet
{
	unsigned int	strength:7;
	unsigned int	dexterity:7;
	unsigned int	constitution:7;
	unsigned int	intelligence:7;
	unsigned int	wisdom:7;
	unsigned int	charisma:7;
	unsigned int	proficiency:7;
	unsigned int	ispiration:7;
	unsigned int	speed:6;
	unsigned int	armour_class:7;
	unsigned int	initiative:6;
	unsigned int	max_hitpoints;
	unsigned char	*skills;
	unsigned int	attack_bonus:8;
	unsigned char	**weapon;
	unsigned char	**spell_list;//stringhe
	temp_stats		*temp_stats;
}	sheet;

typedef struct	s_random_encounter
{
	char			*name;
	size_t			age;
	int				honor;
	unsigned int	respect;
	classes			*job; 
	unsigned int	races:7;
	char			*class;
	int				allignment:3;
	sheet			*sheet;
	temp_stats		t_stats;
}				random_encounter;
typedef struct	all_might
{
	player	*p;
	int		dices:5; //to do????
}	all;

typedef struct s_list_entity
{
	
}				list_entity;


#endif
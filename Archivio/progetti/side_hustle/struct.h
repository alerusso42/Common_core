/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:14:09 by negambar          #+#    #+#             */
/*   Updated: 2024/12/20 18:21:41 by alerusso         ###   ########.fr       */
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


typedef struct s_sheet
{
	unsigned int	strength:7;
	unsigned int	dexterity:7;
	unsigned int	constitution:7;
	unsigned int	intelligence:7;
	unsigned int	wisdom:7;
	unsigned int	charisma:7;
	unsigned char	buff_stats[6];
	unsigned int	proficiency:7;
	unsigned int	ispiration:7;
	unsigned int	speed:6;
	unsigned int	armour_class:7;
	unsigned int	initiative:6;
	unsigned int	max_hitpoints;
	unsigned int	cur_hitpoints;
	skills			*skills;
	bool			death_saves[3];
	unsigned int	attack_bonus:8;
	weapon			*weapon;
	unsigned char	**spell_list;//stringhe
	// unsigned char	;
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
	
}	random_encounter;
typedef struct	all_might
{
	player	*p;
	int		dices:5; //to do????
}	all;

typedef struct s_list_entity
{
	
}				list_entity;


#endif
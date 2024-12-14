/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:14:09 by negambar          #+#    #+#             */
/*   Updated: 2024/12/14 11:25:03 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
	int				allignment:3;
}	player;

typedef struct	all_might
{
	player	*p;
	int		dices:5; //done
}	all;

#endif
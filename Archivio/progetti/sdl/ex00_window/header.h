/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/07 14:48:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define X 0
# define Y 0
# define W 500
# define H 700
# include "../../../../SDL2/include/SDL.h"
# include <stdio.h>

//	 cc main.c -o main $(sdl2-config --cflags --libs) \
	PKG_CONFIG_PATH=./Common_core/SDL2/pkgconfig gcc \
-I./Common_core/SDL2/include -L./Common_core/SDL2/lib \
-o exe main.c -lSDL2 -lSDL2_image

/*
	win:	connection to window;
*/
typedef struct s_sdl
{
	void	*win;
}				t_sdl;

#endif
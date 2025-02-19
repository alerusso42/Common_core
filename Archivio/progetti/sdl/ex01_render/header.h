/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/19 18:30:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define X 0
# define Y 0
# define W 500
# define H 700
# define FRAME 16
# include "../../../../SDL2/include/SDL.h"
# include <stdio.h>

/*
	Why FRAME 16?

	We pause the loop for 16 milliseconds on 
	each iteration, effectively limiting it 
	to about 60 iterations per second (60 FPS). 

1000 ms (=1 second) / 16 ms (delay per frame) ≈ 60 FPS
​
*/
//	 cc main.c -o main $(sdl2-config --cflags --libs)
//	PKG_CONFIG_PATH=./Common_core/SDL2/pkgconfig gcc \
-I./Common_core/SDL2/include -L./Common_core/SDL2/lib \
-o exe main.c -lSDL2 -lSDL2_image

/*
	run:		if loops goes or not;
	color:		unused.
	runtime:	for Loop delay;
	frame_start:for Loop delay;
	win:		connection to window;
	render:		data about rendering;
	SDL_RECT:	x, y (position in screen), w, h (size).
*/
typedef struct s_sdl
{
	char			run;
	unsigned int	color;
	unsigned int	runtime;
	unsigned int	frame_start;
	void			*win;
	void			*render;
	SDL_Rect		rect;
}				t_sdl;

#endif
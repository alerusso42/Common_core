/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/19 19:09:15 by alerusso         ###   ########.fr       */
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
# include "../../../../SDL2/include/SDL_image.h"

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

//	NEW:

/*	PKG_CONFIG_PATH=./Common_core/SDL2/pkgconfig gcc 
-I./Common_core/SDL2/include -L./Common_core/SDL2/lib 
-o exe main.c -lSDL2 -lSDL2_image
*/

/*
	run:		if loops goes or not;
	runtime:	for Loop delay;
	frame_start:for Loop delay;
	win:		connection to window;
	render:		data about rendering;
	surface:	image data.
*/
typedef struct s_sdl
{
	char			run;
	int				img_flags;
	unsigned int	runtime;
	unsigned int	frame_start;
	void			*win;
	void			*render;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		rect;
}				t_sdl;

typedef enum e_valid_files
{
	VALID_FILES = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP,
}			t_valid_files;

#endif
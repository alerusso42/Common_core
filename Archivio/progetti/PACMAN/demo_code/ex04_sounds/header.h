/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:56:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:56:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define X 0
# define Y 0
# define W 500
# define H 700
# define FRAME 16
# define S_MUSIC "../mus/Feeling-Resolute.ogg"
# define S_BEGIN "../mus/pacman_beginning.wav"
# define S_CHOMP "../mus/pacman_chomp.wav"
# define S_DEATH "../mus/pacman_death.wav"
# define S_EATFRUIT "../mus/pacman_eatfruit.wav"
# define S_EATGHOST "../mus/pacman_eatghost.wav"
# define S_EXTRAPAC "../mus/pacman_extrapac.wav"
# define S_INTERMISSION "../mus/pacman_intermission.wav" 
# include <SDL3/SDL_mixer.h>
# include <SDL3/SDL_image.h>
# include <SDL3/SDL.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_img
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}				t_img;

typedef struct s_mix
{
	Mix_Music		*music;
	Mix_Chunk		*sound[10];
	int				frequency;
	int				channels;
	int				chunksize;
	Uint16			format;
}				t_mix;

/*
	Why FRAME 16?

	We pause the loop for 16 milliseconds on 
	each iteration, effectively limiting it 
	to about 60 iterations per second (60 FPS). 

1000 ms (=1 second) / 16 ms (delay per frame) ≈ 60 FPS
​
*/
//	 cc main.c -o main $(SDL3-config --cflags --libs)

//	2.0:

/*	PKG_CONFIG_PATH=./Common_core/SDL3/pkgconfig gcc \
-I./Common_core/SDL3/include -L./Common_core/SDL3/lib \
-o exe main.c -lSDL3 -lSDL3_image
*/

/*
	CURRENT:

	gcc main.c animations.c sounds.c  -o exe  $(SDL3-config\
	 --cflags --libs) -lSDL3_image -lSDL3_mixer -lSDL3_ttf -g
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
	int				curr_img;
	unsigned int	runtime;
	unsigned int	frame_start;
	void			*win;
	void			*render;
	SDL_Rect		rect;
	t_img			img[3];
	t_mix			mix;
}				t_sdl;

enum e_valid_files
{
	VALID_FILES = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP,
};

enum e_event
{
	UPDATE_SCREEN = (SDL_USEREVENT + 1),
};

typedef struct s_sounds
{
	const char	*s;
}				t_sounds;

int		test(void);
void	game_loop(t_sdl *sdl);
int		update_screen(t_sdl *sdl, int *which);
int		get_images(t_sdl *sdl);
int		get_sounds(t_sdl *sdl);
int		dialga(unsigned int ms);

#endif
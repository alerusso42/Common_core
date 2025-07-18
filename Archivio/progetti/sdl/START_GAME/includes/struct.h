/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:41:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/27 00:29:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "pacman.h"

typedef struct s_data	t_data;
typedef struct s_SDL	t_SDL;
typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_player	t_player;
typedef struct s_enemy	t_enemy;
typedef enum e_general	t_general;


struct s_game
{
	int		map_size[2];
	int		collectables;
	int		enemy_num;
	bool	exit;
};


struct s_SDL
{
	Mix_Music	*mus[TOTAL_MUS + 1];
	Mix_Chunk	*sound[TOTAL_SOUND + 1];
	SDL_Texture	*texture[TOTAL_TEXTURES + 1];
	void		*win;
	void		*render;
};

struct s_map
{
	char	*distance;
	char	val;
};

struct s_player
{
	int	pos[2];
	int	lifes;
};

struct s_enemy
{
	int		pos[2];
	int		spawn_time;
	bool	triggered;
};

struct s_data
{
	t_SDL		sdl;
	t_game		game;
	t_player	player;
	t_fd		debug_file;
	t_enemy		*enemy;
	t_map		**map;
	t_map		**old_map;
	int			last_error;
	bool		run;
};

enum e_error
{
	ER_OK,
	ER_MALLOC,
	ER_OPEN,
	ER_SDL,
	ER_DAFT,
};

enum e_general
{
	X,
	Y,	
};

#endif
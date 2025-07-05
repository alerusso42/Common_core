/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:41:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 12:26:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "pacman.h"

typedef struct s_timer	t_timer;
typedef struct s_data	t_data;
typedef struct s_SDL	t_SDL;
typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_entity	t_entity;
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
	SDL_Rect	rect;
	void		*win;
	void		*render;
};

struct s_map
{
	char	*distance;
	char	val;
};

struct s_timer
{
	uint64_t	last;
	uint64_t	interval;
};

struct s_entity
{
	t_timer	move;
	t_timer	anim;
	int		id;
	int		pos[2];
	int		lifes;
	int		spawn_time;
	int		speed;
	char	frame;
	char	last_frame;
	char	type;
	uint8_t	dir:3;
	bool	triggered;
};

struct s_data
{
	t_SDL		sdl;
	t_game		game;
	t_entity	player;
	t_entity	exit;
	t_fd		debug_file;
	t_entity	*enemy;
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
	ER_MAP_ID,
	ER_MAP_EXTENSION,
	ER_MAP_LITTLE,
	ER_MAP_BIG,
	ER_MAP_PLAYER,
	ER_MAP_EXIT,
	ER_MAP_FLOODFILL,
};

enum e_symbol
{
	S_PLAYER = 	'P',
	S_COL = 	'C',
	S_EXIT = 	'E',
	S_ENEMY =	'$',
	S_FMARK = 	'X',
	S_FLOOR = 	'0',
	S_WALL = 	'1',
	S_HARD_WALL = 0,	
};

enum e_entity_type
{
	EN_RED,
	EN_PURPLE,
	EN_CIAN,
	EN_ORANGE,
	TOTAL_ENEMIES,
	EN_EXIT,
	EN_LAST = -1,
};

enum e_general
{
	X,
	Y,
	RANDOM = -2,
	MIN_MAP = 4,
	MAX_MAP = 1000,
	COL_RED = 0,
	COL_GREEN = 1,
	COL_BLUE = 2,
	COL_ALPHA = 3,
	COL_TOTAL,
	DOWN = 0,
	FRONT,
	LEFT,
	RIGHT,
	UP,
	TOTAL_MOVEMENT,
	PLAYER = EN_LAST,
};

#endif
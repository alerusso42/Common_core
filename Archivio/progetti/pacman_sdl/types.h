/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:15:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 11:43:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define ON 1
# define YES 1
# define OFF 0
# define NO 0
# define NO_RANDOM 2
# define CREATE 1
# define READ 0
# define GET 2
# define UPDATE 1

typedef struct s_input		t_input;
typedef struct s_map		t_map;
typedef struct s_position	t_position;
typedef struct s_random		t_random;
typedef struct s_sdl		t_sdl;
typedef struct s_enemy		t_enemy;
typedef struct s_all		t_all;
typedef unsigned char		t_onebyte;
typedef unsigned int		t_bool;

//	EXPLAINATION OF DATA STRUCTS
/*
	n:		the n_enemy
	en_x:	the x position of the enemy
	en_y:	the y position of the enemy
*/
typedef struct s_bfs
{
	int			n;
	int			mark;
	int			en_x;
	int			en_y;
	int			p_x;
	int			p_y;
	int			x;
	int			y;
	int			map_x;
	int			map_y;
	t_position	**position;
	int			distance;
}				t_bfs;

struct s_col
{
	t_onebyte	*x;
};
struct s_row
{
	t_onebyte	*y;
};
struct s_input
{
	t_bool				switch_1_bonus:1;
	t_bool				switch_2_rechargemap:1;
	t_bool				switch_3_confirm_before_exit;
	t_bool				create_map:1;
	t_bool				freeze:1;
	t_bool				kill_pac:1;
	t_bool				quit_process:1;
	char				valid_signs[7];
	unsigned int		en_speed:4;
	int					game_size;
	int					game_size_w;
	int					game_size_h;
	char				*filename;
	struct s_col		col;
	struct s_row		row;
};
struct s_position
{
	t_onebyte	value;
	char		*distance;
};
struct s_enemy
{
	int				x;
	int				y;
	int				x_start;
	int				y_start;
	unsigned int	color:2;
	unsigned int	dir:3;
	t_bool			triggered:1;
};
struct s_map
{
	t_bool				switch_1_bonus:1;
	t_bool				switch_2_printonterminal:1;
	int					variable_1_player_num;
	unsigned int		variable_2_printdata:2;
	t_onebyte			variable_3_enemy_num;
	int					variable_4_collectable_num;
	int					variable_5_internal_wall_num;
	int					variable_6_window_width;
	int					variable_7_window_heigth;
	char				display_name[7];
	int					game_size;
	int					game_size_w;
	int					game_size_h;
	int					free_spaces;
	int					void_spaces;
	int					wall_number;
	int					collectable_num;
	int					collectable_left;
	t_bool				is_solved:1;
	t_bool				player_first_move:1;
	int					e_x;
	int					e_y;
	t_enemy				*enemy;
	int					p_x;
	int					p_y;
	int					p_x_start;
	int					p_y_start;
	int					p_dir;
	int					p_mov;
	int					p_frame;
	struct s_position	**position;
	struct s_position	**old_pos;
};
struct s_random
{
	t_bool		switch_1_showseed:1;
	t_bool		switch_2_showrandomvalues:1;
	t_bool		switch_3_choose_map_entities_num:1;
	t_onebyte	variable_1_setseed;
	t_onebyte	variable_2_randomizer:2;
	t_onebyte	variable_3_enemy_num;
	int			variable_4_collectable_num;
	int			variable_5_internal_wall_num;
	int			variable_6_internal_wall_proportion;
	int			wden;
	t_onebyte	seed;
	int			*values;
};
typedef struct s_mix
{
	Mix_Music		*music;
	Mix_Chunk		**sounds;
	int				frequency;
	int				channels;
	int				chunksize;
	Uint16			format;
}				t_mix;
typedef struct s_img
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}				t_img;
struct s_sdl
{
	char			run;
	int				img_flags;
	int				curr_img;
	unsigned int	runtime;
	unsigned int	frame_start;
	void			*win;
	void			*render;
	t_mix			mix;
	t_sprite		*sprite;
	t_img			*img;
	int				start_x;
	int				start_y;
	int				variable_1_sprite_size;
};
struct s_all
{
	t_input		*input;
	t_map		*map;
	t_random	*random;
	t_sdl		*sdl;
};

enum e_valid_files
{
	VALID_FILES = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP,
};

typedef enum e_game_files
{
    BLUE,
    CIAN_DOWN,
    CIAN_FRONT,
    CIAN_LEFT,
    CIAN_RIGHT,
    CIAN_UP,
    CLOSE_EXIT,
    DEAD,
    DOT,
    EXIT,
    FLOOR,
    ORANGE_DOWN,
    ORANGE_FRONT,
    ORANGE_LEFT,
    ORANGE_RIGHT,
    ORANGE_UP,
    PAC_CLOSE_DOWN,
    PAC_CLOSE_LEFT,
    PAC_CLOSE_RIGHT,
    PAC_CLOSE_UP,
    PAC_DEAD_1,
    PAC_DEAD_2,
    PAC_DEAD_3,
    PAC_DEAD_4,
    PAC_HALF_DOWN,
    PAC_HALF_LEFT,
    PAC_HALF_RIGHT,
    PAC_HALF_UP,
    PAC_OPEN_DOWN,
    PAC_OPEN_LEFT,
    PAC_OPEN_RIGHT,
    PAC_OPEN_UP,
    PURPLE_DOWN,
    PURPLE_FRONT,
    PURPLE_LEFT,
    PURPLE_RIGHT,
    PURPLE_UP,
    RED_DOWN,
    RED_FRONT,
    RED_LEFT,
    RED_RIGHT,
    RED_UP,
    SPECIAL_DOT,
    WALL_DOWN,
    WALL_LEFT,
    WALL_RIGHT,
    WALL_TOTAL,
    WALL_UP,
    GAME_FILES_COUNT,
} t_game_files;

#endif
#ifndef H_H
# define H_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/types.h>

# define WIN_X 800
# define WIN_Y 800
# define TITLE "TEST"
# define FPS 10
# define FRAME_RATE ((1000 / FPS) * 1000)

enum e_sprites
{
	EXAMPLE,
	PICS_NUM,
};

typedef struct timeval	t_time;

typedef struct s_mlx
{
	t_time		start;
	void		*con;
	void		*window;
	void		*sprite[PICS_NUM];
	int			start_x;
	int			start_y;
	int			variable_1_sprite_size;
}	t_mlx;



#endif
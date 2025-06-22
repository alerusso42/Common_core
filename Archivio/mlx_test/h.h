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
# include <limits.h>

# define WIN_X 800
# define WIN_Y 800
# define P_X (WIN_X / 2)
# define P_Y (WIN_Y / 2)
# define X (INT_MAX)
# define Y (INT_MIN)
# define TITLE "GIORNO GIOVANNA"
# define FPS 60
# define FRAME_RATE ((1000 / FPS) * 1000)
# define START_COLOR 0xFF00FF

enum e_sprites
{
	EZIO_GREGGIO,
	PICS_NUM,
};

enum e_sign
{
	NEGATIVE = -1,
	POSITIVE = 1,
};

enum e_mouse
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_CENTER = 3,
	MOUSE_UP = 4,
	MOUSE_DOWN = 5,
};

typedef struct timeval	t_time;

typedef struct s_mlx
{
	t_time		start;
	void		*con;
	void		*window;
	void		*sprite[PICS_NUM];
	int			p_x;
	int			p_y;
	int			last_p_x;
	int			last_p_y;
	int			last_mouse_x;
	int			last_mouse_y;
	int			line_color;
}	t_mlx;

typedef struct s_drawline
{
	double		delta_x;
	double		delta_y;
	double		curr_x;
	double		curr_y;
	int			int_x;
	int			int_y;
	int			next_x;
	int			next_y;
	int			final_x;
	int			final_y;
	char		x_sign:2;
	char		y_sign:2;
}	t_drawline;

void	draw_line(t_mlx *mlx, int x, int y);
int		_random(int size);
double	proportion(double a, double b, double c, double d);
double	safe_division(double divisor, double dividend);
long	elapsed_time(t_time start);
int		random_color(void);

#endif
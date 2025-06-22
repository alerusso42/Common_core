#include "../h.h"

static void		get_data(t_mlx *mlx, int x, int y, t_drawline *draw);
static void		calc_diff(t_drawline *draw);
static void		update_coordinates(t_drawline *draw);

void	draw_line(t_mlx *mlx, int x, int y)
{
	t_drawline	draw;
	int			color;

	draw = (t_drawline){0};
	color = mlx->line_color;
	get_data(mlx, x, y, &draw);
	while ((draw.int_x != draw.final_x && draw.int_y != draw.final_y) && \
		(draw.int_x >= 0 && draw.int_y >= 0) && \
		(draw.int_x <= WIN_X && draw.int_y <= WIN_Y))
	{
		mlx_pixel_put(mlx->con, mlx->window, draw.int_x, draw.int_y, color);
		draw.curr_x += draw.delta_x;
		draw.curr_y += draw.delta_y;
		update_coordinates(&draw);
	}
}

static void	get_data(t_mlx *mlx, int x, int y, t_drawline *draw)
{
	draw->curr_x = mlx->p_x;
	draw->curr_y = mlx->p_y;
	draw->final_x = x;
	draw->final_y = y;
	draw->x_sign = POSITIVE;
	if (mlx->p_x > x)
		draw->x_sign = NEGATIVE;
	draw->y_sign = POSITIVE;
	if (mlx->p_y > y)
		draw->y_sign = NEGATIVE;
	draw->int_x = mlx->p_x;
	draw->int_y = mlx->p_y;
	draw->next_x = mlx->p_x + draw->x_sign;
	draw->next_y = mlx->p_y + draw->y_sign;
	calc_diff(draw);
}

static void	calc_diff(t_drawline *draw)
{
	int	sum_x_y;

	draw->delta_x = (double)abs((int)(draw->final_x - draw->curr_x));
	draw->delta_y = (double)abs((int)(draw->final_y - draw->curr_y));
	sum_x_y = draw->delta_x + draw->delta_y;
	draw->delta_x = proportion(draw->delta_x, sum_x_y, X, 100) / 100;
	draw->delta_y = 1 - draw->delta_x;
	draw->delta_x *= draw->x_sign;
	draw->delta_y *= draw->y_sign;
}

static void		update_coordinates(t_drawline *draw)
{
	if ((draw->x_sign == POSITIVE && draw->curr_x > draw->next_x) || \
		(draw->x_sign == NEGATIVE && draw->curr_x < draw->next_x))
	{
		draw->int_x += draw->x_sign;
		draw->next_x += draw->x_sign;
	}
	if ((draw->y_sign == POSITIVE && draw->curr_y > draw->next_y) || \
		(draw->y_sign == NEGATIVE && draw->curr_y < draw->next_y))
	{
		draw->int_y += draw->y_sign;
		draw->next_y += draw->y_sign;
	}
}
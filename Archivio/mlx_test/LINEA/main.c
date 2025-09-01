#include "../h.h"

//NOTE - Mouse line draw

static int	mouse(int keycode, t_mlx *mlx);
static int	keyboard(int keycode, t_mlx *mlx);
static int	loop(t_mlx *mlx);
static bool	something_moved(t_mlx *mlx, int pos[2]);

int	main()
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.con = mlx_init();
	if (!mlx.con)
		return (1);
	mlx.window = mlx_new_window(mlx.con, WIN_X, WIN_Y, TITLE);
	if (!mlx.window)
		return (free(mlx.con), 1);
	mlx_mouse_get_pos(mlx.con, mlx.window, &mlx.last_mouse_x, &mlx.last_mouse_y);
	mlx.last_p_x = P_X;
	mlx.last_p_y = P_Y;
	mlx.p_x = P_X;
	mlx.p_y = P_Y;
	mlx.line_color = START_COLOR;
	mlx_mouse_hook(mlx.window, mouse, &mlx);
	mlx_key_hook(mlx.window, keyboard, &mlx);
	mlx_loop_hook(mlx.con, loop, &mlx);
	gettimeofday(&mlx.start, NULL);
	mlx_loop(mlx.con);
	free(mlx.window);
	free(mlx.con);
}

static int	keyboard(int keycode, t_mlx *mlx)
{
	printf("%d\n", keycode);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->con, mlx->window);
		mlx_destroy_display(mlx->con);
		free(mlx->con);
		exit(0);
	}
	else if (keycode == XK_F1)
		mlx_do_key_autorepeatoff(mlx->con);
	else if (keycode == XK_F2)
		mlx_do_key_autorepeaton(mlx->con);
	else if (keycode == XK_F3)
		mlx->line_color = random_color();
	else if (keycode == XK_Left || keycode == XK_a)
		mlx->p_x -= 100;
	else if (keycode == XK_Right || keycode == XK_d)
		mlx->p_x += 100;
	else if (keycode == XK_c || keycode == XK_C)
		mlx->line_color = random_color();
	else if (keycode == XK_Down || keycode == XK_s)
		mlx->p_y += 100;
	else if (keycode == XK_Up || keycode == XK_w)
		mlx->p_y -= 100;
	return (0);
}

static int	mouse(int keycode, t_mlx *mlx)
{
	return (0);
	printf("%d\n", keycode);
	if (keycode == MOUSE_LEFT)
		mlx->p_x -= 100;
	else if (keycode == MOUSE_RIGHT)
		mlx->p_x += 100;
	else if (keycode == MOUSE_CENTER)
		mlx->line_color = random_color();
	else if (keycode == MOUSE_UP)
		mlx->p_y += 100;
	else if (keycode == MOUSE_DOWN)
		mlx->p_y -= 100;
	return (0);
}

static int	loop(t_mlx *mlx)
{
	int			pos[2];

	mlx_mouse_get_pos(mlx->con, mlx->window, &pos[0], &pos[1]);
	if (elapsed_time(mlx->start) > FRAME_RATE && something_moved(mlx, pos) == true)
	{
		mlx_clear_window(mlx->con, mlx->window);
		printf("Mouse\tx:%d\ty:%d\t\n", pos[0], pos[1]);
		line(mlx, PI / 2);
		mlx_do_sync(mlx->con);
		mlx->last_p_x = mlx->p_x;
		mlx->last_p_y = mlx->p_y;
		mlx->last_mouse_x = pos[0];
		mlx->last_mouse_y = pos[1];
		gettimeofday(&mlx->start, NULL);
	}
	return (0);
}

static bool	something_moved(t_mlx *mlx, int pos[2])
{
	if (mlx->last_mouse_x != pos[0] || mlx->last_mouse_y != pos[1])
		return (true);
	else if (mlx->last_p_x != mlx->p_x || mlx->last_p_y != mlx->p_y)
		return (true);
	return (false);
}

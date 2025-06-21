#include "../h.h"

//NOTE - Mouse coordinates

/* int	main()
{
	t_mlx	mlx;
	int		pos[2];

	mlx = (t_mlx){0};
	mlx.con = mlx_init();
	mlx.window = mlx_new_window(mlx.con, WIN_X, WIN_Y, TITLE);
	if (!mlx.window)
		return (free(mlx.con), 1);
	sleep(2);
	mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]);
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
	free(mlx.window);
	free(mlx.con);
} */

//NOTE - Mouse timid
//NOTE - Doesn't hide pointer: hides data

/* int	main()
{
	t_mlx	mlx;
	int		pos[2];

	mlx = (t_mlx){0};
	mlx.con = mlx_init();
	mlx.window = mlx_new_window(mlx.con, WIN_X, WIN_Y, TITLE);
	if (!mlx.window)
		return (free(mlx.con), 1);
	mlx_mouse_hide(mlx.con, mlx.window);
	if (mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]) != 0)
		printf("D..Don't look at me...\n");
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
	sleep(2);
	printf("Baka!\n");
	mlx_mouse_show(mlx.con, mlx.window);
	mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]);
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
	sleep(1);
	mlx_destroy_window(mlx.con, mlx.window);
	mlx_destroy_display(mlx.con);
	free(mlx.con);
} */

//NOTE - Mouse move
//NOTE - Moves mouse data

/* int	main()
{
	t_mlx	mlx;
	int		pos[2];

	mlx = (t_mlx){0};
	mlx.con = mlx_init();
	mlx.window = mlx_new_window(mlx.con, WIN_X, WIN_Y, TITLE);
	if (!mlx.window)
		return (free(mlx.con), 1);
	sleep(2);
	mlx_mouse_move(mlx.con, mlx.window, 0, 0);
	mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]);
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
	sleep(1);
	mlx_mouse_move(mlx.con, mlx.window, 110, 220);
	mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]);
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
	sleep(1);
	mlx_mouse_move(mlx.con, mlx.window, 330, 220);
	mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]);
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
	sleep(1);
	mlx_destroy_window(mlx.con, mlx.window);
	mlx_destroy_display(mlx.con);
	free(mlx.con);
} */

//NOTE - Frame rate

/* static int	mouse(int keycode, t_mlx *mlx);
static int	keyboard(int keycode, t_mlx *mlx);
static int	loop(t_mlx *mlx);
static long	elapsed_time(t_time start);

int	main()
{
	t_mlx	mlx;
	int		pos[2];

	mlx = (t_mlx){0};
	mlx.con = mlx_init();
	mlx.window = mlx_new_window(mlx.con, WIN_X, WIN_Y, TITLE);
	if (!mlx.window)
		return (free(mlx.con), 1);
	mlx_mouse_hook(mlx.window, mouse, &mlx);
	mlx_key_hook(mlx.window, keyboard, &mlx);
	mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]);
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
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
		free(mlx->window);
		free(mlx->con);
		exit(0);
	}
	else if (keycode == XK_F1)
		mlx_do_key_autorepeatoff(mlx->con);
	else if (keycode == XK_F2)
		mlx_do_key_autorepeaton(mlx->con);
	return (0);
}

static int	mouse(int keycode, t_mlx *mlx)
{
	(void)keycode, (void)mlx;
	return (0);
}

static int	loop(t_mlx *mlx)
{

	(void)mlx;
	if (elapsed_time(mlx->start) > FRAME_RATE)
	{
		printf("Ciao\n");
		gettimeofday(&mlx->start, NULL);
	}
	return (0);
}

static long	elapsed_time(t_time start)
{
	struct timeval	tv;
	long			diff;

	gettimeofday(&tv, NULL);
	diff = (tv.tv_sec - start.tv_sec) * 1000000
		 + (tv.tv_usec - start.tv_usec);
	return (diff);
} */

//NOTE - Mouse

/* static int	mouse(int keycode, t_mlx *mlx);
static int	keyboard(int keycode, t_mlx *mlx);
static int	loop(t_mlx *mlx);
static long	elapsed_time(t_time start);

int	main()
{
	t_mlx	mlx;
	int		pos[2];

	mlx = (t_mlx){0};
	mlx.con = mlx_init();
	mlx.window = mlx_new_window(mlx.con, WIN_X, WIN_Y, TITLE);
	if (!mlx.window)
		return (free(mlx.con), 1);
	mlx_mouse_hook(mlx.window, mouse, &mlx);
	mlx_key_hook(mlx.window, keyboard, &mlx);
	mlx_mouse_get_pos(mlx.con, mlx.window, &pos[0], &pos[1]);
	printf("Mouse is:\t%d\t%d\n", pos[0], pos[1]);
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
		free(mlx->window);
		free(mlx->con);
		exit(0);
	}
	else if (keycode == XK_F1)
		mlx_do_key_autorepeatoff(mlx->con);
	else if (keycode == XK_F2)
		mlx_do_key_autorepeaton(mlx->con);
	return (0);
}

static int	mouse(int keycode, t_mlx *mlx)
{
	(void)keycode, (void)mlx;
	return (0);
}

static int	loop(t_mlx *mlx)
{
	int	pos[2];

	if (elapsed_time(mlx->start) > FRAME_RATE)
	{
		mlx_clear_window(mlx->con, mlx->window);
		mlx_mouse_get_pos(mlx->con, mlx->window, &pos[0], &pos[1]);
		printf("Mouse\tx:%d\ty:%d\t\n", pos[0], pos[1]);
		gettimeofday(&mlx->start, NULL);
	}
	return (0);
}

static long	elapsed_time(t_time start)
{
	struct timeval	tv;
	long			diff;

	gettimeofday(&tv, NULL);
	diff = (tv.tv_sec - start.tv_sec) * 1000000
		 + (tv.tv_usec - start.tv_usec);
	return (diff);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:49:23 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/21 10:29:31 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(char **map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	j = 0;
	x = 0;
	y = 0;
	find_p(map, &x, &y);
	floodfill(map, x, y);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i] != '1') && (map[j][i] != '0') && \
			(map[j][i] != 'x') && (map[j][i] != '\n'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check(t_imma *imma, int y, int x)
{
	if (!imma->map)
		return (0);
	if (imma->map[y][x] == '1')
		return (0);
	if ((imma->map[y][x] == 'E') && (imma->coll > 0))
		return (0);
	else if (imma->map[y][x] == 'E')
	{
		ft_free(imma->map);
		imma->map = NULL;
		return (0);
	}
	if ((imma->map) && (imma->map[y][x] == 'C'))
		imma->coll -= 1;
	return (1);
}

void	move_map(t_imma *imma)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	imma->sprite.look_to = imma->sprite.direction;
	find_p(imma->map, &x, &y);
	imma->map[y][x] = '0';
	if ((imma->sprite.direction == 1) && (check(imma, y - 1, x) != 0))
		imma->map[y - 1][x] = 'P';
	else if ((imma->sprite.direction == 2) && (check(imma, y, x - 1) != 0))
		imma->map[y][x - 1] = 'P';
	else if ((imma->sprite.direction == 3) && (check(imma, y + 1, x) != 0))
		imma->map[y + 1][x] = 'P';
	else if ((imma->sprite.direction == 4) && (check(imma, y, x + 1) != 0))
		imma->map[y][x + 1] = 'P';
	else if (!imma->map)
		return ;
	else 
		imma->map[y][x] = 'P';
	imma->sprite.direction = 0;
}

// int	main(void)
// {
// 	t_imma	imma;
// 	int		i;

// 	i = 0;
// 	imma.map = get_map();
// 	if (imma.map == NULL)
// 	{
// 		printf("errore");
// 		return (0);
// 	}
// 	while (imma.map[i])
// 	{
// 		printf ("%s", imma.map[i]);
// 		free (imma.map[i]);
// 		i++;
// 	}
// 	free (imma.map);
// 	return (0);
// }

int	input_control(int keysym, t_imma *imma)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window (imma->mlx_ptr, imma->win_ptr);
		mlx_destroy_display (imma->mlx_ptr);
		free (imma->mlx_ptr);
		exit(0);
	}
	if (keysym == XK_w)
		imma->sprite.direction = 1;
	if (keysym == XK_a)
		imma->sprite.direction = 2;
	if (keysym == XK_s)
		imma->sprite.direction = 3;
	if (keysym == XK_d)
		imma->sprite.direction = 4;
	move_map(imma);
	printf ("il tasto e' %d\n", keysym); //da cambiare con il mio printf
	return (0);
}

int	input_mouse_control(t_imma *imma)
{
	mlx_destroy_window (imma->mlx_ptr, imma->win_ptr);
	mlx_destroy_display (imma->mlx_ptr);
	free (imma->mlx_ptr);
	exit(0);
}

void	take_immag(t_imma *imma)
{
	int	i;

	i = 32;
	imma->sprite.link_front = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/1.xpm", &i, &i);
	imma->sprite.link_side_dx = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/2.xpm", &i, &i);
	imma->sprite.link_side_sx = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/3.xpm", &i, &i);
	imma->sprite.link_back = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/4.xpm", &i, &i);
	imma->sprite.fairy1 = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/5.xpm", &i, &i);
	imma->sprite.fairy2 = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/6.xpm", &i, &i);
	imma->sprite.zelda = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/7.xpm", &i, &i);
	imma->sprite.zelda_horny = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/8.xpm", &i, &i);
	imma->sprite.tree = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/9.xpm", &i, &i);
	imma->sprite.floor = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/10.xpm", &i, &i);
	imma->sprite.knight_front = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/11.xpm", &i, &i);
	imma->sprite.knight_back = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/12.xpm", &i, &i);
	imma->sprite.knight_dx = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/13.xpm", &i, &i);
	imma->sprite.knight_sx = mlx_xpm_file_to_image(imma->mlx_ptr, "./textures/14.xpm", &i, &i);
}

void	*look(t_imma *imma)
{
	if (imma->sprite.look_to == 3)
		return (imma->sprite.link_front);
	else if (imma->sprite.look_to == 1)
		return (imma->sprite.link_back);
	else if (imma->sprite.look_to == 2)
		return (imma->sprite.link_side_sx);
	else if (imma->sprite.look_to == 4)
		return (imma->sprite.link_side_dx);
	return (imma->sprite.link_front);
}

void	print_map(t_imma *imma)
{
	int	i;
	int	j;
	static	int count;

	j = 0;
	while (imma->map[j])
	{
		i = 0;
		while ((imma->map[j][i] != '\n') && (imma->map[j][i]))
		{
			if (imma->map[j][i] == 'P')
				mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, look(imma), (i * 32), (j * 32));
			if (imma->map[j][i] == '0')
				mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, imma->sprite.floor, (i * 32), (j * 32));
			if (imma->map[j][i] == '1')
				mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, imma->sprite.tree, (i * 32), (j * 32));
			if (imma->map[j][i] == 'C')
			{
				if (count % 200 < 100)
					mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, imma->sprite.fairy2, (i * 32), (j * 32));
				else if (count % 200 >= 100)
					mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, imma->sprite.fairy1, (i * 32), (j * 32));
			}
			if ((imma->map[j][i] =='E') && (imma->coll != 0))
				mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, imma->sprite.zelda, (i * 32), (j * 32));
			else if ((imma->map[j][i] =='E') && (imma->coll == 0))
				mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, imma->sprite.zelda_horny, (i * 32), (j * 32));
			i++;
		}
		j++;
	}
	++count;
}

void	destroy_immag(t_imma *imma)
{
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_front);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_side_dx);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_side_sx);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_back);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.fairy1);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.fairy2);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.zelda);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.zelda_horny);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.tree);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.floor);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_front);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_back);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_dx);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_sx);
}

void	destroy(t_imma *imma)
{
	destroy_immag(imma);
	mlx_destroy_window (imma->mlx_ptr, imma->win_ptr);
	mlx_destroy_display (imma->mlx_ptr);
	free (imma->mlx_ptr);
	exit(0);
}

int	game_loop(t_imma *imma)
{
	if (!imma->map)
	{
		destroy(imma);
		mlx_loop_end(imma->mlx_ptr);
	}
	print_map(imma);
	return (0);
}

int	main(void)
{
	t_imma	imma;

	imma.mlx_ptr = mlx_init();
	imma.sprite.look_to = 0;
	imma.map = get_map(&imma);
	if ((imma.mlx_ptr == NULL) && (imma.map == NULL))
		return (1);
	imma.win_ptr = mlx_new_window (imma.mlx_ptr, 1000, 500, "TloZ");
	if (imma.win_ptr == NULL)
	{
		mlx_destroy_display (imma.mlx_ptr);
		free (imma.mlx_ptr);
		return (1);
	}
	
	take_immag(&imma);
	mlx_key_hook (imma.win_ptr, input_control, &imma);
	mlx_hook (imma.win_ptr, 17, 1L << 0, input_mouse_control, &imma);
	mlx_loop_hook(imma.mlx_ptr, game_loop, &imma);
	mlx_loop (imma.mlx_ptr);
	return (0);
}

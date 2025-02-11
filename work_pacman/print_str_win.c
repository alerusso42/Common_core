/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:24:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/11 16:46:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

int		find_print_location(int layer, int *x, int *y);

static void	clean_one(t_all *all, int x, int y)
{
	void	*floor;
	int		del_loop;

	floor = all->mlx->sprite->floor;
	del_loop = 7;
	y -= 10;
	while (del_loop--)
	{
		mlx_put_image_to_window(all->mlx->con, all->mlx->window, floor, x, y);
		x += 25;
	}
}

void	print_str_win(int layer, int color, char *str, int data)
{
	int		x;
	int		y;
	char	*temp_str;
	t_all	*all;

	all = storage_structs(NULL, GET);
	if (!str)
		return ;
	if (find_print_location(layer, &x, &y) == 1)
		return ;
	clean_one(all, x, y);
	if (data != NODATA)
	{
		temp_str = ft_strjoin_free(ft_strdup(str), ft_itoa(data));
		//temp_str = ft_itoa(data);
		if (!str)
			return ;
		mlx_string_put(all->mlx->con, all->mlx->window, x, y, color, temp_str);
		free(temp_str);
		return ;
	}
	mlx_string_put(all->mlx->con, all->mlx->window, x, y, color, str);
}

/*
	0	1	2	3	4
	-	-	-	-	-
	10	11	12	13	14
	-	-	-	-	-
		--SCREEN--
	-	-	-	-	-
	20	21	22	23	24
	-	-	-	-	-
	30	31	32	33	34

	Every x is 180 pixel distant;
	Upper and lower y are 50 pixel distant.
	From the two y layer there is the game screen DISTANT???
*/
int		find_print_location(int layer, int *x, int *y)
{
	if (layer < 0)
		return (1);
	if (layer > 34)
		return (1);
	if (layer % 10 > 4)
		return (1);
	*x = layer % 10;
	*x *= 180;
	if (layer < 10)
		*y = 10;
	else if (layer < 20)
		*y = 60;
	else if (layer < 30)
		*y = 810;
	else
		*y = 860;
	return (0);
}
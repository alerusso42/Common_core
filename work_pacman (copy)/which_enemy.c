/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:52:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/10 12:15:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static void	*get_red(t_all *all, int n);
static void	*get_cian(t_all *all, int n);
static void	*get_orange(t_all *all, int n);
static void	*get_purple(t_all *all, int n);

void	*which_enemy(t_all *all, int x, int y)
{
	int	n_enemy;

	n_enemy = id_enemy(all->map, x, y);
	if (n_enemy == -1)
		return (NULL);
	if (all->map->enemy[n_enemy].color == RED)
		return (get_red(all, n_enemy));
	if (all->map->enemy[n_enemy].color == CIAN)
		return (get_cian(all, n_enemy));
	if (all->map->enemy[n_enemy].color == ORANGE)
		return (get_orange(all, n_enemy));
	if (all->map->enemy[n_enemy].color == PURPLE)
		return (get_purple(all, n_enemy));
	return (NULL);
}

static void	*get_red(t_all *all, int n)
{
	if (all->map->enemy[n].dir == FRONT)
		return (all->mlx->sprite->red_front);
	if (all->map->enemy[n].dir == RIGHT)
		return (all->mlx->sprite->red_right);
	if (all->map->enemy[n].dir == DOWN)
		return (all->mlx->sprite->red_down);
	if (all->map->enemy[n].dir == LEFT)
		return (all->mlx->sprite->red_left);
	if (all->map->enemy[n].dir == UP)
		return (all->mlx->sprite->red_up);
	return (NULL);
}

static void	*get_cian(t_all *all, int n)
{
	if (all->map->enemy[n].dir == FRONT)
		return (all->mlx->sprite->cian_front);
	if (all->map->enemy[n].dir == RIGHT)
		return (all->mlx->sprite->cian_right);
	if (all->map->enemy[n].dir == DOWN)
		return (all->mlx->sprite->cian_down);
	if (all->map->enemy[n].dir == LEFT)
		return (all->mlx->sprite->cian_left);
	if (all->map->enemy[n].dir == UP)
		return (all->mlx->sprite->cian_up);
	return (NULL);
}

static void	*get_orange(t_all *all, int n)
{
	if (all->map->enemy[n].dir == FRONT)
		return (all->mlx->sprite->orange_front);
	if (all->map->enemy[n].dir == RIGHT)
		return (all->mlx->sprite->orange_right);
	if (all->map->enemy[n].dir == DOWN)
		return (all->mlx->sprite->orange_down);
	if (all->map->enemy[n].dir == LEFT)
		return (all->mlx->sprite->orange_left);
	if (all->map->enemy[n].dir == UP)
		return (all->mlx->sprite->orange_up);
	return (NULL);
}

static void	*get_purple(t_all *all, int n)
{
	if (all->map->enemy[n].dir == FRONT)
		return (all->mlx->sprite->purple_front);
	if (all->map->enemy[n].dir == RIGHT)
		return (all->mlx->sprite->purple_right);
	if (all->map->enemy[n].dir == DOWN)
		return (all->mlx->sprite->purple_down);
	if (all->map->enemy[n].dir == LEFT)
		return (all->mlx->sprite->purple_left);
	if (all->map->enemy[n].dir == UP)
		return (all->mlx->sprite->purple_up);
	return (NULL);
}

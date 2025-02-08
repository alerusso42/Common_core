/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_algorythm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:02:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/08 17:21:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif
#define PRINT_BFS 0

static int	find_distance(t_position **position, int x, int y, int distance);
static int	process_one(t_bfs *bfs);
static int	bfs_loop(t_bfs *bfs, t_typelist *list);
static void	bfs(t_bfs *bfs);

static int	find_distance(t_position **position, int x, int y, int distance)
{
	t_typelist	*new;
	t_typelist	*list;
	int			*x_alloc;
	int			*y_alloc;
	
	if ((position[x][y].value == '1') || (position[x][y].distance != 0))
		return (2);
	x_alloc = ft_calloc(1, sizeof(int));
	if (!x_alloc)
		return (1);
	y_alloc = ft_calloc(1, sizeof(int));
	if (!y_alloc)
		return (1);
	*x_alloc = x;
	*y_alloc = y;
	new = ft_lstnew((void *)x_alloc, (void *)y_alloc);
	if (!new)
		return (free(x_alloc), free(y_alloc), 1);
	list = store_list(NULL, 1);
	if (position[x][y].distance != -1)
		position[x][y].distance = distance + 1;
	ft_lstadd_back(&list, new);
	return (0);
}

static int	process_one(t_bfs *bfs)
{
	if ((bfs->x == bfs->p_x) && (bfs->y == bfs->p_y))
	{
		return (2);
	}
	if (find_distance(bfs->position, bfs->x + 1, bfs->y, bfs->distance) == 1)
		return (1);
	if (find_distance(bfs->position, bfs->x - 1, bfs->y, bfs->distance) == 1)
		return (1);
	if (find_distance(bfs->position, bfs->x, bfs->y + 1, bfs->distance) == 1)
		return (1);
	if (find_distance(bfs->position, bfs->x, bfs->y - 1, bfs->distance) == 1)
		return (1);
	return (0);
}

static int	bfs_loop(t_bfs *bfs, t_typelist *list)
{
	int	*x;
	int	*y;

	while (list)
	{
		x = (int *)list->content;
		y = (int *)list->type;
		bfs->x = *x;
		bfs->y = *y;
		bfs->distance = bfs->position[bfs->x][bfs->y].distance[bfs->n];
		if (bfs->distance == -1)
			bfs->distance = 0;
		if (process_one(bfs) != 0)
			return (1);
		list = list->next;
	}
	return (0);
}

static void	bfs(t_bfs *bfs)
{
	t_typelist		*list;
	t_typelist		*tail;
	int				*x;
	int				*y;

	bfs->position[bfs->en_x][bfs->en_y].distance[bfs->n] = -1;
	x = ft_calloc(1, sizeof(int));
	if (!x)
		return ;
	y = ft_calloc(1, sizeof(int));
	if (!y)
		return ;
	*x = bfs->en_x;
	*y = bfs->en_y;
	bfs->x = *x;
	bfs->y = *y;
	list = ft_lstnew((void *)x, (void *)y);
	if (!list)
		return (free(x), free(y));
	tail = list;
	store_list(list, 0);
	bfs_loop(bfs, list);
	ft_lstclear(&tail, del_free);
}

int	get_best_path(t_map *map, int enemy_num)
{
	t_bfs	bfs_stuff;
	int		is_valid_path;

	clean_bfs(map);
	bfs_stuff.en_x = map->enemy[enemy_num].x;
	bfs_stuff.en_y = map->enemy[enemy_num].y;
	bfs_stuff.p_x = map->p_x;
	bfs_stuff.p_y = map->p_y;
	bfs_stuff.position = map->position;
	bfs_stuff.map_x = map->game_size_w;
	bfs_stuff.map_y = map->game_size_h;
	bfs_stuff.n = enemy_num;
	bfs(&bfs_stuff);
	is_valid_path = draw_path(&bfs_stuff);
	if (is_valid_path == NO)
		return (2);
	return (0);
}

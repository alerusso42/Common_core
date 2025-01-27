/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:02:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 04:10:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"
#define MAP_X 400
#define MAP_Y 400
#define PRINT 0
#define WALL 3

int	en_x;
int	en_y;
int	p_x;
int	p_y;

void	set_entity(t_position position[MAP_X][MAP_Y], char e)
{
	int	x;
	int	y;

	while ("loop")
	{
		x = rand();
		y = rand();
		if (position[x % MAP_X][y % MAP_Y].value != '1')
		{
			position[x % MAP_X][y % MAP_Y].value = e;
			break ;
		}
	}
}

void	initialize_center(t_position position[MAP_X][MAP_Y])
{
	int	x;
	int	y;
	int	random;

	x = 0;
	y = 1;
	while ((++x) || (1))
	{
		if (x == MAP_X - 1)
		{
			if (y == MAP_Y - 1)
				break ;
			y++;
			x = 1;
		}
		random = rand();
		if (random % WALL == 0)
			position[x][y].value = '1';
		else
			position[x][y].value = '0';
		position[x][y].distance = 0;
	}
}

void	set_to_zero(t_position position[MAP_X][MAP_Y])
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y != MAP_Y + 1)
	{
		x = -1;
		while (++x != MAP_X + 1)
		{
			position[x][y].value = '1';
			position[x][y].distance = 0;
		}
	}
}

void	initialize_map(t_position position[MAP_X][MAP_Y])
{
	int			x;
	int			y;

	x = -1;
	y = 0;
	set_to_zero(position);
	while ((++x) || (1))
	{
		if (x == MAP_X - 1)
		{
			if (y == MAP_Y - 1)
				break ;
			y = MAP_Y - 1;
			x = 0;
		}
		position[x][y].value = '1';
		position[x][y].distance = 0;
	}
	y = -1;
	x = 0;
	while ((++y) || (1))
	{
		if (y == MAP_Y)
		{
			if (x == MAP_X - 1)
				break ;
			x = MAP_X - 1;
			y = 0;
		}
		position[x][y].value = '1';
		position[x][y].distance = 0;
	}
	position[MAP_X - 1][MAP_Y - 1].value = '1';
	position[MAP_X - 1][MAP_Y - 1].distance = 0;
	initialize_center(position);
}

void	get_pos(t_position position[MAP_X][MAP_Y])
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while ((++x) || (1))
	{
		if (x == MAP_X - 1)
		{
			if (y == MAP_Y - 1)
				break ;
			y++;
			x = 1;
		}
		if (position[x][y].value == 'P')
		{
			p_x = x;
			p_y = y;
		}
		if (position[x][y].value == '$')
		{
			en_x = x;
			en_y = y;
		}
	}
}

void	print(t_position position[MAP_X][MAP_Y])
{
	int	x;
	int	y;
	char	c;

	x = -1;
	y = 0;
	printf("\nMap values: \n y = %d:\n", y);
	while ((++x) || (1))
	{
		if (x == MAP_X)
		{
			printf("\ny= %d:\n", y);
			if (y == MAP_Y)
				break ;
			y++;
			x = 0;
		}
		c = position[x][y].value;
		if (c == '0')
			printf("\033[1;37m%c\033[0m | ", c);
		else if (c == '1')
			printf("\033[1;35m%c\033[0m | ", c);
		else if (c == '$')
			printf("\033[1;31m%c\033[0m | ", c);
		else
			printf("\033[1;32m%c\033[0m | ", c);
		//\033[1;31mThis is red text\033[0m
	}
	x = 0;
	y = 0;
	printf("\n\n\nMap distances: \n\n");
	while ((++x) || (1))
	{
		if (x == MAP_X)
		{
			printf("\n\n");
			if (y == MAP_Y)
				break ;
			y++;
			x = 0;
		}
		if (position[x][y].distance == -1)
			printf("\033[1;33m%2d\033[0m | ", position[x][y].distance);
		else if (position[x][y].distance == -2)
			printf("\033[1;31m%2d\033[0m | ", position[x][y].distance);
		else if (position[x][y].distance == -3)
			printf("\033[1;32m%2d\033[0m | ", position[x][y].distance);
		else
			printf("%2d | ", position[x][y].distance);
	}
}

void	del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

//////////////////////////////////////////////

t_typelist	*store_list(t_typelist *list, int mode)
{
	static t_typelist	*store_list;
	
	if (mode == 0)
	{
		store_list = list;
		return (NULL);
	}
	return (store_list);
}

int	find_distance(t_position position[MAP_X][MAP_Y], int x, int y, int distance)
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

int	process_one(t_position position[MAP_X][MAP_Y], int x, int y, int distance)
{
	if ((x == p_x) && (y == p_y))
	{
		return (2);
	}
	if (find_distance(position, x + 1, y, distance) == 1)
		return (1);
	if (find_distance(position, x - 1, y, distance) == 1)
		return (1);
	if (find_distance(position, x, y + 1, distance) == 1)
		return (1);
	if (find_distance(position, x, y - 1, distance) == 1)
		return (1);
	return (0);
}

void	bfs(t_position position[MAP_X][MAP_Y])
{
	t_typelist	*list;
	t_typelist	*tail;
	int			distance;
	int			*x;
	int			*y;

	position[en_x][en_y].distance = -1;
	x = ft_calloc(1, sizeof(int));
	if (!x)
		return ;
	y = ft_calloc(1, sizeof(int));
	if (!y)
		return ;
	*x = en_x;
	*y = en_y;
	list = ft_lstnew((void *)x, (void *)y);
	if (!list)
		return (free(x), free(y));
	tail = list;
	store_list(list, 0);
	while (list)
	{
		x = (int *)list->content;
		y = (int *)list->type;
		distance = position[*x][*y].distance;
		if (distance == -1)
			distance = 0;
		if (process_one(position, *x, *y, distance) != 0)
			return (ft_lstclear(&tail, del));
		if (PRINT == 3)
			print(position);
		list = list->next;
	}
	ft_lstclear(&tail, del);
}

int	find_shortest_route(t_position position[MAP_X][MAP_Y], int x, int y)
{
	int	record;

	record = 2000000;
	if (position[x + 1][y].distance > 0)
		record = position[x + 1][y].distance;
	if ((position[x - 1][y].distance > 0) && \
	(position[x - 1][y].distance < record))
		record = position[x - 1][y].distance;
	if ((position[x][y + 1].distance > 0) && \
	(position[x][y + 1].distance < record))
		record = position[x][y + 1].distance;
	if ((position[x][y - 1].distance > 0) && \
	(position[x][y - 1].distance < record))
		record = position[x][y - 1].distance;
	if (record == position[x + 1][y].distance)
		return (1);
	if (record == position[x - 1][y].distance)
		return (2);
	if (record == position[x][y + 1].distance)
		return (3);
	if (record == position[x][y - 1].distance)
		return (4);
	return (-1);
}
/*		*/

int		found_end(int x, int y, int stop_x, int stop_y)
{
	if ((x + 1 == stop_x) && (y == stop_y))
		return (1);
	if ((x - 1 == stop_x) && (y == stop_y))
		return (1);
	if ((x == stop_x) && (y + 1 == stop_y))
		return (1);
	if ((x == stop_x) && (y - 1 == stop_y))
		return (1);
	return (0);
}

void	update_one(t_position position[MAP_X][MAP_Y], int *x, int *y, int rec)
{
		if (rec == 1)
		{
			position[*x + 1][*y].distance = -1;
			(*x)++;
		}
		if (rec == 2)
		{
			position[*x - 1][*y].distance = -1;
			(*x)--;
		}
		if (rec == 3)
		{
			position[*x][*y + 1].distance = -1;
			(*y)++;
		}
		if (rec == 4)
		{
			position[*x][*y - 1].distance = -1;
			(*y)--;
		}
}

void	normalize_path(t_position position[MAP_X][MAP_Y])
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y != MAP_Y + 1)
	{
		x = -1;
		while (++x != MAP_X + 1)
		{
			if (position[x][y].distance > 0)
				position[x][y].distance = 0;
		}
	}
}

int	draw_path(t_position position[MAP_X][MAP_Y])
{
	int	x;
	int	y;
	int	stop_x;
	int	stop_y;
	int	record;

	x = p_x;
	y = p_y;
	stop_x = en_x;
	stop_y = en_y;
	position[x][y].distance = -3;
	if (find_shortest_route(position, x, y) == -1)
	{
		return (normalize_path(position), NO);
	}
	while ((x != stop_x) || (y != stop_y))
	{
		if (found_end(x, y, stop_x, stop_y) == YES)
		{
			position[en_x][en_y].distance = -2;
			break ;
		}
		record = find_shortest_route(position, x, y);
		update_one(position, &x, &y, record);
		if (PRINT >= 4)
			print(position);
	}
	return (normalize_path(position), YES);
}

int	main()
{
	t_position	position[MAP_X][MAP_Y];
	int			is_valid_path;

	if (WALL <= 1)
		return (printf("\nWALL deve essere minimo 2\n"));
	initialize_map(position);
	set_entity(position, 'P');
	set_entity(position, '$');
	if (PRINT >= 2)
		print(position);
	get_pos(position);/*
	position[en_x + 1][en_y].value = '1';
	position[en_x - 1][en_y].value = '1';
	position[en_x][en_y + 1].value = '1';
	position[en_x][en_y - 1].value = '1';*/
	bfs(position);
	if (PRINT >= 2)
		print(position);
	is_valid_path = draw_path(position);
	if (PRINT >= 1)
		print(position);
	if (is_valid_path == YES)
		printf("\n\nTrovato un path valido!\n");
	if (is_valid_path == NO)
		printf("\n\nNessun path valido!\n");
	exit(0);
}

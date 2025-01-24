/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/24 14:36:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int				full_reset(int struct_num, ...);
static int		reset_memory_input(t_input **input);
static int		reset_memory_sol(t_map **map, int game_size[2], int index);
static int		reset_memory_randlist(t_random **random);
static int		reset_memory_mlx(t_mlx **mlx);

/* 	La funzione variadica full_reset accetta come argomento il numero
	di strutture che vuoi liberare, e le strutture stesse.
	Resetta sempre nell'ordine input, map, random, mlx:
	Perciò se volessi modificare il programma, presta molta attenzione
	a questo dettaglio, per evitare sgradite sorprese.
*/
int	full_reset(int struct_num, ...)
{
	va_list		ptr;
	void		*data_to_free;
	t_input		**input;
	int			game_size[2];

	va_start(ptr, struct_num);
	data_to_free = va_arg(ptr, t_input **);
	if (!data_to_free)
		return (va_end(ptr), 1);
	input = (t_input **)data_to_free;
	game_size[0] = (*input)->game_size_w;
	game_size[1] = (*input)->game_size_h;
	reset_memory_input(input);
	if (struct_num < 2)
		return (va_end(ptr), 1);
	data_to_free = va_arg(ptr, t_map **);
	reset_memory_sol((t_map **)data_to_free, game_size, 0);
	if (struct_num < 3)
		return (va_end(ptr), 2);
	data_to_free = va_arg(ptr, t_random **);
	reset_memory_randlist((t_random **)data_to_free);
	if (struct_num < 4)
		return (va_end(ptr), 3);
	data_to_free = va_arg(ptr, t_mlx **);
	return (reset_memory_mlx((t_mlx **)data_to_free), va_end(ptr), 4);
}

static int	reset_memory_input(t_input **input)
{
	if ((*input) != NULL)
	{
		if ((*input)->col.x != NULL)
			free((*input)->col.x);
		if ((*input)->row.y != NULL)
			free((*input)->row.y);
		(*input)->col.x = NULL;
		(*input)->row.y = NULL;
		free((*input)->filename);
		(*input)->filename = NULL;
		free((*input));
		(*input) = NULL;
	}
	return (0);
}

static int	reset_memory_sol(t_map **map, int game_size[2], int index)
{
	t_map	*p;

	index = 0;
	p = (*map);
	if (!p)
		return (1);
	while ((p->position) && (p->position[index]) && (index <= game_size[0]))
	{
		free(p->position[index]);
		p->position[index++] = NULL;
	}
	index = 0;
	while ((p->old_pos) && (p->old_pos[index]) && (index <= game_size[0]))
	{
		free(p->old_pos[index]);
		p->old_pos[index++] = NULL;
	}
	free(p->position);
	p->position = NULL;
	free(p->old_pos);
	p->old_pos = NULL;
	free(p);
	p = NULL;
	return (0);
}

static int	reset_memory_randlist(t_random **random)
{
	if (!*random)
		return (0);
	if ((*random)->values != NULL)
	{
		free((*random)->values);
		(*random)->values = NULL;
	}
	if ((*random) != NULL)
	{
		free(*random);
		*random = NULL;
	}
	return (0);
}

static int	reset_memory_mlx(t_mlx **mlx)
{
	if (!*mlx)
		return (0);
	if ((*mlx)->sprite)
	{
		reset_pic(*mlx);
		free((*mlx)->sprite);
		(*mlx)->sprite = NULL;
	}
	if ((*mlx)->window)
	{
		mlx_destroy_window((*mlx)->con, (*mlx)->window);
		(*mlx)->window = NULL;
	}
	if ((*mlx)->con)
	{
		mlx_destroy_display((*mlx)->con);
		free((*mlx)->con);
		(*mlx)->con = NULL;
	}
	free(*mlx);
	*mlx = NULL;
	return (0);
}

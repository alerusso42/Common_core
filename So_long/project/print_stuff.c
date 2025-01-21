/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:20:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 14:42:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

void	print_map(t_input *input, t_map *map, int x, int y);
void	print_colgraphic(t_input *input, t_bool mode);
void	print_skyscrapers(t_onebyte game_size);
void	print_blacklist(t_onebyte game_size, t_map *map, int i);

// "s" sta per game_size.
/*	Printa la scacchiera.
	Questa funzione non la spiego, è molto più divertente collegare
	i pezzi del codice con la scacchiera.
*/
void	print_map(t_input *input, t_map *map, int x, int y)
{
	int	w;
	int	h;

	x = -1;
	y = -1;
	w = input->game_size_w;
	h = input->game_size_h;
	print_skyscrapers(w);
	print_colgraphic(input, 0);
	write(1, " ", 1);
	while (++x != w)
		l_printf("<%d>", input->col.x[x]);
	print_colgraphic(input, 1);
	while (++y != h)
	{
		l_printf("\n     [%d]", h - y - 1);
		if ((h - y - 1) < 10)
			write(1, " ", 1);
		l_printf("<%d>", input->row.y[h - y - 1]);
		if ((h - y - 1) < 100)
			write(1, " ", 1);
		x = -1;
		while (++x != w)
			l_printf("|%c|", map->position[x][h - y - 1].value);
		l_printf("<%d> [%d]", input->row.y[h - y - 1], h - y - 1);
	}
	print_colgraphic(input, 1);
	l_printf("            ");
	x = -1;
	write(1, " ", 1);
	while (++x != w)
		l_printf("<%d>", input->col.x[x]);
	print_colgraphic(input, 0);
}

void	print_colgraphic(t_input *input, t_bool mode)
{
	int			x;
	t_onebyte	game_size;

	x = -1;
	game_size = input->game_size_w;
	if (mode == 0)
	{
		l_printf("\n");
		l_printf("            ");
		x = -1;
		write(1, " ", 1);
		while (++x != game_size)
		{
			if (x < 100)
				write(1, "[", 1);
			l_printf("%d", x);
			if (x < 10)
				write(1, "]", 1);
		}
		l_printf("\n");
		l_printf("            ");
	}
	if (mode == 1)
	{
		l_printf("\n");
		l_printf("            ");
		x = -1;
		while (++x != game_size)
			l_printf("____");
		l_printf("\n");
	}
}

/* 	Inserisce spazi in base alla grandezza della scacchiera, per poi
	scrivere il titolo.
*/
void	print_skyscrapers(t_onebyte game_size)
{
	int	count_padding;

	l_printf("\n");
	count_padding = 0;
	while (++count_padding != game_size)
		l_printf("-");
	l_printf("--- ");
	l_printf("P   A   C - M   A   N");
	l_printf(" ---");
	count_padding = 0;
	while (++count_padding != game_size)
		l_printf("-");
	l_printf("\n");
}

/* 	Print della blacklist.
*/
/*
void	print_blacklist(t_onebyte game_size, t_map *map, int i)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	l_printf("\nELENCO DEI REGISTRI BLACKLIST PER OGNI POSIZIONE:");
	while (++y != game_size)
	{
		while (++x != game_size)
		{
			l_printf("\n{%d}", map->position[x][y].value);
			l_printf("\n V.S. map->position[%d][%d]: ", x, y);
			while (map->position[x][y].black_list[++i] != 102)
				l_printf("%d, ", map->position[x][y].black_list[i]);
			l_printf("102.\n V.T. map->position[%d][%d]: 102, ", x, y);
			while (map->position[x][y].black_list[++i] != 103)
				if (map->position[x][y].black_list[i] != 102)
					l_printf("%d, ", map->position[x][y].black_list[i]);
			l_printf("103.\nUncertain score: ");
			l_printf("%d\n---->", map->position[x][y].u_score);
			i = -1;
		}
		x = -1;
	}
}*/

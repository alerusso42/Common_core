/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:20:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 12:18:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

void	print_map(t_map *map);
void	print_colgraphic(t_map *map, t_bool mode);
void	print_blacklist(t_onebyte game_size, t_map *map, int i);
void	print_skyscrapers(t_onebyte game_size);

void	print_map(t_map *map)
{
	(void)map;
	l_printf("Print on the terminal removed due to norminette\n\n");
}

// "s" sta per game_size. Printa la scacchiera.
/*
void	print_map(t_map *map)
{
	int	w;
	int	h;
	int	x;
	int	y;

	x = -1;
	y = -1;
	w = map->game_size_w;
	h = map->game_size_h;
	print_skyscrapers(w);
	print_colgraphic(map, 0);
	write(1, " ", 1);
	print_colgraphic(map, 1);
	while (++y != h)
	{
		l_printf("\n     [%d]", h - y - 1);
		if ((h - y - 1) < 10)
			write(1, " ", 1);
		if ((h - y - 1) < 100)
			write(1, " ", 1);
		x = -1;
		while (++x != w)
			l_printf("|%c|", map->position[x][h - y - 1].value);
		l_printf(" [%d]", h - y - 1);
	}
	print_colgraphic(map, 1);
	l_printf("            ");
	x = -1;
	write(1, " ", 1);
	print_colgraphic(map, 0);
}

void	print_colgraphic(t_map *map, t_bool mode)
{
	int			x;
	t_onebyte	game_size;

	x = -1;
	game_size = map->game_size_w;
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

//	Inserisce spazi in base alla grandezza della scacchiera, per poi
//	scrivere il titolo.
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
*/

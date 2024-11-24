/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:20:15 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 12:14:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STUFF_H
# define PRINT_STUFF_H
# include "ft_printf.h"

void	print_solution(t_input *input, t_solution *solution, int x, int y);
void	print_colgraphic(t_input *input, t_bool mode);
void	print_skyscrapers(t_onebyte game_size);
void	print_blacklist(t_onebyte game_size, t_solution *solution, int i);

// "s" sta per game_size.
/*	Printa la scacchiera.
	Questa funzione non la spiego, è molto più divertente collegare
	i pezzi del codice con la scacchiera.
*/
void	print_solution(t_input *input, t_solution *solution, int x, int y)
{
	t_onebyte	s;

	x = -1;
	y = -1;
	s = input->game_size;
	print_skyscrapers(s);
	print_colgraphic(input, 0);
	while (++x != s)
		ft_printf(" <%d>", input->colup.x[x]);
	print_colgraphic(input, 1);
	while (++y != s)
	{
		ft_printf("\n     [%d] <%d>", s - y - 1, input->rowleft.y[s - y - 1]);
		x = -1;
		while (++x != s)
			ft_printf(" |%d|", solution->position[x][s - y - 1].value);
		ft_printf(" <%d> [%d]", input->rowright.y[s - y - 1], s - y - 1);
	}
	print_colgraphic(input, 1);
	ft_printf("            ");
	x = -1;
	while (++x != s)
		ft_printf(" <%d>", input->coldown.x[x]);
	print_colgraphic(input, 0);
}

void	print_colgraphic(t_input *input, t_bool mode)
{
	int			x;
	t_onebyte	game_size;

	x = -1;
	game_size = input->game_size;
	if (mode == 0)
	{
		ft_printf("\n");
		ft_printf("            ");
		x = -1;
		while (++x != game_size)
			ft_printf(" [%d]", x);
		ft_printf("\n");
		ft_printf("            ");
	}
	if (mode == 1)
	{
		ft_printf("\n");
		ft_printf("            ");
		x = -1;
		while (++x != game_size)
			ft_printf("____");
		ft_printf("\n");
	}
}

/* 	Inserisce spazi in base alla grandezza della scacchiera, per poi
	scrivere il titolo.
*/
void	print_skyscrapers(t_onebyte game_size)
{
	int	count_padding;

	ft_printf("\n");
	count_padding = 0;
	while (++count_padding != game_size)
		ft_printf("--");
	ft_printf("---- ");
	ft_printf("S K Y S C R A P E R S");
	ft_printf(" ----");
	count_padding = 0;
	while (++count_padding != game_size)
		ft_printf("--");
	ft_printf("\n");
}

/* 	Print della blacklist.
*/
void	print_blacklist(t_onebyte game_size, t_solution *solution, int i)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	ft_printf("\nELENCO DEI REGISTRI BLACKLIST PER OGNI POSIZIONE:");
	while (++y != game_size)
	{
		while (++x != game_size)
		{
			ft_printf("\n{%d}", solution->position[x][y].value);
			ft_printf("\n V.S. solution->position[%d][%d]: ", x, y);
			while (solution->position[x][y].black_list[++i] != 102)
				ft_printf("%d, ", solution->position[x][y].black_list[i]);
			ft_printf("102.\n V.T. solution->position[%d][%d]: 102, ", x, y);
			while (solution->position[x][y].black_list[++i] != 103)
				if (solution->position[x][y].black_list[i] != 102)
					ft_printf("%d, ", solution->position[x][y].black_list[i]);
			ft_printf("103.\nUncertain score: ");
			ft_printf("%d\n---->", solution->position[x][y].u_score);
			i = -1;
		}
		x = -1;
	}
	ft_printf("\nG_Uncertain_score : %d\n", solution->g_u_score);
}

#endif
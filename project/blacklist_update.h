/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blacklist_update.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:44:43 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/04 21:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLACKLIST_UPDATE_H
# define BLACKLIST_UPDATE_H
# include "types.h"

void	upbl_sure(t_solution **solution, int x, int y, t_onebyte val);
void	upbl_temp(t_solution **solution, int x, int y, t_onebyte val);
void	update_uncertainscore(t_solution **solution);
void	reset_blacklist_temp(t_solution **solution, int b_index, int x, int y);

// up_blist(solution, x, y, val);
// val è il numero da aggiungere alla black_list.
// Richiesta al sistema: "alla posizione x/y della scacchiera, esegui una
//						  operazione relativa alla blacklist."
// update_blacklist_sure: aggiorna la lista dei valori sicuri di 
//				      black_list(V.S), e inserisci val.
//					  
// update_blacklist_temp: aggiorna la lista dei valori temporanei di
//			          black_list(V.S), e inserisci val.
// update_uncertainscore: conta, considerando anche i valori
//						  della black_list sicuri, quanti sono i
//						  valori legali.
// reset_blacklist_temp: resetta i valori temporanei della
//						 black_list.
void	upbl_sure(t_solution **solution, int x, int y, t_onebyte val)
{
	t_onebyte	gs;

	gs = (*solution)->game_size;
	if ((*solution)->position[x][y].black_list[val] == 0)
	{
		(*solution)->position[x][y].black_list[val] = val;
		if ((*solution)->position[x][y].black_list[val + (gs + 1)] == 0)
			(*solution)->position[x][y].u_score -= 1;
	}
}

void	upbl_temp(t_solution **solution, int x, int y, t_onebyte val)
{
	t_onebyte	game_size;

	game_size = (*solution)->game_size;
	if ((*solution)->position[x][y].black_list[val + (game_size + 1)] == 0)
	{
		(*solution)->position[x][y].black_list[val + (game_size + 1)] = val;
		if ((*solution)->position[x][y].black_list[val] == 0)
			(*solution)->position[x][y].u_score -= 1;
	}
}

void	update_uncertainscore(t_solution **solution)
{
	t_onebyte	g_uncertain_score;
	int			x;
	int			y;

	(*solution)->g_u_score = (*solution)->game_size;
	g_uncertain_score = (*solution)->g_u_score;
	x = -1;
	y = -1;
	while (++y != (*solution)->game_size)
	{
		while (++x != (*solution)->game_size)
		{
			if (((*solution)->position[x][y].u_score < g_uncertain_score)
			&& ((*solution)->position[x][y].value == 0))
				g_uncertain_score = (*solution)->position[x][y].u_score;
		}
		x = -1;
	}
	(*solution)->g_u_score = g_uncertain_score;
}

void	reset_blacklist_temp(t_solution **solution, int t_index, int x, int y)
{
	t_onebyte	s_index;

	s_index = 0;
	while ((*solution)->position[x][y].black_list[++t_index] != 103)
	{
		++s_index;
		if ((*solution)->position[x][y].black_list[t_index] != 0)
		{
			(*solution)->position[x][y].black_list[t_index] = 0;
			if ((*solution)->position[x][y].black_list[s_index] == 0)
				(*solution)->position[x][y].u_score += 1;
		}
	}
}

#endif
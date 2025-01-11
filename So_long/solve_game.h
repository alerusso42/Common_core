/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:37:11 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 18:32:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_GAME_H
# define SOLVE_GAME_H
# include "ft_printf.h"
# include "types.h"
# include "print_stuff.h"
# include "solve_logic.h"
# include "solve_logic2.h"
# include "solve_control.h"
# include "solve_tries.h"

void	solve_game(t_input **input, t_solution **solution, t_random *random);
void	solve_game2(t_solution **solution, t_random *random, int *cycles);
void	clear_unsurevalues(t_solution **solution, t_onebyte game_size);
void	insertnum_sure(t_solution **solution, int x, int y, t_onebyte num);
void	insertnum_temp(t_solution **solution, int x, int y, t_onebyte num);

/* 	Spiegazione dell'algoritmo:
	1) 	Prima di tutto cerchiamo di estrapolare regole logiche sempre
		vere, che vadano a popolare la parte sicura e costante della
		black_list e a fissare i valori obbligatori (linea );
	2) 	Finchè tutte le caselle sono riempite (is_solved == YES) e
		lo schema è verificato (is_correct == YES), l'algoritmo
		continua a sfornare tentativi.
		Viene fermato quando sfora il limite di tentativi, definiti
		dalla variabile (*solution)->variable_1_settriesnum,
		modificabile nel file variables.h.
		Di default i tentativi sono fissati a 10000, perchè in genere
		oltre quel valore i tentativi iniziano ad essere ripetitivi.
		Linea .
	3)	Prima di iniziare, setta a 0 i valori temporanei della
		black_list, e calcola quanti sono i valori legali di ogni
		casella (linee ).
	4)	Inizia un tentativo di risoluzione. Ho chiamato la funzione
		cycle e non tries, perchè tries mi suona incredibilmente male.
		Linea ;
	5)	Ogni tanto cambia i valori randomici (linea ).
	6)	Verifica la soluzione. Vedi file solve_control.h (linea ).
*/
void	solve_game(t_input **input, t_solution **solution, t_random *random)
{
	int		tries;
	int		limit_tries;
	int		cycles;

	tries = 0;
	cycles = 0;
	limit_tries = (*solution)->variable_1_settriesnum;
	while (!(((*solution)->is_solved == YES)
			&& ((*solution)->is_correct == YES)) && (++tries != limit_tries))
	{
		if ((tries % 4 == 0) || (random->variable_2_randomizer > 1))
			twist_random2(&random);
		if (tries % 7 == 0)
			twist_random3(&random);
		solve_game2(solution, random, &cycles);
		if ((*solution)->switch_2_showcycles == ON)
			ft_printf("Tentativo %d: finito dopo %d cicli;\n", tries, cycles);
		cycles = 0;
		if ((*solution)->is_solved == YES)
			(*solution)->is_correct = check_sol(*input, *solution);
		if (random->variable_2_randomizer == 0)
			break ;
	}
	if ((*solution)->switch_1_showtries == ON)
		ft_printf("TENTATIVI EFFETTUATI: %d\n", tries);
}

void	solve_game2(t_solution **solution, t_random *random, int *cycles)
{
	clear_unsurevalues(solution, (*solution)->game_size);
	update_uncertainscore(solution);
	(*solution)->is_solved = cycle(solution, &random, cycles);
	if ((*solution)->is_solved == NO_RANDOM)
		(*solution)->is_solved = YES;
}

void	clear_unsurevalues(t_solution **solution, t_onebyte game_size)
{
	int			col;
	int			row;
	t_onebyte	counter;

	row = -1;
	col = -1;
	counter = game_size + 1;
	while ((++row != game_size + 1))
	{
		while ((++col != game_size + 1))
		{
			if ((*solution)->position[col][row].is_sure == 0)
				if ((*solution)->position[col][row].value != 0)
					(*solution)->position[col][row].value = 0;
			reset_blacklist_temp(solution, counter, col, row);
			counter = game_size + 1;
		}
		col = -1;
	}
}

void	insertnum_sure(t_solution **solution, int x, int y, t_onebyte num)
{
	int	temp_x;
	int	temp_y;

	temp_x = x;
	temp_y = y;
	(*solution)->position[x][y].value = num;
	while (--temp_y != -1)
		upbl_sure(solution, x, temp_y, num);
	temp_y = y;
	while (++temp_y != (*solution)->game_size)
		upbl_sure(solution, x, temp_y, num);
	while (++temp_x != (*solution)->game_size)
		upbl_sure(solution, temp_x, y, num);
	temp_x = x;
	while (--temp_x != -1)
		upbl_sure(solution, temp_x, y, num);
}

void	insertnum_temp(t_solution **solution, int x, int y, t_onebyte num)
{
	int	temp_x;
	int	temp_y;

	temp_x = x;
	temp_y = y;
	(*solution)->position[x][y].value = num;
	while (--temp_y != -1)
		upbl_temp(solution, x, temp_y, num);
	temp_y = y;
	while (++temp_y != (*solution)->game_size)
		upbl_temp(solution, x, temp_y, num);
	while (++temp_x != (*solution)->game_size)
		upbl_temp(solution, temp_x, y, num);
	temp_x = x;
	while (--temp_x != -1)
		upbl_temp(solution, temp_x, y, num);
}

#endif
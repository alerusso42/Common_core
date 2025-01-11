/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 18:23:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H
# include "general_ft.h"
# include "types.h"

t_bool	variables(t_input **input, t_solution **solution, t_random **random);
void	update_var(t_solution **solution, t_random **random);

// Siccome importiamo anche input,
// impostiamo una switch inutile per
// zittire le flags.
// variable_2_randomizer aumenta o diminuisce il ricorso a numeri casuali.
// randomizer == 0 non vengono mai usati valori casuali;
// randomizer == 1 vengono usati solo una volta, dopo un ciclo senza modifiche;
// randomizer == 2 come 1, ma i numeri casuali cambiano ad ogni tentativo;
// randomizer == 3 si usano solo valori random.
// in genere, il programma è più efficace ed efficiente con randomizer == 1.
t_bool	variables(t_input **input, t_solution **solution, t_random **random)
{
	(*input)->variable_0_shutupcompiler = ON;
	(*solution)->variable_1_settriesnum = 0;
	(*random)->variable_1_setseed = 0;
	(*random)->variable_2_randomizer = 1;
	update_var(solution, random);
	return (0);
}

void	update_var(t_solution **solution, t_random **random)
{
	if ((*solution)->variable_1_settriesnum == 0)
		(*solution)->variable_1_settriesnum = 10000;
	if ((*random)->variable_1_setseed != 0)
		(*random)->seed = (*random)->variable_1_setseed;
}

#endif

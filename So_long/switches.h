/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 18:06:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWITCHES_H
# define SWITCHES_H
# include "types.h"

t_bool	switches(t_input **input, t_solution **solution, t_random **random);

// Forzando is_solved e is_correct, si fa terminare i tentativi
// prima del previsto.
t_bool	switches(t_input **input, t_solution **solution, t_random **random)
{
	(*input)->switch_1_showuserinput = OFF;
	(*input)->switch_2_ispossibletowin = ON;
	(*solution)->is_solved = NO;
	(*solution)->is_correct = NO;
	(*solution)->switch_1_showtries = ON;
	(*solution)->switch_2_showcycles = ON;
	(*solution)->switch_3_showblacklist = OFF;
	(*random)->switch_1_showseed = OFF;
	(*random)->switch_2_showrandomvalues = OFF;
	return (0);
}

#endif

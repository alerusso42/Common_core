/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possibletowin.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:52:08 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 18:31:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_POSSIBLETOWIN_H
# define IS_POSSIBLETOWIN_H
# include "types.h"
# include "general_ft.h"
# include "ft_printf.h"
# include "is_possibletowin2.h"

int		is_possibletowin(t_input *input);
int		check_cols(t_input *input, t_onebyte is_even);
int		check_rows(t_input *input, t_onebyte is_even);
void	cols_error(int index, t_input *input, int *error_found, int condition);
void	rows_error(int index, t_input *input, int *error_found, int condition);

// In skyscraper, le coppie di valori nelle parti opposte
// delle colonne e delle righe devono rispettare alcune
// condizioni di esistenza: se queste condizioni non
// si verificano in almeno una coppia, non esistono
// soluzioni. Esempio:
//		1	2
//	2			1
//	1			2
//		2	1	
// Le coppie sono 4: rowleft.y[0] - rowright.y[0] (2 - 1);
//					 rowleft.y[1] - rowright.y[1] (1 - 2);
//					 colup.x[0]   - coldown.x[0]  (1 - 2);
//					 colup.x[1]   - coldown.x[1]  (2 - 1).
// Le condizioni di esistenza possono essere, in base ai casi:
// 1) MIN_VALUE implica non MIN_VALUE;
// 2) MAX_VALUE implica MIN_VALUE;
// 3) Se un valore ad un angolo è == MIN_VALUE, anche
//	  l'angolo adiacente deve essere MIN_VALUE;
// 4) È sempre falso che VALUE_1 + VALUE_2 >= game_size + 3;
// 5) È sempre falso che VALUE_1 + VALUE_2 >= game_size + 2.
// 6) Nella in colup, coldown, rowleft, rowright può esserci
// 	  Uno e un solo 1.
// 
// Ci sono diversi casi, in base al valore di game_size.
// Escludendo i casi in cui game_size <= 0, che non hanno senso,
// Si possono verificare 3 casi:
// GAME_SIZE == 1: 	  	 C'è sempre una e una sola soluzione;
// GAME_SIZE == PARI: 	 Si applicano le condizioni 1, 2, 3, 4, 6;
// GAME_SIZE == DISPARI: Si applicano le condizioni 1, 2, 3, 5, 6.
//
// Le funzioni seguenti verificano le seguenti condizioni,
// in base al valore di game_size, e printano i valori
// errati. 
int	is_possibletowin(t_input *input)
{
	t_onebyte	is_even;
	int			error_found;

	if (input->switch_2_ispossibletowin == OFF)
		return (0);
	ft_printf("\nRILEVAZIONE POSSIBILITA' VITTORIA: ");
	if (input->game_size == 1)
	{
		ft_printf("Lol\n");
		return (0);
	}
	if (input->game_size % 2 == 0)
		is_even = 1;
	if (input->game_size % 2 == 1)
		is_even = 0;
	error_found = check_cols(input, is_even) + check_rows(input, is_even);
	error_found += check_angles(input, 0) + check_one(input);
	if (error_found == 0)
	{
		ft_printf("POSSIBILE.\n");
		return (0);
	}
	ft_printf("\nPROBLEMI RILEVATI: %d\n\n", error_found);
	return (error_found);
}

int	check_cols(t_input *input, t_onebyte is_even)
{
	int	i;
	int	error_found;
	int	max;

	max = input->game_size;
	i = 0;
	error_found = 0;
	while (input->colup.x[i] != 0)
	{
		if ((input->colup.x[i] == 1) && (input->coldown.x[i] == 1))
			cols_error(i, input, &error_found, 1);
		if (((input->colup.x[i] == max) && (input->coldown.x[i] == max))
			|| ((input->colup.x[i] == max) && (input->coldown.x[i] == max)))
			cols_error(i, input, &error_found, 2);
		if (is_even == 1)
			if ((input->colup.x[i] + input->coldown.x[i] >= max + 3))
				cols_error(i, input, &error_found, 4);
		if (is_even == 0)
			if ((input->colup.x[i] + input->coldown.x[i] >= max + 2))
				cols_error(i, input, &error_found, 5);
		++i;
	}
	return (error_found);
}

void	cols_error(int index, t_input *input, int *error_found, int condition)
{
	ft_printf("\nERRORE %d: ", condition);
	ft_printf("input->colup.x[%d] e input->coldown.x[%d]\n", index, index);
	ft_printf("AKA %d,%d, ", input->colup.x[index], input->coldown.x[index]);
	ft_printf("non sono compatibili: \n");
	if (condition == 1)
	{
		ft_printf("due colonne opposte non possono avere contemporaneamente ");
		ft_printf("il valore minimo (1).\n-----------");
	}
	if (condition == 2)
	{
		ft_printf("se uno dei valori e' il massimo(%d), ", input->game_size);
		ft_printf("il valore nella parte opposta deve essere 1.\n-----------");
	}
	if (condition == 3)
	{
		ft_printf("con griglia pari e' sempre falso che VALUE_1 + VALUE_2");
		ft_printf(" >= game_size + 3(%d).\n-----------", input->game_size + 3);
	}
	if (condition == 5)
	{
		ft_printf("con griglia dispari e' sempre falso che VALUE_1 + VALUE_2");
		ft_printf(" >= game_size + 2(%d).\n-----------", input->game_size + 2);
	}
	++(*error_found);
}

int	check_rows(t_input *input, t_onebyte is_even)
{
	int	i;
	int	error_found;
	int	max;

	max = input->game_size;
	i = 0;
	error_found = 0;
	while (input->rowleft.y[i] != 0)
	{
		if ((input->rowleft.y[i] == 1) && (input->rowright.y[i] == 1))
			rows_error(i, input, &error_found, 1);
		if (((input->rowleft.y[i] == max) && (input->rowright.y[i] == max))
			|| ((input->rowleft.y[i] == max) && (input->rowright.y[i] == max)))
			rows_error(i, input, &error_found, 2);
		if (is_even == 1)
			if ((input->rowleft.y[i] + input->rowright.y[i] >= max + 3))
				rows_error(i, input, &error_found, 4);
		if (is_even == 0)
			if ((input->rowleft.y[i] + input->rowright.y[i] >= max + 2))
				rows_error(i, input, &error_found, 5);
		++i;
	}
	return (error_found);
}

void	rows_error(int index, t_input *input, int *error_found, int condition)
{
	ft_printf("\nERRORE %d: ", condition);
	ft_printf("input->rowleft.y[%d] e input->rowright.y[%d]\n", index, index);
	ft_printf("AKA %d,%d, ", input->rowleft.y[index], input->rowright.y[index]);
	ft_printf("non sono compatibili: \n");
	if (condition == 1)
	{
		ft_printf("due colonne opposte non possono avere contemporaneamente ");
		ft_printf("il valore minimo (1).\n-----------");
	}
	if (condition == 2)
	{
		ft_printf("se uno dei valori e' il massimo(%d), ", input->game_size);
		ft_printf("il valore nella parte opposta deve essere 1.\n-----------");
	}
	if (condition == 3)
	{
		ft_printf("con griglia pari e' sempre falso che VALUE_1 + VALUE_2");
		ft_printf(" >= game_size + 3(%d).\n-----------", input->game_size + 3);
	}
	if (condition == 5)
	{
		ft_printf("con griglia dispari è sempre falso che VALUE_1 + VALUE_2");
		ft_printf(" >= game_size + 2(%d).\n-----------", input->game_size + 2);
	}
	++(*error_found);
}

#endif
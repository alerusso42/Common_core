/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_logic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:27:28 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/05 12:42:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_LOGIC_H
# define SOLVE_LOGIC_H
# include "types.h"
# include "solve_game.h"
# include "solve_logic2.h"

void	ft_logic_rules(t_input *input, t_solution **solution);
void	ft_logic_rule1(t_input *input, t_solution **solution);
void	ft_logic_rule2(t_input *input, t_solution **solution, int x, int y);
void	ft_logic_rule3(t_input *input, t_solution **solution);
void	ft_logic_rule4(t_input *input, t_solution **solution);
void	insertnum_sure(t_solution **solution, int x, int y, t_onebyte num);

void	ft_logic_rules(t_input *input, t_solution **solution)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_logic_rule1(input, solution);
	ft_logic_rule2(input, solution, x, y);
	ft_logic_rule3(input, solution);
	ft_logic_rule4(input, solution);
	ft_locknumbers(solution);
	update_uncertainscore(solution);
}

/* Se uno dei valori dati dall'input è 1, la casella accanto avrà sempre
   il valore massimo possibile.*/
void	ft_logic_rule1(t_input *input, t_solution **solution)
{
	int			x;
	int			y;
	t_onebyte	max;

	x = 0;
	y = 0;
	max = input->game_size;
	while ((x != max) || (y != max))
	{
		if (input->colup.x[x] == 1)
			insertnum_sure(solution, x, (max - 1), max);
		if (input->coldown.x[x] == 1)
			insertnum_sure(solution, x, 0, max);
		if (input->rowleft.y[y] == 1)
			insertnum_sure(solution, 0, y, max);
		if (input->rowright.y[y] == 1)
			insertnum_sure(solution, (max - 1), y, max);
		++x;
		++y;
	}
}

/* Se uno dei valori dati dall'input è il massimo consentito,
   le caselle adiacenti avranno valori crescenti, partendo da 1 fino a
   game_size.*/
void	ft_logic_rule2(t_input *input, t_solution **solution, int x, int y)
{
	t_onebyte	game_size;
	signed char	col;
	signed char	row;

	game_size = input->game_size;
	col = -1;
	row = -1;
	if (input->colup.x[x] == game_size)
		while (++row != game_size)
			insertnum_sure(solution, x, (game_size - row - 1), (row + 1));
	row = -1;
	if (input->coldown.x[x] == game_size)
		while (++row != game_size)
			insertnum_sure(solution, x, row, (row + 1));
	if (input->rowleft.y[y] == game_size)
		while (++col != game_size)
			insertnum_sure(solution, col, y, (col + 1));
	col = -1;
	if (input->rowright.y[y] == game_size)
		while (++col != game_size)
			insertnum_sure(solution, (game_size - col - 1), y, (col + 1));
	if ((++x != game_size) && (++y != game_size))
		ft_logic_rule2(input, solution, x, y);
}

// Se uno dei valori dati dall'input è 1 e all'estremo
// opposto c'è 2, la casella adiacente a 2 è pari a
// MAX_VALUE - 1.
void	ft_logic_rule3(t_input *input, t_solution **solution)
{
	int			x;
	int			y;
	t_onebyte	max;

	x = 0;
	y = 0;
	max = input->game_size;
	while ((x != max) || (y != max))
	{
		if ((input->colup.x[x] == 1) && (input->coldown.x[x] == 2))
			insertnum_sure(solution, x, 0, (max - 1));
		if ((input->coldown.x[x] == 1) && (input->colup.x[x] == 2))
			insertnum_sure(solution, x, (max - 1), (max - 1));
		if ((input->rowleft.y[y] == 1) && (input->rowright.y[y] == 2))
			insertnum_sure(solution, (max - 1), y, (max - 1));
		if ((input->rowright.y[y] == 1) && (input->rowleft.y[y] == 2))
			insertnum_sure(solution, 0, y, (max - 1));
		++x;
		++y;
	}
}

/* Se nell'input dell'utente c'è un 2, sappiamo già che la
   casella adiacente non potrà avere come valore MAX_VALUE:
   se per assurdo ci fosse, non potremmo vedere altre caselle.
   Vale una regola simile per 2 + n: con 3, la casella
   accanto non potrà essere MAX_VALUE - 1, e quella
   ancora dopo non potrà essere MAX_VALUE.
   Facciamo un esempio con game_size 4, con questa board:
	4	3	2	1
4					1
3					2
2					2
1					2
	1	2	2	2
	Osserva input->colup.x[2]: se sotto avesse
	un 4, non potrebbe vedere altre caselle.
	Osserva ora invece input->colup.x[1]: sotto
	non può avere né un 4 né un 3, perchè
	altrimenti la regola dei grattacieli non
	potrebbe essere rispettata; ma c'è altro:
	input->colup.x[1], una casella ancora
	sotto, non può essere MAX_VALUE.
	L'unica eccezione a questa regola è il numero 1:
	deve sempre avere accanto il MAX_VALUE, per la
	regola numero 1.
	
	Astraendo, un valore n di input > 1 copre
	n - 1 elementi dell'array
	[MAX_VALUE, MAX_VALUE - 1, MAX_VALUE - 2, ..., 0],
	e le caselle adiacenti n - 1 - m elementi, con m
	pari al numero di spostamenti effettuati.  
*/
void	ft_logic_rule4(t_input *input, t_solution **solution)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	rule4_colup(input, solution, x);
	rule4_coldown(input, solution, x);
	rule4_rowleft(input, solution, y);
	rule4_rowright(input, solution, y);
}

#endif

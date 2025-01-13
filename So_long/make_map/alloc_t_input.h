/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_t_input.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:58:08 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/11 20:12:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_T_INPUT_H
# define ALLOC_T_INPUT_H
# define ERROR_INVALID_INPUT 2
# define ERROR_FULL_MEMORY 3
# include "atoi.h"
# include "types.h"

int				copy_user_input(char *argv[], t_input **input);
int				check_user_input(t_input *input);

// Cosa è game_size, variabile introdotta nel main?
// è "(argc - 1) / 4) + 1".
// Cosa è "(argc - 1) / 4) + 1"?
// Dato che gli argomenti sono multipli di 4,
// argc - 1 (il nome del programma) %4 si ottiene sempre 0.
// Facendo invece (argc - 1) / 4, trovo quante volte devo
// moltiplicare 4 per trovare il numero degli argomenti.
// A che ci serve? Il progetto vuole che allochiamo colup,
// coldown, rowleft e rowright assegnando ad ognuno un
// numero di argomenti di argv pari a (argc - 1) / 4;
// pertanto con questo conto, che salviamo in 
// game_size, capiamo quanti numeri ci servono.
// Allochiamo, oltre a (argc - 1) / 4), un byte in più
// per un carattere terminatore (0), e un altro byte
// in più perchè.. sennò non va. O meglio, succede casino
// nel free a fine programma.
// 
// Allochiamo memoria prima per la struttura s_input,
// che contiene i 4 array di int(input->colup.x, 
// input->coldown.x, ecc.).
// Nel programma chiamo la struttura "t_input": vai a
// "types.h" per ulteriori info sui tipi usati.
// Ultima nota: portiamo in funzione un ** per sovrascrivere
// il puntatore nel main senza usare il ritorno.
// Allochiamo memoria anche per NULL.
int	alloc_user_input(t_input **input, t_onebyte *game_size)
{
	int	size_heigth;
	int	size_width;

	(*input) = malloc(sizeof(t_input));
	if ((*input) == NULL)
		return (2);
	size_heigth = (sizeof(int)) * ((game_size[0]) + 2);
	size_heigth = (sizeof(int)) * ((game_size[1]) + 2);
	(*input)->colup.x = (t_onebyte *)malloc(size_heigth);
	(*input)->coldown.x = (t_onebyte *)malloc(size_heigth);
	(*input)->rowright.y = (t_onebyte *)malloc(size_width);
	(*input)->rowleft.y = (t_onebyte *)malloc(size_width);
	(*input)->game_size = *game_size;
	(*input)->game_size_h = game_size[0];
	(*input)->game_size_w = game_size[1];
	if (((*input)->colup.x == NULL) || ((*input)->coldown.x == NULL)
		|| ((*input)->rowright.y == NULL) || ((*input)->rowleft.y == NULL))
	{
		full_reset(1, input);
		return (ERROR_FULL_MEMORY);
	}
	return (0);
}

// in_index: indice degli array di input.
// av_index: indice di argv.
// ft_atoi fornisce il valore degli input dell'utente:
// check_user_input verifica che siano tutti > 0, e che
// i valori inseriti dall'utente siano minori uguali a
// GAME_SIZE.
//
// A fine funzione, impostiamo ai 4 array un carattere
// terminatore(0).
int	copy_user_input(char *argv[], t_input **input)
{
	int			av_index;
	int			in_index;
	t_onebyte	game_size;

	av_index = 0;
	in_index = -1;
	game_size = (*input)->game_size;
	while (++in_index < game_size)
		(*input)->colup.x[in_index] = ft_atoi(argv[++av_index]);
	in_index = -1;
	while (++in_index < game_size)
		(*input)->coldown.x[in_index] = ft_atoi(argv[++av_index]);
	in_index = -1;
	while (++in_index < game_size)
		(*input)->rowleft.y[in_index] = ft_atoi(argv[++av_index]);
	in_index = -1;
	while (++in_index < game_size)
		(*input)->rowright.y[in_index] = ft_atoi(argv[++av_index]);
	if (check_user_input(*input) == ERROR_INVALID_INPUT)
		return (ERROR_INVALID_INPUT);
	(*input)->colup.x[(game_size)] = 0;
	(*input)->coldown.x[(game_size)] = 0;
	(*input)->rowright.y[(game_size)] = 0;
	(*input)->rowleft.y[(game_size)] = 0;
	return (0);
}

/*	Se l'input dell'utente, in una delle 4 dimensioni, dovesse
	essere <= 0 oppure > game_size, prendiamo a sberle l'utente.
	Niente di più.
*/
int	check_user_input(t_input *input)
{
	int			index;
	t_onebyte	game_size;

	index = 0;
	game_size = input->game_size;
	while (index < game_size)
	{
		if ((input->rowright.y[index] <= 0)
			|| (input->rowleft.y[index] <= 0)
			|| (input->colup.x[index] <= 0)
			|| (input->coldown.x[index] <= 0))
		{
			return (ERROR_INVALID_INPUT);
		}
		if ((input->rowright.y[index] > (game_size))
			|| (input->rowleft.y[index] > (game_size))
			|| (input->colup.x[index] > (game_size))
			|| (input->coldown.x[index] > (game_size)))
		{
			return (ERROR_INVALID_INPUT);
		}
		++index;
	}
	return (0);
}

#endif
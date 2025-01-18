/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:58:08 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 09:27:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ERROR_INVALID_INPUT 2
# define ERROR_FULL_MEMORY 3
# include "atoi.h"
# include "types.h"

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
int	alloc_user_input(t_input **input, int game_size[2])
{
	int	size_heigth;
	int	size_width;

	(*input) = malloc(sizeof(t_input));
	if ((*input) == NULL)
		return (2);
	size_width = (sizeof(int)) * ((game_size[0]) + 4);
	size_heigth = (sizeof(int)) * ((game_size[1]) + 4);
	(*input)->col.x = (t_onebyte *)ft_calloc(size_width, 1);
	(*input)->row.y = (t_onebyte *)ft_calloc(size_heigth, 1);
	(*input)->game_size = game_size[0] * game_size[1];
	(*input)->game_size_w = game_size[0];
	(*input)->game_size_h = game_size[1];
	if (((*input)->col.x == NULL) || ((*input)->row.y == NULL))
	{
		full_reset(1, input);
		return (ERROR_FULL_MEMORY);
	}
	return (0);
}

void	temp_set_input(t_input **input)
{
	int	stop_row;
	int	stop_col;

	stop_row = 0;
	stop_col = 0;
	while (stop_row != (*input)->game_size_h + 2)
	{
		(*input)->row.y[stop_row] = 0;
		++stop_row;
	}
	while (stop_col != (*input)->game_size_w + 2)
	{
		(*input)->col.x[stop_col] = 0;
		++stop_col;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/06 16:11:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

void	twist_random(t_random **random, int game_size);
void	twist_random2(t_random **random, int game_size);
void	twist_random3(t_random **random, int game_size);

// In questa funzione faccio cose a caso per generare valori pseudocasuali.
// Di base genero una lista di 256 elementi il cui valore varia da 1 a
// game_size; i valori partono da 1, e salgono in ordine crescente, fino
// a superare game_size: quando succede, tornano a 1.
// Perciò, se game_size è 5, i valori generati saranno:
// 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5...
// ...E così via, fino al 256esimo elemento.
// Faccio arrivare da fuori dalla funzione un seed: in base al suo valore,
// I valori casuali generati si alterano.
// Si alterano scambiando gli indici: con delle condizioni caotiche e senza
// senso, altero i valori di due indici, index e caos_index, e per un certo
// numero di volte vado a scambiare gli indici della lista di valori.
// Ad esempio.
// index = 5, caos_index = 2.
// Nel nostro esempio precedente, random->values[5] = 1, random->values[2] = 3;
// Facendo lo scambio, ottengo random->values[5] = 3, random->values[2] = 1.
// L'idea è appunto mescolare il mazzo della lista di valori a caso.
// L'ultimo valore viene settato a 103 (carattere terminatore).
// Si ferma quando index == 0. 
//
// Nota: alterare il seed ha un effetto sul risultato pari a zero.
// Ma non dirlo in giro.
int	get_randomlist(t_random **random, int game_size)
{
	int	index;
	int	crescent_numbers;

	index = -1;
	crescent_numbers = (*random)->seed;
	while (++index != game_size)
	{
		if (crescent_numbers > game_size)
			crescent_numbers = 1;
		if (crescent_numbers == 0)
			crescent_numbers = 1;
		(*random)->values[index] = crescent_numbers;
		crescent_numbers += 1;
	}
	twist_random(random, game_size);
	(*random)->values[game_size] = -1;
	return (0);
}

void	twist_random(t_random **random, int game_size)
{
	int			index;
	int			caos_index;

	index = game_size;
	while (--index != 0)
	{
		(*random)->seed += (*random)->seed;
		if (index % 3 == 0)
			(*random)->seed *= index - (*random)->seed;
		if ((*random)->seed % 7 == 0)
			(*random)->seed = (*random)->values[(*random)->values[index % 7]];
		caos_index = (*random)->seed % game_size;
		ft_swap(&(*random)->values[index], &(*random)->values[caos_index]);
	}
}

void	twist_random2(t_random **random, int game_size)
{
	int			index;
	int			caos_index;

	index = game_size;
	while (--index != 0)
	{
		(*random)->seed += (*random)->seed;
		if (caos_index == 0)
			caos_index = 1;
		if (index % 3 == 0)
			(*random)->seed *= index - (*random)->seed;
		if ((*random)->seed % 2 == 0)
			(*random)->seed = (*random)->values[index % caos_index];
		if ((*random)->seed % 23 == 0)
			index += 11;
		caos_index = (*random)->seed % game_size;
		index %= game_size;
		ft_swap(&(*random)->values[index], &(*random)->values[caos_index]);
	}
}

void	twist_random3(t_random **random, int game_size)
{
	int			index;
	int			caos_index;

	index = game_size;
	while (--index != 0)
	{
		(*random)->seed += (*random)->seed;
		if (index % 2 == 0)
			(*random)->seed *= index - (*random)->seed;
		if ((*random)->seed % 4 == 0)
			(*random)->seed = (*random)->values[(*random)->values[index]];
		caos_index = (*random)->seed % game_size;
		ft_swap(&(*random)->values[index], &(*random)->values[caos_index]);
	}
}

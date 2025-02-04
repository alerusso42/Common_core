/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:58:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	twist_random(t_random *random, int numbers_len);
void	twist_random2(t_random *random, int numbers_len);
void	twist_random3(t_random *random, int numbers_len);

// In questa funzione faccio cose a caso per generare valori pseudocasuali.
// Di base genero una lista di 256 elementi il cui valore varia da 1 a
// numbers_len; i valori partono da 1, e salgono in ordine crescente, fino
// a superare numbers_len: quando succede, tornano a 1.
// Perciò, se numbers_len è 5, i valori generati saranno:
// 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5...
// ...E così via, fino al 256esimo elemento.
// Faccio arrivare da fuori dalla funzione un seed: in base al suo valore,
// I valori casuali generati si alterano.
// Si alterano scambiando gli indici: con delle condizioni caotiche e senza
// senso, altero i valori di due indici, i e caos, e per un certo
// numero di volte vado a scambiare gli indici della lista di valori.
// Ad esempio.
// i = 5, caos = 2.
// Nel nostro esempio precedente, random->values[5] = 1, random->values[2] = 3;
// Facendo lo scambio, ottengo random->values[5] = 3, random->values[2] = 1.
// L'idea è appunto mescolare il mazzo della lista di valori a caso.
// L'ultimo valore viene settato a 103 (carattere terminatore).
// Si ferma quando i == 0. 
//
// Nota: alterare il seed ha un effetto sul risultato pari a zero.
// Ma non dirlo in giro.
int	get_randomlist(t_random *random, int numbers_len)
{
	int	i;
	int	crescent_numbers;

	random->seed = INT_MAX % numbers_len;
	i = -1;
	crescent_numbers = random->seed / 2;
	while (++i != numbers_len)
	{
		if (crescent_numbers > numbers_len)
			crescent_numbers = 1;
		if (crescent_numbers == 0)
			crescent_numbers = 1;
		random->values[i] = crescent_numbers;
		crescent_numbers += 1;
	}
	twist_random2(random, numbers_len);
	random->values[numbers_len] = INT_MAX;
	return (0);
}

void	twist_random2(t_random *random, int numbers_len)
{
	int			i;
	int			caos;

	i = numbers_len - 1;
	caos = 0;
	while ((i) && (--i != 0))
	{
		if (caos == 0)
			caos = 1;
		if (i % 3 == 0)
			random->seed *= i - random->seed;
		if (random->seed % 2 == 0)
			random->seed = random->values[i % caos];
		if (random->seed % 23 == 0)
			i %= 11;
		caos = random->seed % numbers_len;
		i %= numbers_len;
		if ((caos >= 0) && (caos < numbers_len - 3) && \
		(random->values[caos] != 0))
		{
			random->values[i] = random->values[i] ^ random->values[caos];
			random->values[caos] = random->values[i] ^ random->values[caos];
			random->values[i] = random->values[i] ^ random->values[caos];
		}
	}
}

void	twist_random3(t_random *random, int numbers_len)
{
	int			i;
	int			caos;

	i = numbers_len - 1;
	while (--i != 0)
	{
		random->seed += random->seed;
		if (i % 2 == 0)
			random->seed *= i - random->seed;
		if (random->seed % 4 == 0)
			random->seed = random->values[random->values[i]];
		caos = random->seed % numbers_len;
		if (random->values[caos] != 0)
		{
			random->values[i] = random->values[i] ^ random->values[caos];
			random->values[caos] = random->values[i] ^ random->values[caos];
			random->values[i] = random->values[i] ^ random->values[caos];
		}
	}
}

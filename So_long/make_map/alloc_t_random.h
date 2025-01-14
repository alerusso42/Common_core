/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_t_random.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:57:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/14 13:44:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_T_RANDOM_H
# define ALLOC_T_RANDOM_H
# include "types.h"
# include "ft_printf.h"
# include "random_numbers.h"

int			alloc_randomlist(t_random **random);
t_random	*fill_random(t_random **random, t_input *input);
void		show_random_values(t_random *random);

// Allochiamo 257 bytes perchè nella lista ci saranno 256 elementi
// di tipo t_onebyte (che occupano 1 byte, vedi types.h).
// L'ultimo byte allocato è di sicurezza, perchè spesso senza non
// funziona nulla.
// random prende valori casuali da 1 a game_size, e termina sempre col
// carattere terminatore 103.
int	alloc_randomlist(t_random **random)
{
	int	size_memory;

	size_memory = 257;
	(*random) = malloc(sizeof(t_random));
	if (*random == NULL)
	{
		return (1);
	}
	(*random)->values = ft_calloc(size_memory, sizeof(t_onebyte));
	if ((*random)->values == NULL)
	{
		free(*random);
		return (1);
	}
	return (0);
}

t_random	*fill_random(t_random **random, t_input *input)
{
	t_onebyte	store_variable;

	(*random)->seed = input->rowleft.y[0] + input->rowright.y[0];
	(*random)->seed += input->colup.x[0] + input->coldown.x[0];
	store_variable = (*random)->seed;
	get_randomlist(random, input->game_size);
	(*random)->seed = store_variable;
	if ((*random)->switch_1_showseed == ON)
		ft_printf("\nSeed used: %d\n", (*random)->seed);
	if ((*random)->switch_2_showrandomvalues == ON)
		show_random_values(*random);
	return (*random);
}

void	show_random_values(t_random *random)
{
	int	index;

	index = 0;
	ft_printf("List of 256 values:\n");
	while (random->values[index] != 103)
	{
		ft_printf("%d: %d\n", index + 1, random->values[index]);
		++index;
	}
	ft_printf("%d: %d\n", index + 1, random->values[index]);
	ft_printf("END OF LIST\n");
}

#endif
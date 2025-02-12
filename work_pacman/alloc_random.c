/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:57:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

int			alloc_randomlist(t_random **random, int game_size);
t_random	*fill_random(t_random **random, t_input *input);
void		show_random_values(t_random *random);
int			full_reset(int struct_num, ...);

/*
	Allocation for the random struct.
	Really useful to randomize stuff.
	Rand can be used, but I didn't know it at the start, lol
*/
int	alloc_randomlist(t_random **random, int game_size)
{
	int	size_memory;

	size_memory = game_size + 3;
	(*random) = malloc(sizeof(t_random));
	if (*random == NULL)
	{
		return (1);
	}
	(*random)->values = ft_calloc(size_memory, sizeof(int));
	if ((*random)->values == NULL)
	{
		free(*random);
		return (1);
	}
	return (0);
}

/*
	My intention was to randomize through 3 values:

	x size of map;
	y size of map;
	a random seed given by the user (optional).

	Actually, I failed on the last part.
	So, the seed is useless.
*/
t_random	*fill_random(t_random **random, t_input *input)
{
	t_onebyte	store_variable;

	(*random)->seed = input->game_size_w + input->game_size_h;
	store_variable = (*random)->seed;
	get_randomlist(random, input->game_size);
	(*random)->seed = store_variable;
	if ((*random)->switch_1_showseed == ON)
		l_printf("\nSeed used: %d\n", (*random)->seed);
	if ((*random)->switch_2_showrandomvalues == ON)
		show_random_values(*random);
	return (*random);
}

/*
	This function only work when switch showrandomvalues is ON.
*/
void	show_random_values(t_random *random)
{
	int	index;

	index = 0;
	l_printf("List of x * y values:\n");
	while (random->values[index] != -1)
	{
		l_printf("%d: %d\n", index + 1, random->values[index]);
		++index;
	}
	l_printf("%d: %d\n", index + 1, random->values[index]);
	l_printf("END OF LIST\n");
}

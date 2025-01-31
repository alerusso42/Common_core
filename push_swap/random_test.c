/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:59:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/31 10:54:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	print_and_algorythm(t_settings *settings, t_stack *a, t_stack *b);

static void	free_random(t_random **random)
{
	if ((!random) || (!*random))
		return ;
	if ((*random)->values)
	{
		free((*random)->values);
		(*random)->values = NULL;
	}
	free(*random);
	*random = NULL;
}

static void	get_random_stack(t_stack *a, t_random *random)
{
	int	index;

	index = 0;
	while (index != a->size)
	{
		a->data[index] = random->values[index];
		++index;
	}
}

/*
	Steps: 

	1)	if argc == 1, stop;
	2)	if during parsing something goes wrong (malloc, invalid chars..), stop;
	3)	algorythm;
	4)	print;
	5)	release of memory alloc.
*/
int	random_test(char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_settings		*settings;
	static t_random	*random;
	int				error_type;

	a = NULL;
	b = NULL;
	settings = (t_settings *)ft_calloc(1, sizeof(t_settings));
	if (!settings)
		return (error(ER_MALLOC_ERROR));
	error_type = get_data((int)ft_atoi(argv[2]), &a, &b);
	if (error_type != 0)
		return (free_memory(&a, &b), free(settings), error(error_type));
	if (alloc_randomlist(&random, (int)ft_atoi(argv[2])) != 0)
		return (free_memory(&a, &b), free(settings), free_random(&random), \
		ER_MALLOC_ERROR);
	get_random_stack(a, random);
	free_random(&random);
	find_biggest(a);
	switches(settings, a);
	variables(settings, a, b);
	print_and_algorythm(settings, a, b);
	return (free_memory(&a, &b), free(settings), 0);
}
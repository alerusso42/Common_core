/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:57:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:42:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

int	alloc_randomlist(t_random **random, int numbers_len)
{
	int	size_memory;

	if (numbers_len < 2)
		return (1);
	size_memory = numbers_len + 3;
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
	get_randomlist(*random, numbers_len);
	return (0);
}

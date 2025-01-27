/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:13:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 14:29:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

/*
	Steps: 

	1)	if argc == 1, stop;
	2)	if during parsing something goes wrong (malloc, invalid chars..), stop;
	3)	algorytm;
	4)	print;
	5)	release of memory alloc.
*/
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		error_type;

	if (argc == 1)
		return (error(ER_BAD_ARGC));
	a = NULL;
	b = NULL;
	error_type = get_data(argc, argv, &a, &b);
	if (error_type != 0)
		return (free_memory(&a, &b), error(error_type));
	//ALGORYTM
	free_memory(&a, &b);
	return (0);
}
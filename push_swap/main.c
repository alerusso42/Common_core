/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:13:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/29 10:46:14 by alerusso         ###   ########.fr       */
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
	t_stack		*a;
	t_stack		*b;
	t_settings	*settings;
	int			error_type;

	if (argc == 1)
		return (error(ER_BAD_ARGC));
	a = NULL;
	b = NULL;
	settings = (t_settings *)ft_calloc(1, sizeof(t_settings));
	if (!settings)
		return (error(ER_MALLOC_ERROR));
	error_type = parsing(argc - 1, argv, &a, &b);
	if (error_type != 0)
		return (free_memory(&a, &b), free(settings), error(error_type));
	variables(settings);
	if (settings->variable_1_mode == PLAY)
		play();
	//ALGORYTM
	print_stacks();
	return (free_memory(&a, &b), free(settings), 0);
}
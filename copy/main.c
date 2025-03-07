/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:13:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/07 10:45:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	print_and_algorythm(t_settings *settings, t_stack *a, t_stack *b);

/*
	PLAY:							allows to play with your algorythm;
	CORRECTION/PRINT_FINAL_RESULT:	perform an algorythm;
	EXECUTE:						execute tester.txt;
	switch_5_save_result:			save the result of algorythm on
									tester.txt.
*/
void	print_and_algorythm(t_settings *settings, t_stack *a, t_stack *b)
{
	int	mode;

	mode = settings->variable_1_mode;
	if (mode == PLAY)
		play();
	if ((mode == CORRECTION) || (mode == PRINT_FINAL_RESULT))
	{
		if (settings->variable_2_which_algorythm == RADIX_SORT)
			radix_sort(a, b);
		else if (settings->variable_2_which_algorythm == INSERTION_SORT)
			insertion_sort(a, b);
		if (settings->switch_3_doctorstrange == ON)
			doctor_strange(a);
	}
	if (mode == EXECUTE)
	{
		print_stacks();
		execute_result();
		print_stacks();
	}
	if (settings->switch_5_save_result == ON)
		save_result(a);
}

//	\007\001\001\006\001\007\007\006\006\001\007\001\006\001\007\007\006\006
/*
	Steps: 

	1)	if argc == 1, stop;
	2)	if during parsing something goes wrong (malloc, invalid chars..), stop;
	3)	algorythm;
	4)	print;
	5)	release of memory alloc.
*/
int	main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_settings		*settings;
	int				error_type;

	if (argc <= 1)
		return (1);
	if ((ft_strncmp("test", argv[1], 4) == 0) && (argc == 3))
		return (random_test(argv));
	a = NULL;
	b = NULL;
	settings = (t_settings *)ft_calloc(1, sizeof(t_settings));
	if (!settings)
		return (error(ER_MALLOC_ERROR, *argv));
	error_type = parsing(argc - 1, argv, &a, &b);
	if (error_type != 0)
		return (free_memory(&a, &b), free(settings), error(error_type, *argv));
	switches(settings, a);
	variables(settings, a, b);
	switch_to_bonus(settings, a);
	if (settings->switch_5_bonus == ON)
		return (test(), free_memory(&a, &b), free(settings), 0);
	print_and_algorythm(settings, a, b);
	return (free_memory(&a, &b), free(settings), 0);
}

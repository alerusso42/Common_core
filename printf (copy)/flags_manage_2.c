/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manage_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:04:13 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/14 16:49:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// [flags][width](NO_FLAGS?)[precision + length][SPECIFIER, if not ERROR]
int	is_specifier(char specifier)
{
	if (specifier == 'c')
		return (0);
	if (specifier == 's')
		return (0);
	if (specifier == 'p')
		return (0);
	if (specifier == 'd')
		return (0);
	if (specifier == 'i')
		return (0);
	if (specifier == 'u')
		return (0);
	if (specifier == 'x')
		return (0);
	if (specifier == 'X')
		return (0);
	if (specifier == '%')
		return (0);
	return (ERROR);
}

/*	SUMMARY OF FLAGS AND AESTHETIC COMMAND:
	1) - :Left alignment 	--->Ov. 2
	2) 0 :Zero padding  	--->
	3) . :Precision			--->Ov. 2, makes 5(if true) 4
	4) MR:Minimal width		--->
	5)MR0:Min. width + 0	--->Ov. 4 
	6) # :Alternative form	--->
	7)   :Space				--->
	8) + :Explicit sign		--->Ov. 7*/
void	override_rules(t_printdata *data)
{
	if (data->is_minus_flag == 1)
	{
		data->is_zero_flag = 0;
		data->is_width_zero = 0;
	}
	if (data->is_precision == 1)
	{
		data->is_zero_flag = 0;
		data->is_width_zero = 0;
	}
	if (data->is_width_zero == 1)
		data->is_width = 0;
	if (data->is_expsign_flag == 1)
		data->is_space_flag = 0;
	if (data->print_address == 1)
		data->is_alt_form = 1;
}

size_t	go_next(const char *str, size_t *index)
{
	size_t	counter;

	counter = 1;
	write(1, &str[*index], 1);
	++(*index);
	++counter;
	while ((str[*index]) && (str[*index] != '%') && (is_specifier(str[*index])))
	{
		write(1, &str[*index], 1);
		++(*index);
		++counter;
	}
	if (str[*index])
	{
		write(1, &str[*index], 1);
		++counter;
	}
	return (counter);
}

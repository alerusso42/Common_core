/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:31:32 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/16 17:50:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_flags(unsigned int size, size_t flag)
{
	char	print_character;

	if (flag == SPACES)
		print_character = ' ';
	else if ((flag == ZEROS) || (flag == PRECISION))
		print_character = '0';
	while (size--)
	{
		write(1, &print_character, 1);
	}
}

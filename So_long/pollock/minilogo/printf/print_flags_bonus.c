/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:31:32 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/17 13:51:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

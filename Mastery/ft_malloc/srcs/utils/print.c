/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 21:57:55 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/23 23:33:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	mem_dump_bit(t_area *area)
{
	char	bits[9];
	char	byte;

	bits[8] = 0;
	ft_printf("\nmemDumpBit: ");
	for (size_t i = sizeof(t_area); i != (size_t)area->next; i++)
	{
		byte = *(char *)(((void *)area) + i);
		bits[0] = ((byte & (1 << 7)) != 0) + '0';
		bits[1] = ((byte & (1 << 6)) != 0) + '0';
		bits[2] = ((byte & (1 << 5)) != 0) + '0';
		bits[3] = ((byte & (1 << 4)) != 0) + '0';
		bits[4] = ((byte & (1 << 3)) != 0) + '0';
		bits[5] = ((byte & (1 << 2)) != 0) + '0';
		bits[6] = ((byte & (1 << 1)) != 0) + '0';
		bits[7] = ((byte & (1 << 0)) != 0) + '0';
		ft_printf("|%s", bits);
	}
	ft_printf("|");
}

void	mem_dump_hex(t_area *area)
{
	char	hex1;
	char	hex2;
	char	byte;

	ft_printf("\nmemDumpHex: ");
	for (size_t i = sizeof(t_area); i != (size_t)area->next; i++)
	{
		byte = *(char *)(((void *)area) + i);
		hex1 = ((byte & ((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4))) != 0) + '0';
		hex2 = ((byte & ((1 << 3) | (1 << 2) | (1 << 1) | (1 << 0))) != 0) + '0';
		ft_printf("X%c X%c ", hex1, hex2);
	}
}

void	mem_dump_byte(t_area *area)
{
	char	byte;

	ft_printf("\nmemDumpByte: ");
	for (size_t i = sizeof(t_area); i != (size_t)area->next; i++)
	{
		byte = *(char *)(((void *)area) + i);
		ft_printf("%c", byte);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/16 17:13:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

typedef unsigned char	byte_t;
void 	*ft_print_memory(void *addr, unsigned int size);
int	print_byte_hex1(byte_t);
void	print_byte_hex2(byte_t);
void	print_address_hex(void *);
/*
int main(void)
{
    int num_str = 5;
    char *str[num_str];
	int	i = 0;

	str[0] = (char *)malloc(strlen(" Bonjour les amin") + 1);
    str[1] = (char *)malloc(strlen("ches...c. est fo") + 1);
    str[2] = (char *)malloc(strlen("peut faire avec") + 1);
    str[3] = (char *)malloc(strlen("..print_memory..") + 1);
    str[4] = (char *)malloc(strlen("\2\1lol.lol\0 .") + 1);
	strcpy(str[0], " Bonjour les amin");
	strcpy(str[1], "ches...c. est fo");
	strcpy(str[2], "peut faire avec");
	strcpy(str[3], "..print_memory..");
	strcpy(str[4], "\2\1lol.lol\0 .");
	while (i < num_str)
	{
		printf("\nIndirizzo reale di str[%d]: %p\n", i, str[i]);
		ft_print_memory((void *)str[i], strlen(str[i]));
		++i;
	}
	for (i = 0; i < num_str; ++i)
    {
        free(str[i]);
    }
    return (0);
}*/
int main(void)
{
    char str1[17] = "Bonjour les ami";
	char str2[17] = "ches...c. est f";
	char str3[17] = "u.tout.ce qu o";
	char str4[17] = "peut faire avec";
	char str5[17] = "..print_memory.";

	//printf("\nIndirizzo reale di str1: %p\n", str1);
	ft_print_memory((void *)str1, strlen(str1));
	//printf("Indirizzo reale di str2: %p\n", str2);
	ft_print_memory((void *)str2, strlen(str2));
	//printf("Indirizzo reale di str3: %p\n", str3);
	ft_print_memory((void *)str3, strlen(str3));
	//printf("Indirizzo reale di str4: %p\n", str4);
	ft_print_memory((void *)str4, strlen(str4));
	//printf("Indirizzo reale di str5: %p\n", str5);
	ft_print_memory((void *)str5, strlen(str5));
    return (0);
}

void 	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;

	print_address_hex(addr);
	write(1, ": ", 2);
	i = 0;
	while (size != 0)
	{
		print_byte_hex1(*((byte_t *)addr + i));
		++i;
		if (size-- % 2 == 0)
			write(1, " ", 1);
	}
	while (i++ != 15)
		write(1, "  ", 2);
	write(1, " ", 1);
	i = -1;
	while (*((byte_t *)addr + ++i) != '\0')
	{
		if ((*((byte_t *)addr + i) < 32) || ((*((byte_t *)addr + i) > 126)))
			write (1, ".", 2);
		else
			write(1, (byte_t *)addr + i, 1);
	}
	write(1, "\n", 1);
	return (addr);
}

void	print_address_hex(void *addr)
{
	byte_t	*ptr_byte;
	int		i;

	ptr_byte = (byte_t *)&addr;
	i = 7;
	write (1, "0000", 4);
	while (i != -1)
	{
		print_byte_hex1(*(ptr_byte + i));
		--i;
	}
}

int	print_byte_hex1(byte_t byte)
{
	char	pippo[2];

	if (byte == 0)
		return (42);
	if ((byte / 16) < 10)
		pippo[0] = 48 + (byte / 16);
	else
		pippo[0] = 87 + (byte / 16);
	if ((byte % 16) < 10)
		pippo[1] = 48 + (byte % 16);
	else
		pippo[1] = 87 + (byte % 16);
	write(1, &pippo[0], 2);
	return (0);
}

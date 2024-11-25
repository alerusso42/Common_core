/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:32:48 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:23:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"

void ft_putendl_fd(char *s, int fd);

void ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}


int	main()
{
	int		pokedex;

	pokedex = open("updated_pokedex.txt", O_RDWR);
	if (pokedex == -1)
		return (1);
	ft_putendl_fd("Pokedex:", pokedex);
	close(pokedex);
	return (0);
}

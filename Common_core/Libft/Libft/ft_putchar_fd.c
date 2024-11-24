/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:54:41 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 15:29:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <malloc.h>
# include <string.h>
# include <fcntl.h>

void ft_putchar_fd(char c, int fd);

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main()
{
	int		pokedex;

	pokedex = open("updated_pokedex.txt", O_RDWR);
	if (pokedex == -1)
		return (1);
	ft_putchar_fd('P', pokedex);
	close(pokedex);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:31:06 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 16:31:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <malloc.h>
# include <string.h>
# include <fcntl.h>

void ft_putstr_fd(char *s, int fd);

void ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}


int	main()
{
	int		pokedex;

	pokedex = open("updated_pokedex.txt", O_RDWR);
	if (pokedex == -1)
		return (1);
	ft_putstr_fd("Pokedex:", pokedex);
	close(pokedex);
	return (0);
}

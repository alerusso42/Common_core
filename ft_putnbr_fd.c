/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:42:50 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 17:16:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	char	*string;

	string = ft_itoa(n);
	write(fd, &string[0], ft_strlen(string));
}

/*
int	main()
{
	int		fd;

	fd = open("testoh.txt", O_RDWR);
	if (fd == -1)
		return (1);
	ft_putnbr_fd(52352, fd);
	close(fd);
	return (0);
}*/

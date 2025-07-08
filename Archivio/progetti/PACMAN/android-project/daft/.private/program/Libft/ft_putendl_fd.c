/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:32:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:47:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, IO_STRUCT *fd)
{
	while (*s)
		WRITE(fd, s++, sizeof(char), 1);
	WRITE(fd, "\n", sizeof(char), 1);
}

/*
int	main()
{
	int		fd;

	fd = open("testoh.txt", O_RDWR);
	if (fd == -1)
		return (1);
	ft_putendl_fd("fd:", fd);
	close(fd);
	return (0);
}*/

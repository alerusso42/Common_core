/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:32:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 16:17:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putendl_fd(char *s, t_fd fd)
{
	WRITE(fd, s, ft_strlen(s));
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

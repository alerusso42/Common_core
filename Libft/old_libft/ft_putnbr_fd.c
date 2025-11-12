/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:42:50 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/29 10:27:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"

static void	ft_putnbr(int num, int fd);
static void	print(char *str, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}

static void	ft_putnbr(int num, int fd)
{
	char	str[12];
	int		temp_num;
	int		index;

	index = 0;
	if (num < 0)
		str[index++] = '-';
	if (num == 0)
		str[index] = '0';
	temp_num = num;
	while ((temp_num > 9) || (temp_num < -9))
	{
		index++;
		temp_num /= 10;
	}
	str[index + 1] = '\0';
	while (num != 0)
	{
		if (num < 0)
			str[index--] = (((num % 10) * -1) + 48);
		else
			str[index--] = ((num % 10) + 48);
		num /= 10;
	}
	print(str, fd);
}

// Printa una stringa con write.
static void	print(char *str, int fd)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(fd, &str[index], 1);
		++index;
	}
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

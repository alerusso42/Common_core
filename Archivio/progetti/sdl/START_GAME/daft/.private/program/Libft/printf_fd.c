/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/24 11:24:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

static int	type_print(char type, va_list ptr, t_fd fd);
static void	ft_putnbr(int num, t_fd fd);
static void	print(char *str, t_fd fd);

/*
int	main(void)
{
	char	c;
	int		x;
	char	*str;

	c = 'A'; 
	x = -42;
	str = "Vincere e vinceremo";
	printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	printf("Stringa custom: \n");
	ft_printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	return (0);
}
*/

/*
	A lighter and faster version of my ft_printf project.

	It takes an fd as argument.
*/
int	fd_printf(t_fd fd, const char *str, ...)
{
	int		index;
	va_list	ptr;

	if (!str)
	{
		return (1);
	}
	index = 0;
	va_start(ptr, str);
	while (str[index] != '\0')
	{
		if ((str[index] == '%') && (str[index + 1] != '\0'))
		{
			if (type_print(str[++index], ptr, fd) == 1)
				print("/UNKNOWN SPECIFIER/", fd);
		}
		else
			SDL_RWwrite(fd.p, &str[index], sizeof(char), 1);
		++index;
	}
	va_end(ptr);
	return (0);
}

int	type_print(char type, va_list ptr, t_fd fd)
{
	char	c;
	char	*s;
	int		d;

	if (type == 'c')
	{
		c = (char)va_arg(ptr, int);
		SDL_RWwrite(fd.p, &c, sizeof(char), 1);
	}
	else if (type == 's')
	{
		s = (char *)va_arg(ptr, char *);
		print(s, fd);
	}
	else if (type == 'd')
	{
		d = (int)va_arg(ptr, int);
		ft_putnbr(d, fd);
	}
	else
		return (1);
	return (0);
}

static void	ft_putnbr(int num, t_fd fd)
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

static void	print(char *str, t_fd fd)
{
	int	index;

	if (!str)
	{
		SDL_RWwrite(fd.p, "(NULL)", sizeof(char), 6);
		return ;
	}
	index = 0;
	while (str[index] != '\0')
	{
		SDL_RWwrite(fd.p, &str[index], sizeof(char), 1);
		++index;
	}
}

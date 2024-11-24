/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:42:50 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 16:57:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <malloc.h>
# include <string.h>
# include <fcntl.h>

void 	ft_putchar_fd(char c, int fd);
void	ft_itoa(int fd, int num, char *str);

void ft_putnbr_fd(int n, int fd)
{
	char	string[12];
	
	ft_itoa(fd, n, string);
}

void	ft_itoa(int fd, int num, char *str)
{
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
	while (*str)
		write(fd, str++, 1);
}

int	main()
{
	int		pokedex;

	pokedex = open("updated_pokedex.txt", O_RDWR);
	if (pokedex == -1)
		return (1);
	ft_putnbr_fd(52352, pokedex);
	close(pokedex);
	return (0);
}

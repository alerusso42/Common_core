/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:16:24 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/13 15:05:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_show_tab(struct s_stock_str *par);
void	ft_putnbr(int num);
int		ft_putstr(char *str);

/*
int	main(int argc, char *argv[])
{
	struct s_stock_str	*stock;
	struct s_stock_str	*ptr;

	if (argc < 1)
		return (42);
	stock = ft_strs_to_tab(argc, argv);
	ptr = stock;
	if (ptr != NULL)
		ft_show_tab(ptr);
	else
	{
		printf("Errore nell'allocazione della memoria!\n");
	}
	free(stock);
	return (0);
}
*/

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != NULL)
	{
		ft_putnbr(par->size);
		ft_putstr("\n");
		ft_putstr(par->str);
		ft_putstr("\n");
		ft_putstr(par->copy);
		ft_putstr("\n");
		++par;
	}
}

void	ft_putnbr(int num)
{
	char	str[12];
	int		temp_num;
	int		index;

	index = 0;
	if (num < 0)
		str[index++] = '-';
	if (num == 0)
		str[index++] = '0';
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
	ft_putstr(str);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
	}
	return (0);
}

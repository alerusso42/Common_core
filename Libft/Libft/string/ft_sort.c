/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 18:20:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	ft_sort_int(int *tab, int size)
{
	int	i;
	int	i2;
	int	t;

	i = -1;
	while (++i < size)
	{
		i2 = i;
		while (++i2 < size)
		{
			if (tab[i] > tab[i2])
			{
				t = tab[i];
				tab[i] = tab[i2];
				tab[i2] = t;
			}
		}
	}
}

void	ft_sort_str(char *tab)
{
	int	i;
	int	i2;
	int	t;

	i = -1;
	while (tab[++i])
	{
		i2 = i;
		while (tab[++i2])
		{
			if (tab[i] > tab[i2])
			{
				t = tab[i];
				tab[i] = tab[i2];
				tab[i2] = t;
			}
		}
	}
}

void	str_sort(t_str *str)
{
	if (str_check(str, NULL))
		return (_str_set_error(str, E_PARAM, "sort"));
	ft_sort_str(str->buff);
}

/*
int	main(void)
{
	int	tab[3] = {5, 6, 1};
	int	size;

	size = 3;
	ft_sort_int_tab(tab, size);	
	return (0);
}*/

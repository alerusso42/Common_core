/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_rev_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/12 20:14:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_int(int *tab, int size)
{
	int	i;
	int	t;

	i = 0;
	while (i < size / 2)
	{
		t = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = t;
		i++;
	}
}

void	ft_rev_str(char *arr)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (arr[j] != '\0')
		++j;
	--j;
	if (arr[0] == '-')
		++i;
	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		++i;
		--j;
	}
}

/*
int	main(void)
{
	int	tab[1] = {0};
	int	size;

	size = 1;
	ft_rev_int_tab(tab, size);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:47 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 12:47:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
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
/*
int	main(void)
{
	int	tab[3] = {5, 6, 1};
	int	size;

	size = 3;
	ft_sort_int_tab(tab, size);	
	return (0);
}*/

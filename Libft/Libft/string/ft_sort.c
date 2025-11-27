/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/27 09:43:11 by codespace        ###   ########.fr       */
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

//ANCHOR - str_sort
/*
	Sort in ascii order the content of the string object's buffer.

	@input:		[t_str *str]----->	pointer to string object
	@return:	[t_str *]--------->	pointer to this
	@variables:	[int i]----------->	start index
				[int j]----------->	end index
				[char t]---------->	temporary char for swapping
	@usage:	*-------------------------------*	
			|	str_reverse(str);			|
			|	//OR						|
			|	reverse(str);				|
			|	//OR						|
			|	str->m->reverse(&str);		|
			*-------------------------------*
*/
t_str	*str_sort(t_str *str)
{
	if (str_check(str, NULL))
		return (_str_set_error(str, E_PARAM, "sort"));
	ft_sort_str(str->buff);
	return (str);
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

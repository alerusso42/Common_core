/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:25:50 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/24 17:25:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	t1;
	int	t2;

	t1 = *a;
	t2 = *b;
	if (b != 0)
	{
		*a = t1 / t2;
		*b = t1 % t2;
	}
	else
	{
		*a = 0;
		*b = 0;
	}
}
/*
int main(void)
{
	int a;
	int b;
	int div;
	int mod;
	
	a = 27;
	b = 0;
	ft_div_mod(a, b, &div, &mod);
	printf("Quoziente %d resto %d", a, b);
	return (0);
}*/

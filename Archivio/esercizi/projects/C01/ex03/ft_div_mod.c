/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:25:29 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/24 17:25:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
	else
	{
		*div = 0;
		*mod = 0;
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
	printf("Quoziente %d resto %d", div, mod);
	return (0);
}*/

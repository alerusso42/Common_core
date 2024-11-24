/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:03:25 by alerusso          #+#    #+#             */
/*   Updated: 2024/08/06 12:03:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	len;
	int	i;

	if (argc)
	{
	}
	i = 0;
	while (argv[i])
		++i;
	--i;
	while (i > 0)
	{
		len = -1;
		while (argv[i][++len])
		{
		}
		write(1, argv[i], len);
		write(1, "\n", 1);
		--i;
	}
	return (0);
}

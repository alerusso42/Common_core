/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:02:58 by alerusso          #+#    #+#             */
/*   Updated: 2024/08/06 12:03:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	len;
	int	i;

	i = 1;
	while (i < argc)
	{
		len = -1;
		while (argv[i][++len])
		{
		}
		write(1, argv[i], len);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}

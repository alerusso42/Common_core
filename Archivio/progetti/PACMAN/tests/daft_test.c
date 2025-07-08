/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:01:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:56:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../daft/daft.h"
#include <stdio.h>
#include "lib.h"

/*
cc $(SDL3-config --cflags) -Wall -Wextra -Werror -g daft_test.c ../daft/daft.a $(SDL3-config --libs)
*/
int	main()
{
	int	i;
	int	j;

	daft_init();
	char	***matr = daft_get("CALYREX");
	if (!matr)
		return (daft_quit(), 1);
	i = 0;
	while (matr[i])
	{
		j = 0;
		while (matr[i][j])
		{
			printf("%s\n", matr[i][j]);
			j++;
		}
		i++;
	}
	daft_quit();
}

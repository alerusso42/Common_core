/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_daft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:21:47 by codespace         #+#    #+#             */
/*   Updated: 2025/11/27 20:04:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DAFT_PWD "daft_test/"
#include "libft.h"

// clear;cc -Wall -Wextra -Werror -g ./test_daft.c ./daft/program/daft_src/*.c ./daft/program/prep_src/*.c   data/list/*.c mem/*.c string/*.c printf/*.c files/*.c

int	main()
{
	int	i;
	int	j;

	daft_init();
    daft_swap(POKEDEX);
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

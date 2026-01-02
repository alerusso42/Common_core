/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_daft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:21:47 by codespace         #+#    #+#             */
/*   Updated: 2026/01/02 12:51:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// clear;cc -Wall -Wextra -Werror -g ./test_daft.c ./daft/program/daft_src/*.c ./daft/program/prep_src/*.c   data/list/*.c mem/*.c string/*.c printf/*.c files/*.c

int	main()
{
	int	i;
	int	j;

	daft_init("daft/DATA_DIR", "SETTINGS.md");
	daft_init(NULL, NULL);
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
	char	***add = daft_append("IR_GABIBBO", 0, 0);
	if (add)
	{
		i = 0;
		while (add[i])
		{
			j = 0;
			while (add[i][j])
			{
				printf("%s\n", add[i][j]);
				j++;
			}
			i++;
		}
		daft_quit();
	}
	for (int i = 0; i; i--)
	{
		daft_init("daft/DATA_DIR", "SETTINGS.md");
		daft_init("daft/DATA_DIR", "SETTINGS.md");
		daft_init("daft/DATA_DIR", "SETTINGS.md");
		daft_quit();
		daft_quit();
		daft_init("daft/DATA_DIR", "SETTINGS.md");
	}
	daft_quit();
	str_terminate();
}

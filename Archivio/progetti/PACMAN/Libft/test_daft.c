/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_daft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:21:47 by codespace         #+#    #+#             */
/*   Updated: 2025/12/01 09:26:26 by alerusso         ###   ########.fr       */
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
	char	***add = daft_append("SQUALO", 0, 0);
	if (!add)
		return (daft_quit(), 1);
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

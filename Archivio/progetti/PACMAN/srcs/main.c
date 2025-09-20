/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:03:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/20 17:14:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

int	main2()
{
	t_data	data;

	data = (t_data){0};
	srand((unsigned int)time(NULL));
	getter(&data, true);
	if (init_all(&data) != 0)
		return (data.last_error);
	game_loop(&data);
	free_all(&data);
	return (0);
}

void	test_print(char ***matr)
{
	int	i, j;

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
}

int	main()
{
	srand((unsigned int)time(NULL));
	
	char	***m1;
	char	***m2;
	char	***m3;

	daft_init();
	m1 = daft_get("[BULBASAUR");
	test_print(m1);
	m2 = daft_get("CALYREX");
	m3 = daft_get("CALYREX");
	(void)m2, (void)m3;
	daft_quit();
	return (0);
}

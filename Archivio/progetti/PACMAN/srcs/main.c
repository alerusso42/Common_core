/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:03:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 19:52:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

/*
TODO
	[]	commentare roba
	[]	controllo su append con key già esistente
	[]	esport su android
*/

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

	(void)m1, (void)m2, (void)m3;
	if (daft_init())
		return (1);
	daft_swap(POKEDEX);
	m1 = daft_append("CALYREX", 9, 2);
	ft_strlcpy(m1[1][0], "FIRE", 5);
	ft_strlcpy(m1[1][1], "FIGHT", 6);
	ft_strlcpy(m1[1][2], "GABIBBO", 8);
	daft_quit();
	return (0);
}

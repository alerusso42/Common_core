/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:03:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 23:25:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

/*
TODO
	[]	commentare roba
	[]	controllo su append con key già esistente
	[]	esport su android
*/

int	main1()
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

int	main3()
{
	srand((unsigned int)time(NULL));
	
	char	***m1;
	char	***m2;
	char	***m3;

	(void)m1, (void)m2, (void)m3;
	if (daft_init())
		return (1);
	daft_swap(POKEDEX);
	m1 = daft_append("CRAZY", 9, 2);
	ft_strlcpy(m1[1][0], "FIRE", 5);
	ft_strlcpy(m1[1][1], "FIGHT", 6);
	ft_strlcpy(m1[1][2], "GABIBBO", 8);
	daft_quit();
	return (0);
}

int	main4()
{
	srand((unsigned int)time(NULL));
	
	char	**m1;

	if (daft_init())
		return (1);
	daft_swap(MEDIA_LIST);
	m1 = daft_append("CRAZY", 20, 10);
	ft_strlcpy(m1[1], "FIRE", 5);
	ft_strlcpy(m1[2], "FIGHT", 6);
	ft_strlcpy(m1[3], "GABIBBO", 8);
	daft_load();
	m1 = daft_edit("CRAZY", 20, 10);
	ft_strlcpy(m1[1], "WATER", 5);
	ft_strlcpy(m1[2], "FOOO", 6);
	ft_strlcpy(m1[3], "MEGA_GABIBBO", 13);
	daft_load();
	m1 = daft_get("CRAZY");
	for (int i = 0; m1[i]; i++)
	{
		printf("%s\n", m1[i]);
	}
	daft_quit();
	return (0);
}

int	main()
{
	srand((unsigned int)time(NULL));
	
	char	***m1;

	if (daft_init())
		return (1);
	daft_swap(POKEDEX);
	m1 = daft_append("CRAZY", 200, 100);
	ft_strlcpy(m1[1][0], "FIRE", 5);
	ft_strlcpy(m1[1][1], "FIGHT", 6);
	ft_strlcpy(m1[5][2], "GABIBBO", 8);
	ft_strlcpy(m1[6][3], "GABIBBOo", 9);
	ft_strlcpy(m1[7][4], "GABIBBOoo", 10);
	ft_strlcpy(m1[8][5], "GABIBBOooo", 11);
	ft_strlcpy(m1[9][6], "GABIBBOooo", 11);
	daft_load();
	m1 = daft_edit("CRAZY", 200, 100);
	ft_strlcpy(m1[1][0], "WATER", 6);
	ft_strlcpy(m1[1][1], "FIRE", 5);
	ft_strlcpy(m1[5][2], "RAYQUAZ", 8);
	ft_strlcpy(m1[6][3], "RAYQUAZo", 8);
	ft_strlcpy(m1[7][4], "RAYQUAZoo", 8);
	ft_strlcpy(m1[8][5], "RAYQUAZooo", 8);
	ft_strlcpy(m1[9][6], "RAYQUAZooo", 8);
	daft_load();
	m1 = daft_get("CRAZY");
	test_print(m1);
	daft_quit();
	return (0);
}

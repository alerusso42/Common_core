/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:22:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/29 17:22:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_malloc.h"

void	test();

int	main()
{
	char		*s;
	const int	size = 7;

	perror("Checking errno...");
	s = malloc(size + 1);
	perror("Checking errno...");
	if (!s)
		return (perror("Error\n"), 1);
	for (int i = 0; i < size; i++)
		s[i] = 'A' + i;
	s[size] = 0;
	write(1, s, size);
	write(1, "\n", 1);
	free(s);
	test();
}

#include "../libft.h"
void	test()
{
	int	i;
	int	j;

	daft_init();
    daft_swap(2);
	char	***matr = daft_get("CALYREX");
	if (!matr)
		return (daft_quit());
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
		return (daft_quit());
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

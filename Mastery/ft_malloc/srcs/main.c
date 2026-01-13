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

# include "../includes/malloc_internal.h"

void	test();

/*
//FIXME
1)	fixare main 2
2)	fixare calcolo longest_chunk
3)	stampa puntatore in esadecimale
//TODO
1)	allineamento pagina
2)	realloc
3)	pulizia codice
4)	cartella con test automatizzati
5)	show_alloc_mem_ex()		
6)	environmental variables			
*/
int	main0()
{
	char	*p[100];
	const int	size = 25;

	for (int i = 0; i != 50; i++)
		p[i] = malloc(size);
	show_alloc_mem();
	for (int i = 0; i != 25; i++)
		free(p[i]);
	show_alloc_mem();
	for (int i = 50; i != 100; i++)
		p[i] = malloc(size);
	show_alloc_mem();
	for (int i = 25; i != 100; i++)
		free(p[i]);
	show_alloc_mem();
	return 0;
}

int	main()
{
	char	*p[300];
	const int	size = 1;

	for (int i = 0; i != 300; i++)
		p[i] = malloc(size);
	show_alloc_mem();
	for (int i = 0; i != 300; i++)
		free(p[i]);
	show_alloc_mem();
	return 0;
}

int	main2()
{
	char		*s;
	const int	size = 7;

	ft_printf("stack starts with: %p,%p\n", &s, &size);
	ft_printf("pagesize: %d\n", sysconf(_SC_PAGE_SIZE));
	perror("Checking errno...");
	s = malloc(size + 1);
	free(malloc((int)1e6));
	perror("Checking errno...");
	if (!s)
		return (perror("Error\n"), 1);
	for (int i = 0; i < size; i++)
		s[i] = 'A' + i;
	s[size] = 0;
	ft_printf("%s\n", s);
	free(s);
	test();
	//print_extreme(NULL, _global_data(false), true);
	ft_printf("Program end!\n");
	ft_printf("Internal Leak check: ");
	if (_global_data(false)->bytes_alloc == _global_data(false)->bytes_freed)
		ft_printf("$GSuccess!$z\n");
	else
	{
		ft_printf("$RLeak! $z%d allocated, %d freed\n", _global_data(false)->bytes_alloc, _global_data(false)->bytes_freed);
		ft_printf("Total leak: %d\n", _global_data(false)->bytes_alloc - _global_data(false)->bytes_freed);
	}
	return (0);
}

void	test()
{
	int	i;
	int	j;

	daft_init("media", "SETTINGS.md");
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

/*
	first-freed
	
	++++
	++
	+
	+-++-++-+-++-++++
	/\
   /  \
  /    \
 /\
   \
	\
	 \
*/

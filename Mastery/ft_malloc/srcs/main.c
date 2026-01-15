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

void	test(char *pokemon);

/*
//FIXME
OK)	fixare main 2
2)	fixare calcolo longest_chunk
3)	stampa puntatore in esadecimale
//TODO
OK)	allineamento pagina
2)	realloc
3)	pulizia codice
4)	cartella con test automatizzati
5)	show_alloc_mem_ex()		
6)	environmental variables			
*/

void	fill(char **s, int size)
{
	static int	type = 'A';

	//fd_printf(2, "size %d\n", size);
	*s = malloc(size + 1);
	(*s)[size] = 0;
	while (--size > 0)
	{
		(*s)[size] = type;
	}
	(*s)[0] = type;
	if (type == 'Z')
		type = 'A';
	else
		type++;
}

void	release(char *s)
{
	//ft_printf("Print of %p:\t%s\n", s, s);
	free(s);
}

int	get_size()
{
	static int test;
	//return (rand() % 12345);
	char	*s = gnl();
	if (!s)
		return (++test);
	int		size = ft_atoi(s);
	free(s);
	return (size);
}
//((t_area *)(((void*)p[0]) - sizeof(t_area)))->info
#include <sys/time.h>
int	main1()
{
	char	*p[100];
	struct timeval	t;
	void	*pt[4];
(void)pt;
/*show_alloc_mem();
pt[0] = malloc(5);
show_alloc_mem();
pt[1] = malloc(15);
show_alloc_mem();
pt[2] = malloc(5000000);
show_alloc_mem();
free(pt[0]);
show_alloc_mem();
free(pt[1]);
show_alloc_mem();
free(pt[2]);
show_alloc_mem();*/
	if (openfd("test_file1", "a+").p == 0)
		return 1;
	gettimeofday(&t, NULL);
	srand(t.tv_sec);
	const int	max_size = get_size();
	(void)max_size;
	//fd_printf(2, "max size %d\n", max_size);
	for (int i = 0; i != 50; i++)
	{
		fill(&p[i], get_size());
		show_alloc_mem();
	}
	for (int i = 0; i != 25; i++)
	{
		release(p[i]);
		show_alloc_mem();
	}
	for (int i = 50; i != 100; i++)
	{
		fill(&p[i], get_size());
		show_alloc_mem();
	}
	show_alloc_mem();
	for (int i = 25; i != 100; i++)
	{
		release(p[i]);
		show_alloc_mem();
	}
	del_filedata();
	return 0;
}

int	main2()
{
	char	*p[300];
	const int	size = 1234;

	for (int i = 0; i != 300; i++)
		p[i] = malloc(size);
	show_alloc_mem();
	for (int i = 0; i != 300; i++)
		free(p[i]);
	show_alloc_mem();
	return 0;
}

int	main(int ac, char **av)
{
	char		*s;
	const int	size = 7;

	if (ac == 1)
		return (ft_printf("arg required: insert pokemon\n"));
	ft_printf("stack starts with: %p,%p\n", &s, &size);
	ft_printf("pagesize: %d\n", sysconf(_SC_PAGE_SIZE));
	ft_printf("max align: %d\n", ALIGN);
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
	test(av[1]);
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
	del_filedata();
	//show_alloc_mem();
	return (0);
}

void	test(char *pokemon)
{
	int	i;
	int	j;
	int	fd;
	fd = openfd("test_file", "w").p, (void)fd;

	daft_init("media", "SETTINGS.md");
    daft_swap(2);
	char	***matr = daft_get(pokemon);
	if (!matr)
		return (daft_quit());
	i = 0;
	while (matr[i])
	{
		j = 0;
		while (matr[i][j])
		{
			ft_printf("%s\n", matr[i][j]);
			j++;
		}
		i++;
	}
	char	***add = daft_append("SQUALO", 0, 0);
	//show_alloc_mem();
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

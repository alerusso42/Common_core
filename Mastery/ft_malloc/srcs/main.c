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

void	test(void);

/*
//FIXME
OK)	fixare main 2
OK)	fixare calcolo longest_chunk
3)	stampa puntatore in esadecimale
//TODO
OK)	allineamento pagina
1)	testare pool_realloc
2)	realloc
3)	pulizia codice
4)	cartella con test automatizzati
5)	show_alloc_mem_ex()		
6)	environmental variables
7)	create libreria ammodino come vuole il subject			
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
int	main()
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
	gettimeofday(&t, NULL);
	srand(t.tv_sec);
	const int	max_size = rand() % 5;
	//fd_printf(2, "max size %d\n", max_size);
	for (int i = 0; i != 50; i++)
	{
		fill(&p[i], rand() % max_size);
		show_alloc_mem_ex(2 | MALL_SHOW_SILENT_FREED);
	}
	for (int i = 0; i != 25; i++)
	{
		release(p[i]);
		show_alloc_mem_ex(2 | MALL_SHOW_SILENT_FREED);
	}
	for (int i = 50; i != 100; i++)
	{
		fill(&p[i], rand() % max_size);
		show_alloc_mem_ex(2 | MALL_SHOW_SILENT_FREED);
	}
	show_alloc_mem_ex(2 | MALL_SHOW_SILENT_FREED);
	for (int i = 25; i != 100; i++)
	{
		release(p[i]);
		show_alloc_mem_ex(2 | MALL_SHOW_SILENT_FREED);
	}
	del_filedata();
	return 0;
}

void	__attribute__((constructor, used)) func()
{
	ft_printf("apro\n");
}

void	__attribute__((destructor, used)) func2()
{
	ft_printf("chiudo\n");
}

// -Wno-unused-result
int	main2()
{
	const int	ptrs = 30;
	char	*p[ptrs];
	const int	size = 249;

	show_alloc_mem_ex(256);
	for (int i = 0; i != ptrs / 2; i++)
	{
		show_alloc_mem_ex(256);
		p[i] = malloc(size);
	}
	for (int i = 0; i != ptrs / 4; i++)
	{
		show_alloc_mem_ex(256);
		free(p[i]);
	}
	for (int i = ptrs / 2; i != ptrs; i++)
	{
		show_alloc_mem_ex(256);
		p[i] = malloc(size);
	}
	for (int i = ptrs / 4; i != ptrs; i++)
	{
		show_alloc_mem_ex(256);
		free(p[i]);
	}
	show_alloc_mem();
	return 0;
}

int	main3(int ac, char **av)
{
	(void)ac, (void)av;
	char		*s;
	const int	size = 7;

	/*if (ac == 1)
		return (ft_printf("arg required: insert pokemon\n"));*/
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
	del_filedata();
	//show_alloc_mem();
	return (0);
}

void	print_3d(char ***);

void	test(void)
{
	char	***data;

	daft_init("media", "SETTINGS.md");
	daft_init(NULL, NULL);
    daft_swap(POKEDEX);
	data = daft_get("CALYREX");
	if (!data)
		return (daft_quit());
	print_3d(data);
	data = daft_append("IR_GABIBBO", 0, 0);
	print_3d(data);
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
	daft_init("media", "SETTINGS.md");
	daft_swap(POKEDEX);
	while (daft_iter((void **)&data))
		print_3d(data);
	daft_quit();
}

void	print_3d(char ***s)
{
	return ;
	if (s)
	{
		for (int i = 0; s[i]; i++)
			for (int j = 0; s[i][j]; j++)
				ft_printf("%s\n", s[i][j]);
	}
}

int	main6()
{
	char	*base = "NEGRO";
	size_t	base_len = ft_strlen(base);
	size_t	n_append = 42;
	size_t	cursor;
	char	*s;

	s = malloc(base_len);
	s = realloc(s, base_len * 42 + 1);
	for (size_t i = 0; i != n_append; i++)
	{
		cursor = i * base_len;
		ft_strlcat(s + cursor, base, base_len + 1);
	}
	ft_printf("base: %s; s: %s\n", base, s);
	free(s);
	s = calloc(5, 10);
	for (int i = 0; i != 65; i++)
		write(1, &s[i], 1);
	ft_printf("\n");
	return 0;
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

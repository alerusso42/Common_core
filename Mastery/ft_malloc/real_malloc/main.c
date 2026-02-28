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

# include "all.h"
# include <malloc.h>

void	test();
void	print_3d(char ***s);

/*int	main2()
{
	char	*stringa = malloc_file(15, "per_malloc");
	ft_strlcpy(stringa, "ciao", 5);
	ft_printf(stringa);
	return 1;
}*/

int	main(int ac, char **av)
{
	(void)ac, (void)av;
	char				*s;
	const int			size = 7;
	struct mallinfo2	mData;

	/*if (ac == 1)
		return (ft_printf("arg required: insert pokemon\n"));*/
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
	//print_extreme(NULL, malloc_global_data(false), true);
	ft_printf("Program end!\n");
	ft_printf("Internal Leak check: ");
	mData = mallinfo2();
	if (mData.uordblks == mData.fordblks)
		ft_printf("$GSuccess!$z\n");
	else
	{
		ft_printf("$RLeak! $z%d allocated, %d freed\n", mData.uordblks, mData.fordblks);
		ft_printf("Total leak: %d\n", mData.uordblks - mData.fordblks);
	}
	del_filedata();
	FILE	*f = fopen("/dev/tty", "w");
	malloc_info(0, f);
	return (0);
}

void	print_3d(char ***);

void	test(void)
{
	char	***data;

	daft_init("../media", "SETTINGS.md");
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
		daft_init("../media", "SETTINGS.md");
		daft_init("../media", "SETTINGS.md");
		daft_init("../media", "SETTINGS.md");
		daft_quit();
		daft_quit();
		daft_init("../media", "SETTINGS.md");
	}
	daft_quit();
	daft_init("../media", "SETTINGS.md");
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

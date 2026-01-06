/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:35:49 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/06 13:00:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	header(const char *name);
void		test_args(int ac, char **av);
void		test_rect(void);
void		test_buff(void);

int	main(int ac, char **av)
{
	(void)ac, (void)av;

	ft_printf("$\\");
	header("args");
	test_args(ac, av);
	header("clear");
	ft_printf("$!2$0");
	header("column test");
	ft_printf("$\\1$\\1$\\1ciao da -3!\n");
	ft_printf("\033[B\033[B\033[Bciao da -3!\n");
	header("rectangle test");
	test_rect();
	header("buffer test");
	test_buff();
	header("command test");
	const int time = 3;
	ft_printf("aspetto %d secondi... ?%p-%d?fine attesa!\n", time, sleep, time);
	str_terminate();
}

static void	header(const char *name)
{
	static int	test;

	ft_printf("$z$GTest $Y%d$G:\t$Y%s$z\n", test++, name);
}

void	test_args(int ac, char **av)
{
	char	**temp = av;

	while (ac--)
	{
		ft_printf("%s\n", *av);
		++av;
	}
	av = temp;
}

static void	line(char c, int times);

void	test_rect(void)
{
	const int	w = 15;
	const int	w_tab = 2;
	const int	h = 5;
	const int	h_tab = 2;

	ft_printf("$>%d$\\%d$1", w_tab, h_tab);
	ft_printf("X");
	line('-', w);
	ft_printf("X$2$\\1");
	for (int i = h; i; i--)
	{
		ft_printf("$1|$V$X");
		line('a', w);
		ft_printf("$z|$2$\\1");
	}
	ft_printf("$1X");
	line('-', w);
	ft_printf("X$2$\\1$<5");
}

static void	line(char c, int times)
{
	char	buff[2] = "";

	if (!c)
		return (ft_printf("$>%d", times), (void)0);
	*buff = c;
	while (times--)
	{
		if (*buff)
			ft_printf(buff);
	}
}

static void	line_buff(char c, int times, t_str *buff);

void		test_buff(void)
{
	const int	w = 15;
	const int	w_tab = 2;
	const int	h = 5;
	const int	h_tab = 2;
	STR(buff, "");

	str_printf(&buff, "$>%d$\\%d$1", w_tab, h_tab);
	str_printf(&buff, "X");
	line_buff('-', w, &buff);
	str_printf(&buff, "X$2$\\1");
	for (int i = h; i; i--)
	{
		str_printf(&buff, "$1|$V$X");
		line_buff('a', w, &buff);
		str_printf(&buff, "$z|$2$\\1");
	}
	str_printf(&buff, "$1X");
	line_buff('-', w, &buff);
	str_printf(&buff, "X$2$\\1$<5");
	ft_printf(buff.buff);
}

static void	line_buff(char c, int times, t_str *buff)
{
	char	temp[2] = "";

	if (!c)
		return (str_printf(buff, "$>%d", times), (void)0);
	*temp = c;
	while (times--)
	{
		str_printf(buff, temp);
	}
}

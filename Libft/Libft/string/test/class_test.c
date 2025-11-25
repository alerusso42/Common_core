/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:15:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/25 22:27:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string.h"

void	psection(char *s)
{
	static int	n = 1;

	printf("\033[34m----------------------------\033[35m\n");
	printf("SECTION %d:\n", n);
	printf("%s\n", s);
	printf("\033[34m----------------------------\033[0m\n");
	++n;
}

void	ptest(char *s)
{
	static int	n = 1;

	printf("\033[33m----------------------------\033[32m\n");
	printf("TEST %d:\n", n);
	printf("%s\n", s);
	printf("\033[33m----------------------------\033[0m\n");
	++n;
}

int	test1()
{
	ptest("find substr ROCKY and deletes it");

	STR(s, "ROCKI ROCK ROOCKY CKY OCKY ROCK YROCKY ROCCKY AAA");
	STR(s2, "ROCKY");
	STR(s3, "");

	sdup(&s3, &s2)->m->find(&s, &s2)->m->cut(&s, s.i, s.i + s2.len);
	return (0);
}

int	test2(void)
{
	ptest("Prints string begin, half, end. Overrides char from begin to half");

	STR(trim_s, "str ");
	STR(s1, "str Bosio");
	STR(s2, "str Rayquaza");
	char	*trim_c = "str ";

	find(&s1, &trim_s)->m->cut(&s1, s1.i, trim_s.len);
	find(&s2, trim_c)->m->cut(&s2, s2.i, ft_strlen(trim_c));
	return (0);
}

int	test3()
{
	ptest("Prints string begin, half, end. Overrides char from begin to half");

	STR(s, "MEGA_RAYQUAZA");

	printf("BEGIN[%s][%ld]\n", (char *)s.begin, s.begin);
	printf("HALF[%s][%ld]\n", (char *)s.half, s.half);
	printf("END[%s][%ld]\n", (char *)s.end, s.end);

	for (uintptr_t i = s.begin; i < s.half; i++)
		*(char *)i = 'A';
	printf("%s\n", s.buff);
	return (0);
}

int	test4(char **av)
{
	ptest("Append argv to front and back of an empty string");

	STR(s, "");

	for (int i = 0; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			addr(&s, av[i][j]);
			addl(&s, av[i][j]);
		}
	}
	return (0);
}

int	test5()
{
	ptest("Copy matrix until \\n");

	STR(s, "                 ");
	char	matr[5][8] = {"ciao,\n", " come\n", " stai?\n", ""};

	for (int i = 0; matr[i][0]; i++)
	{
		printf("%s\n", s.buff);
		excpy(&s, matr[i], "\n");
		s.i += ft_strlen(matr[i]) - 1;
	}
	return (0);
}

int	test6()
{
	ptest("Sort");

	STR(s, "38573847183471834701401840912841822110002321");

	sort(&s);
	return (0);
}

int	test7()
{
	ptest("Reverse");

	STR(s, "Ale Alle Allllle   -><-");

	reverse(&s);
	return (0);
}

int	test8(char *n1, char *n2)
{
	ptest("Join");

	STR(m, n2);
	join(&m, " with ", 0)->m->join(&m, n1, 0)->m->join(&m, "Sum of ", 0);
	return (0);
}

int	test_sum(char *n1, char *n2)
{
	ptest("Sum of argv[1] with argv[2]");

	STR(s, n1);
	STR(s2, n2);
	STR(final, "");
	int	temp1;
	int	temp2;

	if (!n1 || !n2)
		return (1);
	if (satoi(&s, &temp1) != 0 || satoi(&s2, &temp2) != 0)
		return (1);
	temp1 = temp1 + temp2;
	itoa(&final, temp1);
	printf("Result:\t%s\n", final.buff);
	return (0);
}

//FIXME - 
/*
	1)	cpy, ncpy, scpy, join should move the iterator at the end of the copy;
	2)	add a print function (later, when fd_printf available).
*/
int	main(int ac, char **av)
{
	test1();
	test2();
	test3();
	test4(av);
	test5();
	test6();
	test7();
	if (ac < 3)
		return (0);
	test_sum(av[1], av[2]);
	test8(av[1], av[2]);
	return (0);
}

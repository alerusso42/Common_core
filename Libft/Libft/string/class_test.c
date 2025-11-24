/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:15:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 23:43:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	test1()
{
	STR(s, "ROCKI ROCK ROOCKY CKY OCKY ROCK YROCKY ROCCKY AAA");
	STR(s2, "ROCKY");
	STR(s3, "");
	sdup(&s3, &s2)->m->find(&s, &s2)->m->cut(&s, s.i, s.i + s2.len);
	return (0);
}

int	test2()
{
	STR(s, "MEGA_RAYQUAZA");

	printf("BEGIN[%s][%ld]\n", (char *)s.begin, s.begin);
	printf("HALF[%s][%ld]\n", (char *)s.half, s.half);
	printf("END[%s][%ld]\n", (char *)s.end, s.end);

	for (uintptr_t i = s.begin; i < s.half; i++)
		*(char *)i = 'A';
	printf("%s\n", s.buff);
	return (0);
}

int	test3(void)
{
	STR(trim_s, "str ");
	STR(s1, "str Bosio");
	STR(s2, "str Rayquaza");
	char	*trim_c = "str ";

	find(&s1, &trim_s)->m->cut(&s1, s1.i, trim_s.len);
	find(&s2, trim_c)->m->cut(&s2, s2.i, ft_strlen(trim_c));
	return (0);
}

int	test4(char **av)
{
	STR(s, "");

	while (av && *av)
	{
		while (**av)
		{
			addr(&s, **av);
			addl(&s, **av);
			++(*av);
		}
		av += *av != NULL;
	}
	return (0);
}

int	test_sum(char *n1, char *n2)
{
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

int	main(int ac, char **av)
{
	(void)ac, (void)av;
	return (test_sum(av[1], av[2]));
}

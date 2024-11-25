/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:27:17 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:28:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define TRUE 1
#define FALSE 0
#define GO_RIGHT 0
#define GO_LEFT 1

char 		*ft_strtrim(char const *s1, char const *set);
static char	*trimmer(const char *s1, const char *set, int go_left);	

char *ft_strtrim(char const *s1, char const *set)
{
	char	*trimmered_string;
	char	*save_left_position;
	char	*save_right_position;
	size_t	size;

	if ((!s1) || (!set) || (*s1 == '\0') || (*set == '\0'))
		return ((char *)s1);
	save_left_position = trimmer(s1, set, GO_RIGHT);
	if (s1 == save_left_position)
		return ("\0");
	while (*s1 != '\0')
		++s1;
	save_right_position = trimmer(--s1, set, GO_LEFT);
	s1 = save_left_position;
	size = 0;
	while (s1++ != save_right_position)
		++size;
	trimmered_string = (char *)malloc(size + 2);
	if (trimmered_string == NULL)
		return (NULL);
	s1 = save_left_position;
	size = 0;
	while (s1 != save_right_position + 1)
		trimmered_string[size++] = *s1++;
	trimmered_string[size] = '\0';
	return (trimmered_string);
}

static char	*trimmer(const char *s1, const char *set, int go_left)
{
	char	*save_pointer;
	
	save_pointer = (char *)s1;
	while (*s1)
	{
		if (ft_strrchr(set, *s1) == FALSE)
		{
			return ((char *)&(*s1));
		}
		if (go_left == FALSE)
			++s1;
		if (go_left == TRUE)
			--s1;
	}
	return (save_pointer);
}

int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	char	*stringhina;

	if (argc < 3)
	{
		printf("s1 = argv[1]; set = argv[2]");
		return (42);
	}
	s1= argv[1];
	s2 = argv[2];
	stringhina = ft_strtrim(s1, s2);
	printf("\n STRINGHE\ns1: %s;\nset: %s\n", s1, s2);
	printf("\n STRINGHINA:%s\n", stringhina);
	return (0);
}

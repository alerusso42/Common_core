/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:08:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/10 00:31:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

size_t	ft_strlen(const char *string)
{
	unsigned int	index;

	index = 0;
	while (string[index])
		++index;
	return (index);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*pointer;

	if ((!dest) && (!src))
		return (NULL);
	pointer = dest;
	while ((n--) && (dest))
	{
		*((char *)dest) = *((char *)src);
		++dest;
		++src;
	}
	return (pointer);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;
	char	*char_pointer;
	void	*save;

	pointer = NULL;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	save = pointer;
	char_pointer = (char *)pointer;
	while (total_size--)
		*char_pointer++ = 0;
	return (pointer);
}

static int	ft_realloc(void **content, size_t nmemb, size_t size)
{
	void	*re_content;

	re_content = ft_calloc(nmemb, size);
	if (!(re_content))
		return (1);
	ft_memcpy(re_content, *content, nmemb - size);
	free(*content);
	*content = re_content;
	return (0);
}

int	cut_string(char **string, size_t start, size_t end)
{
	unsigned int	temp;
	unsigned int	string_len;

	if (!(string) || !(*string) || !(**string) || (start > end))
		return (1);
	end++;
	string_len = ft_strlen(*string);
	temp = start;
	while ((start != end) && ((*string)[start] != 0))
		(*string)[start++] = 0;
	end = start;
	start = temp;
	temp = 0;
	while (end != string_len)
	{
		(*string)[start + temp] = (*string)[end + temp];
		--string_len;
		++temp;
	}
	if (temp != 0)
		(*string)[temp + start] = 0;
	end = ft_strlen(*string);
	ft_realloc((void **)string, end + 2, sizeof(char));
	return (0);
}

void	test(char **string, char *copy, int from, int to)
{
	*string = strdup(copy);
	printf("cut from %d to %d: result:\n", from, to);
	cut_string(string, from, to);
	printf("---> %s\n", *string);
	free(*string);
	*string = NULL;
}

/*
int	main()
{
	char	*string;
	int		len;
	char	copy[20] = "0123456789";

	string = NULL;
	len = strlen(copy) - 2;
	printf("test made with the string \"0123456789\" (len = 10).\n\n");
	printf("test with from == 0:\n");
	test(&string, copy, 0, 8);
	test(&string, copy, 0, 4);
	test(&string, copy, 0, 2);
	test(&string, copy, 0, 1);
	test(&string, copy, 0, 0);
	test(&string, copy, 0, 1000);
	test(&string, copy, 0, 9);
	test(&string, copy, 0, 10);
	printf("test with from == 3:\n");
	test(&string, copy, 3, 8);
	test(&string, copy, 3, 4);
	test(&string, copy, 3, 2);
	test(&string, copy, 3, 1);
	test(&string, copy, 3, 0);
	test(&string, copy, 3, 1000);
	test(&string, copy, 3, 9);
	test(&string, copy, 3, 10);
	printf("test with to == 8:\n");
	test(&string, copy, 3, len);
	test(&string, copy, 3, len);
	test(&string, copy, 3, len);
	test(&string, copy, 3, len);
	test(&string, copy, 3, len);
	test(&string, copy, 3, len);
	test(&string, copy, 3, len);
	test(&string, copy, 3, len);
}*/
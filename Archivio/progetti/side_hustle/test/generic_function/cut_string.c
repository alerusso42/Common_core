/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:08:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/03 17:06:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>

static size_t	ft_strlen(const char *string)
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

	end++;
	if (!(string) || !(*string) || (start > end))
		return (1);
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
		(*string)[temp] = 0;
	end = ft_strlen(*string);
	if (ft_realloc((void **)string, end, sizeof(char)))
		return (1);
	return (0);
}
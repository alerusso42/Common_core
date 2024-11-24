/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/13 09:58:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
/*
int	main()
{
	char	dest[20] = "1337 42";
	char	src[20] = "Born to code";
	unsigned int	size = 7;

	size = ft_strlcat(dest, src, size);
	printf("Ecco qua campione: l: %d; %s", size, dest);
	return (0);
}*/

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = -1;
	dest_len = 0;
	src_len = 0;
	while (dest[++i])
		++dest_len;
	i = -1;
	while (src[++i])
		++src_len;
	i = 0;
	while (((i + dest_len) < size) && (src[i] != '\0'))
	{
		dest[dest_len + i] = src[i];
		++i;
	}
	dest[dest_len + i] = '\0';
	return (src_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/18 19:18:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	byte;

	string = (unsigned char *)s;
	byte = (unsigned char)c;
	while ((string) && (n--))
	{
		if (*string == byte)
		{
			return ((void *)string);
		}
		string++;
	}
	return (NULL);
}

/*
int main()
{
    printf("%s\n", (char *)ft_memchr("Mega_rayquaza", '\0', 2));
    return (0);
}*/

/*
#define POKEDEX "../../../../getnextline/updated_pokedex.txt"
#define TEST "../tests/long.txt"
#include <unistd.h>
#include <malloc.h>
#include <fcntl.h>
int main()
{
	int	fd = open(TEST, O_RDONLY);
	char *s = malloc(500 * 1000000);
	int size = read(fd, s, 500 * 1000000 - 1);
	s[size] = 0;
	char	*tmp = alg_memchr(s, "hid");
	write(1, tmp, 12);
    free(s);
	close(fd);
	return (0);
}

int maina()
{
	unlink(TEST);
	int	fd2 = open(TEST, O_CREAT | O_RDWR, 0666);
	int i = 500000;
	while (i--)
		write(fd2, "ROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKY\n", 401);
	write(fd2, "hidden", 6);
	i = 50000;
	while (i--)
		write(fd2, "ROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKYROCKY\n", 401);
	close(fd2);
	return (0);
}
*/

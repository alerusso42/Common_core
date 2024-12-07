/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/15 11:57:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		alloc(char **bigshow, int temp, int size, char *sep);
void	copy(char **strs, char *bigshow, int size, char *sep);
// Uso di strcpy per inizializzare le stringhe!
/*
int main(int argc, char *argv[])
{
    int size;
    char    *strs[5];

	if (argc != 3)
	{
		printf("argv[1] = size, argv[2] = sep\n");
		return (42);
	}
    size = atoi(argv[1]);
	printf("Size: %d\n", size);
    printf("Separatore: %s\n", argv[2]);
    strs[0] = (char *)malloc(30 * sizeof(char));
    strs[1] = (char *)malloc(30 * sizeof(char));
    strs[2] = (char *)malloc(30 * sizeof(char));
    strs[3] = (char *)malloc(30 * sizeof(char));
    strs[4] = (char *)malloc(30 * sizeof(char));

    if (!strs[0] || !strs[1] || !strs[2] || !strs[3] || !strs[4])
    {
        printf("Errore di allocazione della memoria\n");
        return (42);
    }
    strcpy(strs[0], "IlGabibbo");
    strcpy(strs[1], "Ezio");
    strcpy(strs[2], "Shrek");
    strcpy(strs[3], "ROCKY");
    strcpy(strs[4], "KIRAAAAAAAAAA");
    printf("%s\n", ft_strjoin(size, strs, argv[2]));
    free(strs[0]);
    free(strs[1]);
    free(strs[2]);
    free(strs[3]);
    free(strs[4]);
	return (0);
}*/
// Tre parti:
// 1) Trovare quanti caratteri dobbiamo allocare (58);
// 2) Allocare la memoria (alloc);
// 3) Riempire il nuovo array con le stringhe (copy).

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		temp;
	int		str_count;
	char	*bigshow;

	str_count = -1;
	i = -1;
	temp = 0;
	while (++str_count < size)
	{
		while (strs[str_count][++i])
			++temp;
		i = -1;
	}
	if ((alloc(&bigshow, temp, size, sep) == 42))
		return (bigshow);
	copy(strs, bigshow, size, sep);
	return (bigshow);
}
// Se size o temp(= numero caratteri) sono nulli, esce.

int	alloc(char **bigshow, int temp, int size, char *sep)
{
	int	sep_len;

	if ((temp <= 0) || (size <= 0))
	{
		*bigshow = (char *)malloc(sizeof(char));
		*bigshow[0] = '\0';
		return (42);
	}
	sep_len = 0;
	while (sep[sep_len] != '\0')
		++sep_len;
	*bigshow = (char *)malloc(((temp + (size - 1)) * sep_len) * sizeof(char));
	if ((*bigshow == NULL))
		return (42);
	return (0);
}

void	copy(char **strs, char *bigshow, int size, char *sep)
{
	int	i;
	int	big_i;
	int	str_count;

	str_count = -1;
	big_i = -1;
	while ((++str_count != size))
	{
		i = -1;
		while (strs[str_count][++i] != '\0')
			bigshow[++big_i] = strs[str_count][i];
		i = -1;
		while (((str_count + 1) != size) && (sep[++i] != '\0'))
			bigshow[++big_i] = sep[i];
	}
}

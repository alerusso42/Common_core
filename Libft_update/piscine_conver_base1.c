/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_conver_base1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 12:39:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>

char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
int			ft_atoi_base(char *str, char *base);
int			find_base(char *base);
int			ft_atoi(char *str, char *base, int base_len, int i);
int			ft_exp(int base, int power);
int			convert_nbr_values(char temp, char *base);
char		*ft_putnbr_base(int nbr, char *base, char *print);
void		convert_from_base10(int nbr, char *base, int base_len, \
	char *print);
static void	ft_strcpy(char **dest, char *src);
void		ft_invert_array(char **arr);
/*

int main(int argc, char *argv[])
{
    char    *result;

    if (argc != 4)
    {
        printf("argv[1] = numero in una base qualsiasi\n");
        printf("argv[2] = base di partenza\n");
        printf("argv[3] = base di arrivo\n");
        printf("Il programma fa la conversione del ");
        printf("numero da una base all'altra.\n");
        printf("Restituisce come stringa il nuovo numero.\n");
        printf("Inserire 3 argomenti validi.\n");
        return (42);
    }
    ft_strcpy(&result, ft_convert_base(argv[1], argv[2], argv[3]));
    printf("Numero di partenza: %s\n", argv[1]);
    printf("Base di partenza: %s\n", argv[2]);
    printf("Base di arrivo: %s\n", argv[3]);
    printf("Conversione: %s\n", result);
    free(result);
    return (0);
}*/
// Sulla carta a malloc bastano 34 byte (min binario = 32 caratteri + "-" + \0)
// Tuttavia, sperimentalmente ne bastano 25. Come mai?

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_base_ten;
	char	*nbr_new_base;
	char	*print;

	if ((find_base(base_from)) == -1 || (find_base(base_to) == -1))
		return (NULL);
	nbr_base_ten = ft_atoi_base(nbr, base_from);
	print = (char *)malloc(34 * sizeof(char));
	print[0] = '0';
	print[1] = '\0';
	ft_strcpy(&nbr_new_base, ft_putnbr_base(nbr_base_ten, base_to, print));
	ft_invert_array(&nbr_new_base);
	free(print);
	return (nbr_new_base);
}

static void	ft_strcpy(char **dest, char *src)
{
	int	i;

	i = 0;
	if (*dest == NULL)
		free(*dest);
	while (src[i] != '\0')
		++i;
	if (i != 0)
		*dest = (char *)malloc(i * sizeof(char));
	if (i != 0)
	{
		i = 0;
		(*dest)[i] = src[i];
		while (src[++i] != '\0')
			(*dest)[i] = src[i];
		(*dest)[i] = src[i];
	}
}

// Il programma fa una normale conversione, poi prende
// gli indici della base per trasformare il numero
char	*ft_putnbr_base(int nbr, char *base, char *print)
{
	int	base_len;

	base_len = find_base(base);
	if ((nbr != 0) & (base_len != -1))
		convert_from_base10(nbr, base, base_len, print);
	return (print);
}
// Restituisce l'array di valori da stampare e il segno.
// il min int lo gestisce moltiplicando SOLO la prima volta per -1
// così si lavora su numeri positivi.

void	convert_from_base10(int nbr, char *base, int base_len, char *print)
{
	int	sign;
	int	i;
	int	temp;

	i = -1;
	sign = 1;
	if (nbr < 0)
	{
		print[++i] = '-';
		sign = -1;
	}
	while (nbr != 0)
	{
		temp = (nbr % base_len) * sign;
		nbr = (nbr / base_len) * sign;
		sign = 1;
		++i;
		print[i] = base[temp];
	}
	print[++i] = '\0';
}

void	ft_invert_array(char **arr)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while ((*arr)[j] != '\0')
		++j;
	--j;
	if ((*arr)[0] == '-')
		++i;
	while (i < j)
	{
		temp = (*arr)[i];
		(*arr)[i] = (*arr)[j];
		(*arr)[j] = temp;
		++i;
		--j;
	}
}
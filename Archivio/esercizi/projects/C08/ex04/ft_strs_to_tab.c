/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:31:10 by alerusso          #+#    #+#             */
/*   Updated: 2024/10/22 15:11:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <malloc.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
int					ft_strlen(char *str);
int					ft_strcpy(char *dest, char *src);
char				*ft_memset(char *str, int size);
struct s_stock_str	*reset_memory(struct s_stock_str *ptr);

/*
int	main(int argc, char *argv[])
{
	struct s_stock_str	*stock;
	struct s_stock_str	*ptr;
	int					count;

	if (argc < 1)
		return (42);
	stock = ft_strs_to_tab(argc, argv);
	ptr = stock;
	count = 1;
	if (ptr != NULL)
	{
		while (ptr->str != NULL)
		{
			printf("\n\nStringa %d:", count);
			printf("\nSize: %d", ptr->size);
			printf("\nContenuto stringa: %s", ptr->str);
			printf("\nContenuto copia: %s", ptr->copy);
			free(ptr->str);
			free(ptr->copy);
			++count;
			++ptr;
		}
		printf("\n\nTUTTO FATTO!\n");
	}
	else
	{
		printf("Errore nell'allocazione della memoria!\n");
	}
	free(stock);
	return (0);
}
*/

//
// ptr punta a stock.
// Allochiamo due volte: una per la struttura, la seconda per le stringhe.
// La struttura necessita, in teoria, (int)+(char *)+(char *) = 4+8+8=20 bytes.
// sizeof(struct s_stock_str) non è una stima affidabile. Prova a printarlo.
// Perciò, allochiamo 20 bytes per ogni elemento di av, corretto?
// In teoria, sì. In pratica... No. Ne servono 21 per ogni elemento.
// Adesso chiederai: "Perchè 21 e non 20?" Beh, ecco, perchè...
// ...
// .....
// .........
// .............Boh.. ma che ne so..
// Comunque, agiamo su ptr e non su stock per due motivi:
// 1) Vogliamo tornare stock[0], e quando finiamo, stock è a stock[in culo].
// Perciò, anzichè farlo tornare a zero normalmente, ne facciamo una copia.
// 2) Perchè Valgrind fa le bizze: se agiamo direttamente su stock, il
// puntatore sul quale abbiamo allocato memoria, dice: "GNE! MA TE HAI"
// ALLOCATO PER stock[0], NON PER stock[1], stock[2], stock[tua mamma]!
// Pff. Ci vuole pazienza. Quindi lavoriamo su un altro puntatore, così
// stock se ne sta a riposo e valgrind è felice.
//
// Avanziamo lavorando sui puntatori: ++av passa all'elemento successivo di av,
// ++ptr passa all'elemento successivo di stock.
// Impostiamo l'ultimo elemento a NULL, così pure Moulinette è felice.
// Questi algoritmi sono proprio dei bimbi viziati.
// 3 errori comunque permangono, non so come toglierli. Vabbè.
// Se ad un dato momento malloc fallisce, reset_memory resetta tutto.
// Qualche funzione utile per il debug/correzione:
// printf("sizeof struct: %zu", sizeof(struct s_stock_str));
// ft_strcpy(ptr->str, *av);
// ft_strcpy(ptr->copy, *av);
// ptr->copy = (char *)malloc(ptr->size + 100000000000000);
//
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*stock;
	struct s_stock_str	*ptr;

	stock = malloc((21) * (ac + 1));
	if ((stock == NULL))
		return (stock);
	ptr = stock;
	while (--ac >= 0)
	{
		ptr->size = ft_strlen(*av);
		ptr->str = (char *)malloc(ptr->size + 1);
		ptr->copy = (char *)malloc(ptr->size + 1);
		if ((ptr->str == NULL) || (ptr->copy == NULL))
			stock = reset_memory(stock);
		if (stock == NULL)
			return (stock);
		ft_strcpy(ft_memset(ptr->str, ptr->size + 1), *av);
		ft_strcpy(ft_memset(ptr->copy, ptr->size + 1), *av);
		++av;
		++ptr;
	}
	ptr->size = 0;
	ptr->str = NULL;
	ptr->copy = NULL;
	return (stock);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int	ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		++index;
	}
	return (0);
}

char	*ft_memset(char *str, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		str[index] = '0';
		++index;
	}
	str[index] = '\0';
	return (str);
}

// Libera d'ogni 'osa.
struct s_stock_str	*reset_memory(struct s_stock_str *ptr)
{
	struct s_stock_str	*current;

	current = ptr;
	while ((current->str != NULL) || (current->copy != NULL))
	{
		free(current->str);
		free(current->copy);
		current++;
	}
	free(ptr);
	ptr = NULL;
	return (ptr);
}

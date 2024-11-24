/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemon_database.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:45:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 12:28:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stats.h"
#include "general_ft.h"

int	main(int argc, char *argv[])
{
	int				index;
	struct s_pkmn	pkmn;

	if (argc == 1)
	{
		ft_printf("Inserisci il nome di uno o più ");
		ft_printf("pokémon.\n");
		ft_printf("Il programma ne restituisce le ");
		ft_printf("statistiche.\n");
		return (42);
	}
	index = 1;
	while (argv[index] != NULL)
	{
		if (search_stat(argv[index], &pkmn, 0) == 1)
		{
			ft_printf("Pokèmon '%s' non trovato.", argv[index]);
		}
		//else
			//ft_printf("Pokèmon '%s' non trovato.", argv[index]);
		ft_printf("\n");
		//if (pkmn.nbr != 0)
			//free(pkmn.name);
		++index;
	}
	ft_printf("--FINE DELLA LISTA, BACI BACI--\n", argv[index]);
	return (0);
}

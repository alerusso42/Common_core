/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 17:03:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static void	*other_messages(int error);
static void	*other_messages2(int error);
static void	*other_messages3(int error);

/*
	Pretty unused in this project.
*/
void	*error(int error)
{
	if (error == ERROR_INVALID_INPUT)
	{
		l_printf("Inserisci dei valori validi.\n");
		l_printf("MODE CREATE: \"gen\" \"x\" \"y\"\n");
		l_printf("MODE READ: \"maps/map.ber\", or");
		l_printf("MODE READ: \"map.ber\"\n");
		return (NULL);
	}
	else
		return (other_messages(error));
}

static void	*other_messages(int error)
{
	if (error == ERROR_FULL_MEMORY)
	{
		l_printf("Attenzione: il sistema non ha");
		l_printf("memoria sufficiente per l'operazione ");
		l_printf("richiesta.\n");
		return (NULL);
	}
	else if (error == ERROR_BAD_BOARD)
	{
		l_printf("I numeri inseriti non hanno una soluzione.\n");
		l_printf("Inserire una board valida.\n");
		return (NULL);
	}
	else if (error == ERROR_NO_SOLUTIONS)
	{
		l_printf("L'algoritmo non ha trovato nessuna ");
		l_printf("soluzione per lo schema richiesto.\n");
		l_printf("Unlucky.\n");
		return (NULL);
	}
	else
		return (other_messages2(error));
}

static void	*other_messages2(int error)
{
	if (error == EZ)
		l_printf("\nEZ.\n");
	else
		return (other_messages3(error));
	return (NULL);
}

static void	*other_messages3(int error)
{
	if (error == ERROR_BAD_ARGC)
	{
		l_printf("\t:-#\t----PACMAN----\t  #-:\n\t------------------------");
		l_printf("-----\n");
		l_printf("\nPer giocare, inserisci il nome della mappa.\n");
		l_printf("La mappa deve essere in formato \".ber\".\n");
		l_printf("In alternativa, inserisci come argomenti \"gen x y\",");
		l_printf("dove x rappresenta la size della mappa in colonne, y");
		l_printf(" in righe.\n\n");
		l_printf("Per modificare il numero di nemici, di muri, ");
		l_printf("collezionabili, eccetera, vai nei file \"switches.c\", ");
		l_printf("\"variables.c\".\n\n\n");
		l_printf("Infine, per compilare e runnare, usa i seguenti comandi:\n");
		l_printf("\n\"make run ARGS=\"ARG_1 ARG_2 ARG_3...\"\": compile, run");
		l_printf("\n\"make val ARGS=\"ARG_1 ARG_2 ARG_3...\"\": comp, valgr.");
		l_printf("\n\"make gdb ARGS=\"ARG_1 ARG_2 ARG_3...\"\": comp, gdb");
		l_printf("\n\n");
		return (NULL);
	}
	else
		return (NULL);
}

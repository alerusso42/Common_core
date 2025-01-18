/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 16:02:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

static int	other_messages(int error);
static int	other_messages2(int error);
static int	other_messages3(int error);

int	error(int error)
{
	if (error == ERROR_INVALID_INPUT)
	{
		l_printf("Inserisci dei numeri validi.\n");
		l_printf("Ricorda: i numeri validi vanno da ");
		l_printf("1 alla dimensione di ogni col e row.\n");
		l_printf("Giocando con 16 quadranti, quindi, da 1 ");
		l_printf("a 4. Ce la puoi fare.\n");
		return (ERROR_INVALID_INPUT);
	}
	else
		return (other_messages(error));
}

static int	other_messages(int error)
{
	if (error == ERROR_FULL_MEMORY)
	{
		l_printf("Attenzione: il sistema non ha");
		l_printf("memoria sufficiente per l'operazione ");
		l_printf("richiesta.\n");
		return (ERROR_FULL_MEMORY);
	}
	else if (error == ERROR_BAD_BOARD)
	{
		l_printf("I numeri inseriti non hanno una soluzione.\n");
		l_printf("Inserire una board valida.\n");
		return (ERROR_BAD_BOARD);
	}
	else if (error == ERROR_NO_SOLUTIONS)
	{
		l_printf("L'algoritmo non ha trovato nessuna ");
		l_printf("soluzione per lo schema richiesto.\n");
		l_printf("Unlucky.\n");
		return (ERROR_NO_SOLUTIONS);
	}
	else
		return (other_messages2(error));
}

static int	other_messages2(int error)
{
	if (error == ERROR_PLAY_NOT_IMPLEMENTED)
	{
		l_printf("Attenzione: il motore di gioco non è");
		l_printf(" stato ancora implementato.\n");
		return (ERROR_PLAY_NOT_IMPLEMENTED);
	}
	else if (error == EZ)
		l_printf("\nEZ.\n");
	else
		return (other_messages3(error));
	return (error);
}

static int	other_messages3(int error)
{
	if (error == ERROR_BAD_ARGC)
	{
		l_printf("Il programma risolve il gioco \"Skyscraper\".\n ");
		l_printf("Inserisci i dati sullo schema che devi battere (max 9x9");
		l_printf(").\nIl formato è:\ncol1up col2up col3up col4up\n");
		l_printf("col1down col2down col3down col4down\n");
		l_printf("row1left row2left row3left row4left\n");
		l_printf("row1right row2right row3right row4right\n");
		l_printf("Se giochi a 9 quadranti devi mettere 9 valori per ogni");
		l_printf(" col e row.\nRicorda: il numero di argomenti deve essere");
		l_printf(" uguale a un multiplo di 4\nZero escluso :-)\n");
		l_printf("Comandi speciali:\n");
		l_printf("GEN: inserisci \"gen x y\", dove x è la grandezza della");
		l_printf("griglia e y è il seed randomico (opzionale), per farti ");
		l_printf("generare una griglia valida dal sistema;\n");
		l_printf("PLAY: inserisci \"play\" per giocare.");
		l_printf(" !Non è stato ancora implementato!\n");
		l_printf("switches & variables: se vai nei file switches.h e ");
		l_printf("variables.h, puoi modificare varie impostazioni.\n");
		return (ERROR_BAD_ARGC);
	}
	else
		return (42);
}

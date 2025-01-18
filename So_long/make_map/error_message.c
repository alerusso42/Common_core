/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 09:37:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	other_messages(int error);
int	other_messages2(int error);
int	other_messages3(int error);

int	error(int error)
{
	if (error == ERROR_INVALID_INPUT)
	{
		ft_printf("Inserisci dei numeri validi.\n");
		ft_printf("Ricorda: i numeri validi vanno da ");
		ft_printf("1 alla dimensione di ogni col e row.\n");
		ft_printf("Giocando con 16 quadranti, quindi, da 1 ");
		ft_printf("a 4. Ce la puoi fare.\n");
		return (ERROR_INVALID_INPUT);
	}
	else
		return (other_messages(error));
}

int	other_messages(int error)
{
	if (error == ERROR_FULL_MEMORY)
	{
		ft_printf("Attenzione: il sistema non ha");
		ft_printf("memoria sufficiente per l'operazione ");
		ft_printf("richiesta.\n");
		return (ERROR_FULL_MEMORY);
	}
	else if (error == ERROR_BAD_BOARD)
	{
		ft_printf("I numeri inseriti non hanno una soluzione.\n");
		ft_printf("Inserire una board valida.\n");
		return (ERROR_BAD_BOARD);
	}
	else if (error == ERROR_NO_SOLUTIONS)
	{
		ft_printf("L'algoritmo non ha trovato nessuna ");
		ft_printf("soluzione per lo schema richiesto.\n");
		ft_printf("Unlucky.\n");
		return (ERROR_NO_SOLUTIONS);
	}
	else
		return (other_messages2(error));
}

int	other_messages2(int error)
{
	if (error == ERROR_PLAY_NOT_IMPLEMENTED)
	{
		ft_printf("Attenzione: il motore di gioco non è");
		ft_printf(" stato ancora implementato.\n");
		return (ERROR_PLAY_NOT_IMPLEMENTED);
	}
	else if (error == EZ)
		ft_printf("\nEZ.\n");
	else
		return (other_messages3(error));
	return (error);
}

int	other_messages3(int error)
{
	if (error == ERROR_BAD_ARGC)
	{
		ft_printf("Il programma risolve il gioco \"Skyscraper\".\n ");
		ft_printf("Inserisci i dati sullo schema che devi battere (max 9x9");
		ft_printf(").\nIl formato è:\ncol1up col2up col3up col4up\n");
		ft_printf("col1down col2down col3down col4down\n");
		ft_printf("row1left row2left row3left row4left\n");
		ft_printf("row1right row2right row3right row4right\n");
		ft_printf("Se giochi a 9 quadranti devi mettere 9 valori per ogni");
		ft_printf(" col e row.\nRicorda: il numero di argomenti deve essere");
		ft_printf(" uguale a un multiplo di 4\nZero escluso :-)\n");
		ft_printf("Comandi speciali:\n");
		ft_printf("GEN: inserisci \"gen x y\", dove x è la grandezza della");
		ft_printf("griglia e y è il seed randomico (opzionale), per farti ");
		ft_printf("generare una griglia valida dal sistema;\n");
		ft_printf("PLAY: inserisci \"play\" per giocare.");
		ft_printf(" !Non è stato ancora implementato!\n");
		ft_printf("switches & variables: se vai nei file switches.h e ");
		ft_printf("variables.h, puoi modificare varie impostazioni.\n");
		return (ERROR_BAD_ARGC);
	}
	else
		return (42);
}

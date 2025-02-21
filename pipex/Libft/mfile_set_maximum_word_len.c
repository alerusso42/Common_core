/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_set_maximum_word_len.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:16:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 10:38:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
	set_maximum_word_len contiene il numero massimo di
	caratteri che write_line può scrivere (che è anche
	il minimo numero di caratteri, vedi "write_line").
	Il valore è definito da un int statico.

	Riceve come argomento un int.

	Se è positivo o zero, modifica l'attuale limite
	di caratteri di write_line, e lo restituisce.
	
	Altrimenti, ritorna il limite attuale senza fare
	altro.
*/
int	set_maximum_word_len(int new_len)
{
	static int	maximum_word_len = MIDWORDS_LEN;

	if (new_len < 0)
		return (maximum_word_len);
	maximum_word_len = new_len;
	return (maximum_word_len);
}

/*
	set_maximum_words contiene il numero massimo di
	parole che write_line può scrivere (che è anche
	il minimo numero di caratteri, vedi "write_line").
	Il valore è definito da un int statico.

	Riceve come argomento un int.

	Se è positivo o zero, modifica l'attuale limite
	di parole di write_line, e lo restituisce.
	
	Altrimenti, ritorna il limite attuale senza fare
	altro.
*/
int	set_maximum_words(int new_len)
{
	static int	maximum_words = MIDWORDS_LEN;

	if (new_len < 0)
		return (maximum_words);
	maximum_words = new_len;
	return (maximum_words);
}

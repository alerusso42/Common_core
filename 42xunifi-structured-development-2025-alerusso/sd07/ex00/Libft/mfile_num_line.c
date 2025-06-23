/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile_num_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:18:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 10:40:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfile_gnl.h"

/*
Find_number_line riceve:
1) fd;
2) il nome del file come stringa;
3) il numero di confronti da fare;
4) un numero variadico di stringhe: le parole chiave che vuoi cercare nel file.
	
	le stringhe verranno cercate in ordine. Se, durante la ricerca, il cursore
	arriva alla fine del testo senza aver trovato tutte le linee, la funzione
	restituisce -1 (stessa cosa per errori di malloc).

Ritorno:
		Il numero della linea dove si trova la corrispondenza;
		-1, se la ricerca fallisce oppure in caso di errori di malloc.
		-2, se gli argomenti presi sono invalidi.
*/
int	find_number_line(int fd, char *filename, int num_search, ...)
{
	int		line_num;
	va_list	ptr;

	if ((fd == -1) || (!filename))
		return (-2);
	reset_fd(fd, filename);
	va_start(ptr, num_search);
	line_num = find_line(fd, num_search, ptr);
	va_end(ptr);
	reset_fd(fd, filename);
	return (line_num);
}

/*
num_line riceve:
1) Il numero di ricerche da fare;
2) un numero variadico di stringhe: le parole chiave che vuoi cercare nel file.
	
	le stringhe verranno cercate in ordine. Se, durante la ricerca, il cursore
	arriva alla fine del testo senza aver trovato tutte le linee, la funzione
	restituisce -1 (stessa cosa per errori di malloc).

Ritorno:
		Il numero della linea dove si trova la corrispondenza;
		-1, se la ricerca fallisce oppure in caso di errori di malloc.
		-2, se gli argomenti presi sono invalidi.
*/
int	num_line(int num_search, ...)
{
	int		line_num;
	int		fd;
	char	*filename;
	va_list	ptr;

	get_filedata(&fd, &filename);
	if ((fd == -1) || (!filename))
		return (-2);
	va_start(ptr, num_search);
	reset_fd(fd, filename);
	line_num = find_line(fd, num_search, ptr);
	va_end(ptr);
	reset_fd(fd, filename);
	return (line_num);
}

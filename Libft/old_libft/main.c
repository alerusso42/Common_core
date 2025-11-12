/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:35:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/20 14:59:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

/*
	cc main.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c \
        ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c \
        ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
        ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
        ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
        ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
        ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c \
         mfile_find_line.c mfile_get_next_line_original.c \
                        mfile_get_n_line.c mfile_gnl.c \
                        mfile_gnl_utils1.c mfile_gnl_utils2.c \
                        mfile_hold_space.c mfile.main.c mfile_num_line.c \
                        mfile_read_all_line.c mfile_read_line.c \
						mfile_reset_fd.c \
                        mfile_set_maximum_word_len.c mfile_store_fds_back.c \
                        mfile_store_fds_user.c mfile_write_line.c \
						other_add_sign.c other_cut_string.c \
						other_del_pointer.c \
                        other_free_matrix.c other_move_sign.c other_realloc.c \
                        other_strjoin_free.c other_sub_string_tools.c \
                        other_trim_only.c printf_light.c mfile_initiate_file.c 
*/
/*
// Funzione generica per terminare programma
int	error(int error_type)
{
	if (error_type == 0)
		l_printf("\nTEST OK!\n");
	//8)Nota che chiamare del_filedata e sempre sicuro
	del_filedata();
	return (error_type);
}
*/
/*NOTE - 

	Questo e un main scritto per dimostrare come usare
	le funzioni manage_files(mfile).

	Di seguito l'ordine delle operazioni:

	1)	Aprire uno o piu file;
	2)	Dare fd e nome dei file a give_filedata.
		Di default, le funzioni mfile useranno
		l'ultimo dato che gli fornisci.
		Per switchare tra fd, usa switch_filedata.

		RICORDA: devi usare del_filedata prima
		di terminare il programma, e NON devi
		chiudere i file che dai in pasto a 
		give_filedata (ci pensa lui).
	
	3)	Setta il massimo di caratteri e parole per
		linea.
		Se non specificato, ogni linea nel file
		potra avere 10 parole da 10 caratteri ognuna.
		Questo dato viene usato da tutti i file, ed
		e consigliabile cambiarlo prima di iniziare
		ad operare sui file.

	4)	Registra, prima di inizializzare i file, le 
		categorie di ogni riga.
		VIETATI ' ' e '=' qui.
		Pro tip: crea un file e inserisci le colonne
		che vuoi abbia la matrice, e riempi la
		matrice con gnl.

	5)	Inizializza il file con la matrice.
		Puoi spammare questa funzione come vuoi,
		lasciera sempre uno spazio.

	6)	Trova il numero della linea su cui devi lavorare.
		In caso di errori, torna -1, ma non devi fare
		alcun controllo: write_line e read_line 
		falliranno.

	7)	Usa write_line, read_line, read_all_line a 
		tua discrezione.
		E ricorda di spegnere il gas.

	8)	Chiama del_filedata per non avere leak.
		PRO_TIP: siccome e sempre safe chiamarlo,
		usa una funzione in cui la chiami sempre, e
		in cui magari liberi la memoria delle tue
		strutture.

*/
/*
int	main()
{
	int		fd;
	char	*string;
	char	**matrix;
	int		line;

//	1)Files
	fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
		return (error(1));
//	2)Salvo i dati del file. Ricorda di usare del_filedata
	if (give_filedata(fd, "test.txt") != 0)
		return (error(2));
//	3)Setto il numero massimo di parole e caratteri. Il loro prodotto è il
//	numero di spazi inseriti.
	set_maximum_word_len(10);
	set_maximum_words(10);
//	4)Registro in una matrice i dati che voglio inserire (\t è opzionale).
//	Vietati ' ' e '='.
	matrix = ft_split("\tNome,\tCognome,\tStato_mentale,\tPunti_ferita,\
	\tRayquaza,\tNumero_di_peni_preso", ',');
//	5)Inizializzo il file con la matrice.
	initiate_file(fd, "TEST", matrix);
	matrix = free_matrix(matrix);
//	Rifaccio tutto per mostrare come viene formattato.
	matrix = ft_split("\tNome,\tCognome,\tStato_mentale,\tPunti_ferita,\
\tRayquaza,\tNumero_di_peni_preso", ',');
	initiate_file(fd, "TEST_2", matrix);
	matrix = free_matrix(matrix);
//	6,7)Prima di chiamare read_line e write_line, chiama num_line
	line = num_line(2, "[TEST]", "Nome");	
	if (write_line(line, 1, "ciao!") != 0)
		return (error(3));
	if (write_line(4, 1, "eeee!") != 0)
		return (error(3));
	if (write_line(3, 2, "aaaa!") != 0)
		return (error(3));
	if (write_line(3, 3, "oooo!") != 0)
		return (error(3));
	string = read_line(3, 2);
	l_printf("string: %s\n", string);
	if (string == NULL)
		return (error(5));
	free(string);
	return (error(0));
}
*/

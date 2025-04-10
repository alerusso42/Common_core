/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:35:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/24 12:10:54 by alerusso         ###   ########.fr       */
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
int	main()
{
	int		fd;
	char	*string;
	char	**matrix;
	int		line;

	fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
		return (l_printf("1"));
//	Salvo i dati del file
	if (give_filedata(fd, "test.txt") != 0)
		return (l_printf("2"));
//	Registro in una matrice i dati che voglio inserire (\t è opzionale)
	matrix = ft_split("\tNome,\tCognome,\tStato_mentale,\tPunti_ferita,\
	\tRayquaza,\tNumero_di_peni_preso", ',');
//	Setto il numero massimo di parole e caratteri. Il loro prodotto è il
//	numero di spazi inseriti.
	set_maximum_word_len(10);
	set_maximum_words(10);
//	Inizializzo il file con la matrice.
	initiate_file(fd, "TEST", matrix);
	matrix = free_matrix(matrix);
//	Rifaccio tutto per mostrare come viene formattato.
	matrix = ft_split("\tNome,\tCognome,\tStato_mentale,\tPunti_ferita,\
\tRayquaza,\tNumero_di_peni_preso", ',');
	initiate_file(fd, "TEST_2", matrix);
	matrix = free_matrix(matrix);
//	Prima di chiamare read_line e write_line, chiama num_line
	line = num_line(2, "[TEST1], Nome");	
	if (write_line(line, 1, "ciao!") != 0)
		return (l_printf("3"));
	if (write_line(4, 1, "eeee!") != 0)
		return (l_printf("3"));
	if (write_line(3, 2, "aaaa!") != 0)
		return (l_printf("3"));
	if (write_line(3, 3, "oooo!") != 0)
		return (l_printf("3"));
	string = read_line(3, 2);
	l_printf("string: %s\n", string);
	if (string == NULL)
		return (l_printf("5"));
	free(string);
	return (l_printf("TEST OK!"));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 04:59:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../header.h"
# include <fcntl.h>
# include <stdbool.h>

//	separators and trim character (in CSV, ' ' and ',')

# define TO_TRIM ' '
# define SEPARATOR ','
# define SEPARATOR_S ",\n"

//	filenames

# define DIR		"data/"
# define ERROR_FILE DIR"error.log"
# define D_NAME		DIR"lib.csv"
# define DATA 		"lib.csv"

//	variables of database columns

# define NAMES 		"id", "book", "author"
# define FILES		DIR"id_"DATA, DIR"book_"DATA, DIR"author_"DATA

//	filetypes: 	types are equal to printf types (d, s, c...).
//				TYPES[i] -> FILES[i] type

# define TYPES "dss"

//	max read in loop() function

# define MAX_READ 250

typedef struct s_data	t_data;
typedef struct s_entry	t_entry;

enum e_entries
{
	ID,
	AUTHOR_NAME,
	BOOK_NAME,
	TOTAL_ENTRIES,
};

enum e_errors
{
	ER_NOERR,
	ER_MALLOC,
	ER_OPEN,
	ER_STDIN,
	ER_PARSING,
	ER_MISSING_DATABASE,
	ER_MISSING_NAME_HEADER,
};

enum	Alphabet
{
	LETTER_A,
	LETTER_B,
	LETTER_C,
	LETTER_D,
	LETTER_E,
	LETTER_F,
	LETTER_G,
	LETTER_H,
	LETTER_I,
	LETTER_J,
	LETTER_K,
	LETTER_L,
	LETTER_M,
	LETTER_N,
	LETTER_O,
	LETTER_P,
	LETTER_Q,
	LETTER_R,
	LETTER_S,
	LETTER_T,
	LETTER_U,
	LETTER_V,
	LETTER_W,
	LETTER_X,
	LETTER_Y,
	LETTER_Z,
	ALPHABET_SIZE,
};

enum e_perms
{
	P_CREATE = O_RDWR | O_CREAT | O_TRUNC,
	P_EXIST = O_RDWR | O_EXCL,
	P_APPEND = O_RDWR | O_CREAT | O_APPEND,
};

struct s_entry
{
	char	*name;
	char	*filename;
	int		offsets[ALPHABET_SIZE];
	int		first_entry;
	int		last_element;
	int		size;
	char	type;
};

struct s_data
{
	t_entry	entry[TOTAL_ENTRIES];
	char	**entries[TOTAL_ENTRIES];
	char	*filename;
	int		*offsets;
	int		last_error;
	int		error_file;
	bool	del_warning;
};


#endif
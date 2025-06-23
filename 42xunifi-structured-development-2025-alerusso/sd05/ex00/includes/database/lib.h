/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:31:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/23 12:06:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

//	separators and trim character (in CSV, ' ' and ',')

# define TO_TRIM ' '
# define SEPARATOR ','
# define SEPARATOR_S ",\n"
# define QUOTE '"'

//	filenames

# define DIR		"data/lib/"
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

enum e_entries
{
	ID,
	AUTHOR_NAME,
	BOOK_NAME,
	TOTAL_ENTRIES,
};

#endif
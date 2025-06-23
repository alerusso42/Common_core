/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:31:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/23 12:39:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

//	!!! DOES NOT WORK: CANNOT PARSE "" !!!

//	separators and trim character (in CSV, ' ' and ',')

# define TO_TRIM ' '
# define SEPARATOR ','
# define SEPARATOR_S ",\n"
# define QUOTE '"'

//	filenames

# define DIR		"data/big_file/"
# define ERROR_FILE DIR"error.log"
# define D_NAME		DIR"10mb.csv"
# define DATA 		"big_file.csv"

//	variables of database columns

# define NAMES 		"first_name", "last_name", "email", "gender", "ip_address",\
 "date", "image", "animal", "avatar"
# define FILES 		DIR"first_name_"DATA, DIR"last_name_"DATA, DIR"email_"DATA, \
DIR"gender_"DATA, DIR"ip_address_"DATA, DIR"date_"DATA, DIR"image_"DATA, \
DIR"animal_"DATA, DIR"avatar_"DATA

//	filetypes: 	types are equal to printf types (d, s, c...).
//				TYPES[i] -> FILES[i] type

# define TYPES "sssssssss"

enum e_entries
{
	FIRST_NAME,
	LAST_NAME,
	EMAIL,
	GENDER,
	IP_ADDRESS,
	DATE,
	IMAGE,
	ANIMAL,
	AVATAR,
	TOTAL_ENTRIES,
};

#endif
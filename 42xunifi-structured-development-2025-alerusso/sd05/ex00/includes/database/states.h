/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:31:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/23 12:33:43 by alerusso         ###   ########.fr       */
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

# define DIR		"data/states/"
# define ERROR_FILE DIR"error.log"
# define D_NAME		DIR"states_by_country_code.csv"
# define DATA 		"states_by_country_code.csv"

//	variables of database columns

# define NAMES 		"State_Code", "State_Name", "Country_Code"
# define FILES		DIR"State_Code_"DATA, DIR"State_Name_"DATA, DIR"Country_Code_"DATA

//	filetypes: 	types are equal to printf types (d, s, c...).
//				TYPES[i] -> FILES[i] type

# define TYPES "sss"

//	max read in loop() function

enum e_entries
{
	STATE_CODE,
	STATE_NAME,
	COUNTRY_CODE,
	TOTAL_ENTRIES,
};

#endif
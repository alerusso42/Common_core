/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/23 13:48:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../header.h"
# include <fcntl.h>
# include <stdbool.h>

# define MAX_READ 250

typedef struct s_data	t_data;
typedef struct s_entry	t_entry;

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
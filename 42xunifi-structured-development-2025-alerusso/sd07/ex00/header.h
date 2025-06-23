/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/23 14:32:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//	CHOOSE DATABASE, BETWEEN:
//	lib.h
//	states.h
//	big_file.h

# include "includes/database/lib.h"

//	header files

# include "Libft/all.h"
# include "includes/struct.h"
# include "includes/func.h"
# include <stdbool.h>
# include <fcntl.h>

//	color for frontend.c

# define COL_R			"\033[0m"
# define COL_BLACK 		"\033[30m"
# define COL_RED 		"\033[31m"
# define COL_GREEN 		"\033[32m"
# define COL_YELLOW 	"\033[33m"
# define COL_BLUE 		"\033[34m"
# define COL_MAGENTA 	"\033[35m"
# define COL_CYAN 		"\033[36m"
# define COL_WHITE 		"\033[37m"

#endif
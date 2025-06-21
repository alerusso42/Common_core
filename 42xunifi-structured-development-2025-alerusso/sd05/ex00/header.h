/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 00:10:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "includes/struct.h"
# include "includes/func.h"
# include "Libft/all.h"
# include <stdbool.h>
# include <fcntl.h>

# define COL_R			"\033[0m"
# define COL_BLACK 		"\033[30m"
# define COL_RED 		"\033[31m"
# define COL_GREEN 		"\033[32m"
# define COL_YELLOW 	"\033[33m"
# define COL_BLUE 		"\033[34m"
# define COL_MAGENTA 	"\033[35m"
# define COL_CYAN 		"\033[36m"
# define COL_WHITE 		"\033[37m"

enum e_color
{
	RST = 0,
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	WHITE = 37,
	BOLD_BLACK = 90,
	BOLD_RED = 91,
	BOLD_GREEN = 92,
	BOLD_YELLOW = 93,
	BOLD_BLUE = 94,
	BOLD_MAGENTA = 95,
	BOLD_CYAN = 96,
	BOLD_WHITE = 97,
}; 

#endif
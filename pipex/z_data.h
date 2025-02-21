/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:29:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_DATA_H
# define Z_DATA_H
# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

enum e_error
{
	ER_BAD_ARGC = 1,
	ER_MALLOC = 2,
	ER_PARSING = 3,
};

typedef struct s_settings
{
	unsigned char	switch_1_bonus:1;
}				t_settings;

#endif
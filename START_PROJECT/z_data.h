/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 12:22:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

enum e_bool
{
	ON = 1,
	YES = 1,
	OFF = 0,
	NO = 0,
};

typedef struct s_settings
{
	unsigned char	switch_1_bonus:1;
}				t_settings;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 14:37:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_HEADER_H
# define Z_HEADER_H

# if __has_include("z_data.h")
#  include "z_data.h"
# else
#  include "z_data_bonus.h"
# endif

# if __has_include("z_function_list.h")
#  include "z_function_list.h"
# else
#  include "z_function_list_bonus.h"
# endif

#endif
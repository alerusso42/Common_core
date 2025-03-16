/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/06 16:16:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# if __has_include("types.h")
#  include "types.h"
# else
#  include "types_bonus.h"
# endif

# if __has_include("z_error_list.h")
#  include "z_error_list.h"
# else
#  include "z_error_list_bonus.h"
# endif

# if __has_include("z_event_list.h")
#  include "z_event_list.h"
# else
#  include "z_event_list_bonus.h"
# endif

# if __has_include("z_flags.h")
#  include "z_flags.h"
# else
#  include "z_flags_bonus.h"
# endif

# if __has_include("z_function_list.h")
#  include "z_function_list.h"
# else
#  include "z_function_list_bonus.h"
# endif

# if __has_include("get_next_line.h")
#  include "get_next_line.h"
# else
#  include "get_next_line_bonus.h"
# endif

#endif

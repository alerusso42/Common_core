/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_function_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:02:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:37:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FUNCTION_LIST_H
# define Z_FUNCTION_LIST_H
# include "Libft/all.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

int		switch_to_bonus(t_settings *settings);
void	*storage(void *ptr, int mode);
void	reset_memory(void *ptr);

#endif
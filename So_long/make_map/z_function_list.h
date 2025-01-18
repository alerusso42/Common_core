/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_function_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:33:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/18 09:38:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FUNCTION_LIST_H
# define Z_FUNCTION_LIST_H
# include "types.h"
# include "z_error_list.h"
# include "get_next_line_bonus.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

int	alloc_user_input(t_input **input, int game_size[2]);

#endif
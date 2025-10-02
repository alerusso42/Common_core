/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:41:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 01:23:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACMAN_H
# define PACMAN_H

# include "lib.h"
# include "../program/Libft/all.h"
# include "../daft.h"
# include "media/mus.h"
# include "media/sound.h"
# include "media/textures.h"
# include "media/maps.h"
# include "bfs.h"
# include "func.h"
# include "struct.h"
# include "macros.h"

void	err(const char *s);

# define ERROR_FILE "error.log"

#endif
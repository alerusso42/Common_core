/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:41:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/25 00:48:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "pacman.h"

typedef struct s_data	t_data;
typedef struct s_SDL	t_SDL;

struct s_SDL
{
	void		*win;
	void		*render;
	Mix_Music	*mus[TOTAL_MUS + 1];
	Mix_Chunk	*sound[TOTAL_SOUND + 1];
};

struct s_data
{
	t_SDL	sdl;
	t_fd	debug_file;
	int		last_error;
};

enum e_error
{
	ER_OK,
	ER_MALLOC,
	ER_OPEN,
	ER_SDL,
	ER_DAFT,
};

#endif
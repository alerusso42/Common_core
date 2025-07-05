/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:43:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 12:28:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define DEBUG true
# define WIN_W 1080
# define WIN_H 1800
# define WIN_X 0
# define WIN_Y 0
# define WIN_FLAGS (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)
# define SPRITE_SIZE 25
# define WIN_NAME "PACMAN"
# define FPS 30ULL
# define FRAME_TIME (1000ULL / FPS)
# define DELTA_TIME FPS / 30
# define MIN_SPEED 5000
# define SDL_INIT_MASK 	(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | \
						SDL_INIT_TIMER)

# define VALID_CHAR_AFTER_FLOODFILL "X1$"

#endif
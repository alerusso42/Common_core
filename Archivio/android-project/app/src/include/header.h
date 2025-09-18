/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:03:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 23:05:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "SDL.h"
# include <stdbool.h>
# include "../main/daft/daft.h"
# include "../main/daft/.private/program/Libft/libft.h"

int 	daft_init(void);
void	daft_quit(void);
void	daft_swap(int enum_id);
void	*daft_get(const char *search);

enum	e_utils
{
	X = 0,
	Y = 1,
	TOUCH = 1,
	COLOR = 0x3449eb,
	R = 52,
	G = 73,
	B = 235,
	BOX_X = 300,
	BOX_Y = 500,
};

enum e_txtr
{
	TXTR_BOX,
	TXTR_CURSOR,
	TXTR_NUM,
};

typedef struct s_touch
{
	int		pos[2];
	char	text[32];
	int		text_len;
	int		text_left;
	float	pressure;
	char	input;
}	t_touch;

typedef struct s_data
{
	SDL_Window		*win;
	SDL_Texture		*txtr[TXTR_NUM + 1];
	SDL_Renderer	*rend;
	int				wscreen;
	int				hscreen;
	char			input;
}	t_data;

void	app_loop(t_data *data);
void	inputs(t_touch *touch, int *run, int wscreen, int hscreen);
void	render(t_touch *touch, t_data *data);
void	interface(t_data *data, t_touch *touch);
void	reset_buff(t_touch *touch);
int		init_txtr(t_data *data);
void	free_txtr(t_data *data);

#endif
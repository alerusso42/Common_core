/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mod.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/11 18:31:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGE_MOD_H
# define CHANGE_MOD_H
# include "types.h"
# include "general_ft.h"
# include "error_message.h"
# include "automatic_input.h"

int	change_mod(char *argv[], int argc);

int	change_mod(char *argv[], int argc)
{
	int	game_size[2];
	int	seed;

	game_size[0] = 0;
	game_size[1] = 0;
	seed = 0;
	if (ft_strcmp(argv[1], "gen") == 0)
		return (automatic_input(argc, argv, game_size, seed));
	if (ft_strcmp(argv[1], "play") == 0)
		error(ERROR_PLAY_NOT_IMPLEMENTED);
	return (0);
}

#endif
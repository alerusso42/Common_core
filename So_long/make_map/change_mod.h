/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mod.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/16 17:18:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGE_MOD_H
# define CHANGE_MOD_H
# include "types.h"
# include "general_ft.h"
# include "error_message.h"
# include "automatic_input.h"

int		change_mod(char *argv[], int argc);
t_bool	alloc_data(int game_size[2], int seed, int create_or_read);
int		check_extension_file(char *filename, char *extension);

int	change_mod(char *argv[], int argc)
{
	int	game_size[2];
	int	seed;

	game_size[0] = 0;
	game_size[1] = 0;
	seed = 0;
	if (argc == 2)
	{
		if (check_extension_file(argv[1], ".ber") == 1)
			return (1);
		ft_printf("File valido!\n");
		return (0);
		//return (alloc_data(game_size, seed));
	}
	if (argc < 4)
		return (error(ERROR_BAD_ARGC));
	if (ft_strcmp(argv[1], "gen") == 0)
		return (create_map(argc, argv, game_size, seed));
	return (0);
}

#endif
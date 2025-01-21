/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/21 14:42:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	ft_settings(t_input **input, t_map **map);
int	ft_start(t_input **input, t_map **map, t_random *random);

// 
int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (error(ERROR_BAD_ARGC));
	if (change_mod(argv, argc) == 1)
		return (1);
	return (0);
}

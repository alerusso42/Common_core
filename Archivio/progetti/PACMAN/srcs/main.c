/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:03:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/07 22:52:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

int	main()
{
	t_data	data;

	srand((unsigned int)time(NULL));
	data = (t_data){0};
	getter(&data, true);
	if (init_all(&data) != 0)
		return (data.last_error);
	game_loop(&data);
	free_all(&data);
	return (0);
}

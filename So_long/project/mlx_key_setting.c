/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:30:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/22 17:22:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

int	commands(int keycode);

void	get_key_settings(t_all *all)
{
	void	*p;

	p = (void *)&all;
	storage_structs(all, UPDATE);
	mlx_hook(all->mlx->window, ON_DESTROY, KEY_RELEASE_MASK, end, p);
	mlx_hook(all->mlx->window, ON_KEYDOWN, KEY_PRESS_MASK, end, p);
	mlx_hook(all->mlx->window, ON_KEYDOWN, KEY_PRESS_MASK, commands, p);
}

int	commands(int keycode)
{
	if (keycode == XK_Escape)
		end(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:30:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/22 13:02:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_function_list.h"

void	get_key_settings(t_all *all)
{
	void	*p;

	p = (void *)all;
	mlx_hook(all->mlx->window, ON_DESTROY, KEY_RELEASE_MASK, *end, p);
}
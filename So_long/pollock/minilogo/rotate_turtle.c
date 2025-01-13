/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_turtle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:16:49 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/13 14:10:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilogo.h"

void	right(int amount, t_turtle *turtle)
{
	if (!turtle)
		return ;
	turtle->angle += amount;
	if (turtle->angle > 359)
		turtle->angle %= 360;
}

void	left(int amount, t_turtle *turtle)
{
	if (!turtle)
		return ;
	turtle->angle -= amount;
	if (turtle->angle < 0)
		turtle->angle %= -360;
}
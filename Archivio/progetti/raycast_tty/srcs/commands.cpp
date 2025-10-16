/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:32:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/16 10:28:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/raycast_tty.hpp"

void	commands(Term &tty, Map &map)
{
	if (tty.key(tty.KEY_W))
		map.move_player(-1, false);
	if (tty.key(tty.KEY_S))
		map.move_player(1, false);
	if (tty.key(tty.KEY_A))
		map.move_player(-1, true);
	if (tty.key(tty.KEY_D))
		map.move_player(1, true);
	if (tty.key(tty.KEY_Q))
		tty.turn_down();
}

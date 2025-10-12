/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:32:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/12 18:21:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/raycast_tty.hpp"

void	commands(Term *tty)
{
	if (tty->key(tty->KEY_W))
		tty->test_input(1);
	else if (tty->key(tty->KEY_S))
		tty->test_input(-1);
	else if (tty->key(tty->KEY_Q))
		tty->turn_down();
}

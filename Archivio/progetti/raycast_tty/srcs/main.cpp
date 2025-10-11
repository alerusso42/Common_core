/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:58:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/11 00:47:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/raycast_tty.hpp"

int	main(void)
{
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	Term	t;
	int		loops;

	t.clear();
	t.test_screen();
	t.render();
	loops = 12;
	while (loops--)
	{
		std::cout << "\033[H";
		tty_putstr("@", loops, 9);
	}
	std::cout << "\033[9999;9999H";
	return (0);
}
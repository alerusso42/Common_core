/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:29:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 16:33:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.hpp"

void	tty_clear(void)
{
	std::cout << "\033[H";// H: set to position to 0,0
	std::cout << "\033[0J" << std::flush;// 0J: clear from position to end
}

void	tty_putstr(string s, int x, int y)
{
	std::cout << "\033[" << y << ";" << x << "H" << s;//033[y;xH
}

void	print_error(string s)
{
	std::cerr << "\033[31m";//red
	std::cerr << s;
	std::cerr << "\033[0m";//reset
	std::cerr << std::endl;
}
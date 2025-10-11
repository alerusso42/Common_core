/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:18:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/11 01:23:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Term.hpp"

#ifdef _WIN32


void	Term::test_input(void)
{
	
}

#elif defined(__linux__) || defined(__APPLE__)

void	Term::test_input(void)
{
	termios	oldt;
	termios	newt;
	char	buffer[20];

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ECHO | ICANON);
	newt.c_cc[VTIME] = 5; // 0.5 secondi
	newt.c_cc[VMIN] = 0;  // leggi anche se niente disponibile
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	read(STDIN_FILENO, buffer, 19);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

#endif	

void	Term::_init_keys(void)
{
	std::string	keys(KEYS);

	for (u_int64_t i = 0; keys[i]; i++)
	{
		this->_key_binding[keys[i]] = 1 << i;	
	}
}

void	Term::_init_input(void)
{
	this->_thread_input = std::thread(Term::_input_reader, this);
}

void	Term::_input_reader(void)
{
	while ()
}

u_int64_t	Term::get_input(void)
{
	u_int64_t	input;

	this->_mutex_input.lock();
	input = this->_input;
	this->_mutex_input.unlock();
	return (input);
}

void	Term::set_input(const u_int64_t &input)
{
	this->_mutex_input.lock();
	this->_input = input;
	this->_mutex_input.unlock();
}

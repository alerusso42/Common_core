/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:18:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/13 09:49:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Term.hpp"

//SECTION - input thread functions

void	_input_thread(Term *tty)
{
	while (tty->is_active() == true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(tty->INPUT_RATE));
		tty->get_input();
	}
}

/*
void	Term::_init_keys(void)
{
	std::string	keys(KEYS);

	for (u_int64_t i = 0; keys[i]; i++)
	{
		this->_key_binding[keys[i]] = 1 << i;	
	}
}*/

void	Term::get_input(void)
{
	this->_input_read();
	this->_mutex_input.lock();
	for (typename std::map<int32_t, bool>::iterator i = this->_keys.begin();\
	 i != this->_keys.end(); i++)
		i->second = false;
	for (u_int32_t i = 0; i < this->_input_size; i++)
		this->_keys[this->_buffer_input[i]] = true;
	this->_mutex_input.unlock();
}

bool	Term::is_active(void)
{
	bool	tty_on;

	this->_mutex_input.lock();
	tty_on = this->_term_on;
	this->_mutex_input.unlock();
	return (tty_on);
}

//SECTION - main thread functions

bool	Term::key(int32_t c)
{
	bool	is_pressed;

	this->_mutex_input.lock();
	is_pressed = this->_keys[c];
	this->_keys[c] = false;
	this->_mutex_input.unlock();
	return (is_pressed);
}

bool	Term::key(u_int32_t number, ...)
{
	va_list		list;

	va_start(list, number);
	for (u_int32_t i = 0; i < number; i++)
	{
		if (key((int32_t)va_arg(list, int32_t)) == true)
			return (va_end(list), true);
	}
	va_end(list);
	return (false);
}

void	Term::turn_down(void)
{
	this->_mutex_input.lock();
	this->_term_on = false;
	this->_mutex_input.unlock();
}

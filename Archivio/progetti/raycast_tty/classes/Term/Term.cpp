/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Term.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:22:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/13 09:48:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Term.hpp"

Term::Term()
{
	this->_init_tty_settings();
	this->_update_tty_size();
	this->_column = 0;
	this->_term_on = true;
	this->_thread_input = std::thread(_input_thread, this);
}

Term::~Term()
{
	this->_mutex_input.lock();
	this->_term_on = false;
	this->_mutex_input.unlock();
	this->_thread_input.join();
#if defined(__linux__) || defined(__APPLE__)
	tcsetattr(STDIN_FILENO, TCSANOW, &this->_oldt);
#endif
}

Term::Term(const Term &other)
{
	if (this == &other)
		return ;
	this->_column = other._column;
	this->_term_x = other._term_x;
	this->_term_y = other._term_y;
	this->_term_on = true;
	this->_thread_input = std::thread(_input_thread, this);
}

Term	&Term::operator=(const Term &other)
{
	if (this == &other)
		return (*this);
	this->_column = other._column;
	this->_term_x = other._term_x;
	this->_term_y = other._term_y;
	this->_term_on = true;
	this->_thread_input = std::thread(_input_thread, this);
	return (*this);
}

void	Term::render(void)
{
	std::cout << std::flush;
	this->_column = 0;
}

void	Term::clear(void) const
{
	std::cout << "\033[H";// H: set to position to 0,0
	std::cout << "\033[0J" << std::flush;// 0J: clear from position to end
}

void	Term::draw_column(int32_t heigth)
{
	int	y;
	int	stop;

	y = this->_term_y / 2;
	std::cout << "\033[" << this->_term_y / 2 << ";" << this->_column << "H";
	stop = y + (heigth / 2);
	while (y < stop && y < this->_term_y)
	{
		std::cout << "\u2588";// u is unicode
		std::cout << "\033[1B";//goes # line below
		std::cout << "\033[1D";//goes # colums left
		++y;
	}
	y = this->_term_y / 2;
	std::cout << "\033[" << this->_term_y / 2 << ";" << this->_column << "H";
	stop = y - (heigth / 2);
	while (y && y > stop)
	{
		std::cout << "\u2588";
		std::cout << "\033[1A";//goes # line up
		std::cout << "\033[1D";
		--y;
	}
	this->_column++;
}

void	Term::get_size(int32_t *x, int32_t *y)
{
	if (x)
		*x = this->_term_x;
	if (y)
		*y = this->_term_x;
}

int32_t	Term::get_size_x(void)
{
	return (this->_term_x);
}

int32_t	Term::get_size_y(void)
{
	return (this->_term_y);
}


void	Term::test_screen(void)
{
	this->_column = 0;
	while (this->_column < this->_term_x)
		this->draw_column((float)random_gen(this->_term_y));
}

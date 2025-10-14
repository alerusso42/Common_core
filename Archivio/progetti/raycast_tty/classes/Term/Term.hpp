/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Term.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:22:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/14 22:04:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_HPP
# define TERM_HPP

# include "../../includes/lib/lib.hpp"
# include <stdarg.h>
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <mutex>
# include <thread>
# include <map>
# include <math.h>
#ifdef _WIN32
# include <conio.h>
# include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
#else
# error "OS has not terminal support"
#endif

# ifndef FOV
#  define FOV 60
#  define PI 3.1415926535
# define FOV_RAD FOV * (PI / 180)
# endif

#define LOG "logfile"

class Term
{
private:
	enum e_term
	{
		FPS =		60,
		READ_SIZE = 20,
	};

	termios						_oldt;
	//SECTION - input
	std::map<int32_t, bool>		_keys;
	int8_t						_buffer_input[READ_SIZE];
	std::mutex					_mutex_input;
	std::thread					_thread_input;
	u_int32_t					_input_size;
	void						_input_read(void);

	int32_t		_term_x;
	int32_t		_term_y;
	int32_t		_column;
	bool		_term_on;

	void	_update_tty_size(void);
	void	_init_tty_settings(void);
public:
	//canonic form
	Term();
	~Term();
	Term(const Term &other);
	Term	&operator=(const Term &other);

	Fixed	screen_distance;
	enum e_term_general
	{
		FRAME_RATE =	(int32_t)((float)1000 / (float)FPS),
		INPUT_RATE =	FRAME_RATE / 2,
	};
	enum e_term_input
	{
		KEY_W =		'w',
		KEY_D =		'd',
		KEY_S =		's',
		KEY_A =		'a',
		KEY_Q =		'q',
	};
	//SECTION - getters/setters

	void	get_size(int32_t *x, int32_t *y) const;
	int32_t	get_size_x(void) const;
	int32_t	get_size_y(void) const;

	//SECTION - class functions

	void	render(void);
	void	clear(void) const;
	bool	is_active(void);
	void	turn_down(void);

	bool	key(int32_t c);
	bool	key(u_int32_t number, ...);
	
	//SECTION - testing
	void		draw_column(int32_t heigth);
	void		test_screen(void);
	void		get_input(void);
	void		set_input(const u_int64_t &other);
};

void	_input_thread(Term *tty);

#endif
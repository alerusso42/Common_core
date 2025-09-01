/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/01 23:01:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "lib/lib.hpp"

# define USAGE "Give as a parameter DEBUG, INFO, WARNING, ERROR"
# define MSG_DEBUG "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define MSG_INFO "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking \
 for more!"
# define MSG_WARNING "I think I deserve to have some extra bacon for free. \
I’ve been coming for years, whereas you started working here just last month."
# define MSG_ERROR "This is unacceptable! I want to speak to the manager now."
# define MSG_IGNORED "Probably complaining about insignificant problems"

# define MASK 16

typedef class Harl	Harl;
typedef void		(Harl::*t_harl)(void);

//	D	359
//	I	300
//	W	534
//	E	394
//	divided by ten
enum	e_levels
{
	LV_DEBUG = 24,
	LV_INFO = 61,
	LV_WARNING = 84,
	LV_ERROR = 98,
	LV_NUM = 100,
};

class Harl
{
private:
	void 	debug(void);
	void 	info(void);
	void 	warning(void);
	void 	error(void);
	void	empty(void);
	int		filter;
public:
	Harl(int filter);
	~Harl();
	void 	complain(std::string level);
	t_harl	ft[100];
};


int	alpha_hash(string s);
int	filter_check(string s, int filter);

#endif
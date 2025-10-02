/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "lib/lib.hpp"

# define MSG_DEBUG "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define MSG_INFO "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking \
 for more!"
# define MSG_WARNING "I think I deserve to have some extra bacon for free. \
I’ve been coming for years, whereas you started working here just last month."
# define MSG_ERROR "This is unacceptable! I want to speak to the manager now."

typedef class Harl	Harl;
typedef void		(Harl::*t_harl)(void);

//	D	359
//	I	300
//	W	534
//	E	394
//	divided by ten
enum	e_levels
{
	LV_DEBUG = 35,
	LV_INFO = 30,
	LV_WARNING = 53,
	LV_ERROR = 39,
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
public:
	Harl();
	~Harl();
	void 	complain(std::string level);
	t_harl	ft[100];
};


int	alpha_hash(std::string s);

#endif
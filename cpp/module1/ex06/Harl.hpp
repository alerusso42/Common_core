/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 16:10:06 by alerusso         ###   ########.fr       */
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
# define MSG_EMPTY "Probably complaining about insignificant problems"

# define FILTER_ARRAY "DEBUG", "INFO", "WARNING", "ERROR", "DEBUG"
# define MSG_ARRAY MSG_DEBUG, MSG_INFO, MSG_WARNING, MSG_ERROR, MSG_EMPTY

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
	LV_DEBUG,
	LV_INFO,
	LV_WARNING,
	LV_ERROR,
	LV_EMPTY,
	LV_NUM,
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
	string	*names;
public:
	Harl(string filter);
	~Harl();
	void 	complain(std::string level);
	int		find_lv(string s);
	int		filter_check(int level);
	t_harl	ft[LV_NUM + 1];
	bool	invalid(void);
};

int	alpha_hash(string s);
int	filter_check(int filter);

#endif
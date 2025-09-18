/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 16:08:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(string filter)
{
	static string	names[] = {FILTER_ARRAY};

	this->names = names;
	this->filter = this->find_lv(filter);
	this->ft[LV_EMPTY] = &Harl::empty;
	this->ft[LV_DEBUG] = &Harl::debug;
	this->ft[LV_INFO] = &Harl::info;
	this->ft[LV_WARNING] = &Harl::warning;
	this->ft[LV_ERROR] = &Harl::error;
}

Harl::~Harl()
{}

void	Harl::debug(void)
{
	std::cout << MSG_DEBUG;
}

void	Harl::info(void)
{
	std::cout << MSG_INFO;
}

void	Harl::warning(void)
{
	std::cout << MSG_WARNING;
}

void	Harl::error(void)
{
	std::cout << MSG_ERROR;
}

void	Harl::empty(void)
{
	std::cout << "[ " MSG_EMPTY << " ]" << std::endl;
}

int	Harl::find_lv(string s)
{
	for (int i = 0; i < LV_NUM; i++)
	{
		if (!s.compare(this->names[i]))
			return (i);
	}
	return (LV_EMPTY);
}

void	Harl::complain(string s)
{
	int	level;

	if (valid_input(s) == false)
		return ;
	std::cout << "[ " << s << " ]" << std::endl;
	std::cout << "[ ";
	level = find_lv(s);
	if (level == LV_EMPTY || filter_check(level) == 1)
		return (std::cout << MSG_EMPTY << " ]\n\n", (void)0);
	(this->*ft[level])();
	std::cout << " ]\n\n";
}

//returns 1 on error	
int	Harl::filter_check(int level)
{
	switch (level < this->filter)
	{	
		case (false):
			return (false);
		default:
			return (true);
	}
}

bool	Harl::invalid(void)
{
	if (this->filter == LV_EMPTY)
	{
		this->empty();
		return (true);
	}
	return (false);
}

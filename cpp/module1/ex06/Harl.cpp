/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(std::string filter)
{
	static std::string	 names[] = {FILTER_ARRAY};

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
	std::cout << "[ " << MSG_DEBUG << " ]\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ " << MSG_INFO << " ]\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ " << MSG_WARNING << " ]\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ " << MSG_ERROR << " ]\n" << std::endl;
}

void	Harl::empty(void)
{
	std::cout << "[ " MSG_EMPTY << " ]\n" << std::endl;
}

void	Harl::print(int lv)
{
	std::string	 names[] = {FILTER_ARRAY};

	if (lv == LV_EMPTY)
		return (this->empty());
	while (lv < LV_EMPTY)
	{
		std::cout << "[ "<< names[lv] << " ]\n";
		(this->*ft[lv])();
		++lv;
	}
}

int	Harl::find_lv(std::string s)
{
	for (int i = 0; i < LV_NUM; i++)
	{
		if (!s.compare(this->names[i]))
			return (i);
	}
	return (LV_EMPTY);
}

void	Harl::complain(void)
{
	switch (this->filter)
	{
		case (LV_DEBUG) :
			this->print(LV_DEBUG);
			break ;
		case (LV_INFO) :
			this->print(LV_INFO);
			break ;
		case (LV_WARNING) :
			this->print(LV_WARNING);
			break ;
		case (LV_ERROR) :
			this->print(LV_ERROR);
			break ;
		default :
			this->print(LV_EMPTY);
	}
	std::cout << std::flush;
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

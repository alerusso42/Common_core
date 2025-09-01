/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/01 23:06:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(int filter)
{
	int	i;

	this->filter = filter;
	i = -1;
	while (++i < LV_NUM)
		this->ft[i] = &Harl::empty;
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
{}

void	Harl::complain(string s)
{
	int	level;

	if (valid_input(s) == false)
		return ;
	std::cout << "[ " << s << " ]" << std::endl;
	std::cout << "[ ";
	if (filter_check(s, this->filter) == 1)
		return (std::cout << MSG_IGNORED << " ]\n\n", (void)0);
	level = alpha_hash(s);
	(this->*ft[level])();
	std::cout << " ]\n\n";
}

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

Harl::Harl()
{
	int	i;

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
	std::cout << MSG_DEBUG << std::endl;
}

void	Harl::info(void)
{
	std::cout << MSG_INFO << std::endl;
}

void	Harl::warning(void)
{
	std::cout << MSG_WARNING << std::endl;
}

void	Harl::error(void)
{
	std::cout << MSG_ERROR << std::endl;
}

void	Harl::empty(void)
{}

void	Harl::complain(std::string s)
{
	int	level;

	if (valid_input(s) == false)
		return ;
	level = alpha_hash(s);
	(this->*ft[level])();
}

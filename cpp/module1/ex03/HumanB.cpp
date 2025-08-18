/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/17 09:59:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

HumanB::HumanB(string name)
{
	this->weapon = 0;
	this->name = name;
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	if (!weapon)
	{
		std::cout << "bare hands! What? Is he crazy?? " << name << ", wtf?";
	}
	else
		std::cout << weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

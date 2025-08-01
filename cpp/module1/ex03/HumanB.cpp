/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/26 15:54:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

HumanB::HumanB(string name)
{
	Weapon	unarmed;

	this->weapon = &unarmed;
	this->name = name;
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	const string	&weapon_type = weapon->getType();

	std::cout << name << " attacks with their ";
	if (weapon_type.empty())
	{
		std::cout << "bare hands! What? Is he crazy?? " << name << ", wtf?";
	}
	else
		std::cout << weapon_type;
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}

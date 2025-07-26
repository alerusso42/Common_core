/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/26 15:55:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

HumanA::HumanA(string name, Weapon weapon)
{
	this->weapon = &weapon;
	this->name = name;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	const string	&weapon_type = weapon->getType();

	std::cout << name << " attacks with their " << weapon_type;
	std::cout << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}

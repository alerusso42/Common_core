/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/17 09:41:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

HumanA::HumanA(string name, Weapon &weapon)
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

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA(void)
{}

void	HumanA::attack(void)
{
	const std::string	 &weapon_type = weapon.getType();

	std::cout << name << " attacks with their " << weapon_type;
	std::cout << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	(void)weapon;
	std::cout << "cannot assign " << weapon.getType() << ": ";
	std::cout << this->name << " has already weapon " << this->weapon.getType();
	std::cout << std::endl;
}

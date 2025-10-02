/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
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

HumanB::HumanB(std::string name) 
{
	this->name = name;
	this->weapon = NULL;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/26 16:06:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

Weapon::Weapon()
{
	type.clear();
}

Weapon::Weapon(string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	type.clear();
}

const string	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(string new_type)
{
	this->type.assign(new_type);
}

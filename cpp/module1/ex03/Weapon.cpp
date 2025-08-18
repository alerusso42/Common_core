/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/17 09:54:16 by codespace        ###   ########.fr       */
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
	this->type = new_type;
}

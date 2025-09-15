/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->setType("ice");
}

Ice::~Ice()
{}

Ice::Ice(const Ice &other) : AMateria(other.getType())
{ 
	this->setType(other.getType());
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other) 
	{
		this->setType(other.getType());
	}
	return *this;
}

Ice	*Ice::clone() const
{
	Ice	*this_clone = new Ice();

	if (!this_clone)
		return (NULL);
	this_clone->setType(this->getType());
	return (this_clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice: '* shoots an ice bolt at ";
	std::cout << target.getName() << " *'";
	std::cout << std::endl;
}

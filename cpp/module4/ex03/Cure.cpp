/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->setType("cure");
}

Cure::~Cure()
{}

Cure::Cure(const Cure &other) : AMateria(other.getType())
{ 
	this->setType(other.getType());
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other) 
	{
		this->setType(other.getType());
	}
	return *this;
}

Cure	*Cure::clone() const
{
	Cure	*this_clone = new Cure();

	if (!this_clone)
		return (NULL);
	this_clone->setType(this->getType());
	return (this_clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure: '* heals ";
	std::cout << target.getName() << "'s wounds *'";
	std::cout << std::endl;
}

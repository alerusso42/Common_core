/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	if (std::rand() % 2)
	{
		this->type_val = ICE;
		this->type = "ice";
	}
	else
	{
		this->type_val = CURE;
		this->type = "cure";
	}
}

AMateria::AMateria(std::string const &type)
{
	this->setType(type);
}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria &other)
{
	this->type = other.type;
	this->type_val = other.type_val;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "WHY DID I BUY " << target.getName() << "ON ALIEXPRESS?!!";
	std::cout << std::endl;
}

void	AMateria::setType(std::string const newtype)
{
	this->type_val = AMateria_type_finder(newtype);
	this->type = newtype;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

int	AMateria::getIdx() const
{
	return (this->type_val);
}

int	AMateria_type_finder(const std::string &s)
{
	if (!s.compare("ice"))
		return (ICE);
	else if (!s.compare("cure"))
		return (CURE);
	else
	{
		std::cout << "This item is useless!" << std::endl;
		return (NONE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "";
	std::cout << "AAnimal " << this->type << ":\tCostructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << this->type << ":\tDestructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{ 
	this->type = other.type;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

const string	&AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal " << this->type << ":\tUDDIO CHI E ൠ" << std::endl;
}

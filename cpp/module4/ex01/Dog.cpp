/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "dog";
	this->ideas = new Brain();
	std::cout << "Dog " << this->type << ":\tCostructor" << std::endl;
}

Dog::~Dog()
{
	delete this->ideas;
	std::cout << "Dog " << this->type << ":\tDestructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
	if (this == &other)
		return ;
	this->type = other.type;
	this->ideas = new Brain();
	*this->ideas = *other.ideas;

}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
		*this->ideas = *other.ideas;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog " << this->type << ":\tBAU 🐕" << std::endl;
}

const Brain	&Dog::abilities(void) const
{
	return (*this->ideas);
}

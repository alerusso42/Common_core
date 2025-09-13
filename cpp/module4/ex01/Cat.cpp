/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "cat";
	this->ideas = new Brain();
	std::cout << "Cat " << this->type << ":\tCostructor" << std::endl;
}

Cat::~Cat()
{
	delete this->ideas;
	std::cout << "Cat " << this->type << ":\tDestructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{ 
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	Cat::makeSound()  const
{
	std::cout << "Cat " << this->type << ":\tMIAO 🐈" << std::endl;
}

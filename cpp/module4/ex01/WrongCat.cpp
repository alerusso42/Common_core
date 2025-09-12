/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "cat";
	std::cout << "WrongCat " << this->type << ":\tCostructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << this->type << ":\tDestructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{ 
	this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat " << this->type << ":MIAO 🐈" << std::endl;
}

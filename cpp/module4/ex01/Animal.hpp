/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include "header.hpp"

class Animal
{
protected:
	string	type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	const string	&getType() const;
	virtual void	makeSound() const;
};

#include "Dog.hpp"
#include "Cat.hpp"

#endif

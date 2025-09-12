/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include "header.hpp"

class WrongAnimal
{
protected:
	string	type;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	string			&getType();
	void	makeSound() const;
};

#include "WrongCat.hpp"

#endif

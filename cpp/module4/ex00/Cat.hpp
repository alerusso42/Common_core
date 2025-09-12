/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "header.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	void	makeSound() const;
};

#endif

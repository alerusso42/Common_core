/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:33:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/28 09:31:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
*/

Brain::Brain()
{
	std::string	 random_ideas[] = {RAND_IDEAS};
	int	i;
	int	random;

	i = 0;
	while (i != IDEAS)
	{
		random = (std::rand() % TOTAL_IDEAS);
		this->ideas[i] = random_ideas[random];
		++i;
	}
	std::cout << "Brain :\t\tconstructor" << std::endl;
}

Brain::Brain(std::string s)
{
	int	i;

	i = 0;
	while (i != IDEAS)
	{
		this->ideas[i] = s;
		++i;
	}
	std::cout << "Brain :\t\tconstructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain:\t\tdestructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	int	i;

	i = 0;
	while (i != IDEAS)
	{
		this->ideas[i] = other.ideas[i];
		++i;
	}
	std::cout << "Brain :\t\tconstructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	int	i;

	if (this == &other)
		return (*this);
	i = 0;
	while (i != IDEAS)
	{
		this->ideas[i] = other.ideas[i];
		++i;
	}
	return (*this);
}

void	Brain::thinking(void) const
{
	int	i;

	i = std::rand() % this->IDEAS;
	std::cout << "\033[34m" << this->ideas[i] <<"\033[0m" << std::endl; 
}

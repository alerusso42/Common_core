/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:33:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/13 17:05:46 by alerusso         ###   ########.fr       */
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
	string	random_ideas[] = {RAND_IDEAS};
	int	i;
	int	random;

	i = 0;
	while (i != IDEAS)
	{
		random = (std::rand() % TOTAL_IDEAS);
		this->ideas[i] = random_ideas[random];
		++i;
	}
}

Brain::Brain(string s)
{
	int	i;

	i = 0;
	while (i != IDEAS)
	{
		this->ideas[i] = s;
		++i;
	}
}

Brain::~Brain()
{}

Brain::Brain(const Brain &other)
{
	int	i;

	i = 0;
	while (i != IDEAS)
	{
		this->ideas[i] = other.ideas[i];
		++i;
	}
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
}

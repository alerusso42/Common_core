/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	if (name.empty() == true)
		return ;
	std::cout << name << ": " << MSG << std::endl;
}

void	Zombie::set(std::string zombie_name, bool alloc_heap)
{
	heap = alloc_heap;
	name = zombie_name;
}

bool	Zombie::empty(void)
{
	return (name.empty());
}

Zombie::Zombie()
{
	this->heap = false;
}

Zombie::Zombie(const std::string &name, bool heap)
{
	this->heap = heap;
	this->name = name;
}

Zombie::~Zombie()
{
	if (heap == true)
		std::cout << name << "bleah, heap! Disgusting." << std::endl;
	else
		std::cout << name << " has been eaten!" << std::endl;
}

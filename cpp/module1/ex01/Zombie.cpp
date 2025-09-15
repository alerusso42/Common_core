/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 20:53:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	if (name.empty() == true)
		return ;
	std::cout << name << ": " << MSG << std::endl;
}

void	Zombie::set(string zombie_name, bool alloc_heap)
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

Zombie::Zombie(const string &name, bool heap)
{
	this->heap = heap;
	this->name = name;
}

Zombie::~Zombie()
{
	if (heap == true)
		std::cout << "bleah, heap! Disgusting." << std::endl;
	else
		std::cout << name << " has been eaten!" << std::endl;
}

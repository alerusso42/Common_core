/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/07 09:55:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	if (name.empty() == true)
		return ;
	std::cout << name << ": " << MSG << std::endl;
}

Zombie::Zombie(std::string zombie_name, bool alloc_heap)
{
	heap = alloc_heap;
	name = zombie_name;
}

Zombie::~Zombie()
{
	if (heap == true)
		std::cout << name << " bleah, heap! Disgusting." << std::endl;
	else
		std::cout << name << " has been eaten!" << std::endl;
}

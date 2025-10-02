/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

  

class Zombie
{
public:
	void	announce(void);
	bool	empty(void);
	void	set(std::string name, bool heap);
	Zombie(const std::string &name, bool heap);
	Zombie();
	~Zombie();
private:
	std::string	 name;
	bool	heap;
};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

# define MSG "BraiiiiiiinnnzzzZ..."

#endif
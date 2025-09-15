/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 20:50:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

typedef	std::string	string;

class Zombie
{
public:
	void	announce(void);
	bool	empty(void);
	void	set(string name, bool heap);
	Zombie(const string &name, bool heap);
	Zombie();
	~Zombie();
private:
	string	name;
	bool	heap;
};

Zombie	*newZombie(string name);
void 	randomChump(string name);
Zombie* zombieHorde(int N, std::string name);

# define MSG "BraiiiiiiinnnzzzZ..."

#endif
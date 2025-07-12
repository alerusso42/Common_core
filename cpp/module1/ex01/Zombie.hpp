/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/12 14:18:22 by codespace        ###   ########.fr       */
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
	void announce( void );
	Zombie(string name, bool heap);
	~Zombie();
private:
	string	name;
	bool	heap;
};

Zombie	*newZombie(string name);
void 	randomChump(string name);

# define MSG "BraiiiiiiinnnzzzZ..."

#endif
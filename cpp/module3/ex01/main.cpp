/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:56:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 11:56:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main() 
{
	string		random_names[] = {RAND_NAMES};
	std::srand(random_gen());
	ScavTrap	scav(random_names[std::rand() % 3]);
	ScavTrap	scav1(random_names[std::rand() % 3]);

	scav.attack(random_names[std::rand() % 3]);
	scav.beRepaired(10);
	scav.takeDamage(30);
	scav.attack(random_names[std::rand() % 3]);
	scav.beRepaired(40);
	scav.attack(random_names[std::rand() % 3]);
	scav1.guardGate();
	scav1.guardGate();
	return (0);
}

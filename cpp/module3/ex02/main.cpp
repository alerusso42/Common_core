/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:07:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 16:07:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main() 
{
	string		random_names[] = {RAND_NAMES};
	std::srand(random_gen());
	ClapTrap	clap(random_names[std::rand() % 3]);
	ScavTrap	scav(random_names[std::rand() % 3]);
	FragTrap	frag(random_names[std::rand() % 3]);

	scav.attack(frag.getname());
	scav.beRepaired(10);
	scav.takeDamage(30);
	scav.attack(frag.getname());
	scav.beRepaired(40);
	scav.attack(frag.getname());
	clap.takeDamage(74);
	clap.attack(frag.getname());
	frag.highFivesGuys();
	frag.attack(frag.getname());
	return (0);
}

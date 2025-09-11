/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:17:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 09:17:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main() 
{
	string		random_names[] = {RAND_NAMES};
	ClapTrap	clap;

	std::srand(random_gen());
	clap.attack(random_names[std::rand() % 3]);
	clap.beRepaired(12);
	clap.takeDamage(123);
}

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
	std::string	 	random_names[] = {RAND_NAMES};
	std::srand(random_gen());
	DiamondTrap	d(random_names[std::rand() % 3]);

	d.print_stats();
	d.attack(random_names[std::rand() % 3]);
	return (0);
}

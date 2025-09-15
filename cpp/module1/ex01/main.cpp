/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 20:51:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	Zombie	*lonely;
	int		i;

	horde = zombieHorde(5, "Silvio Berlusconi");
	if (horde == NULL)
		return (std::cerr << "Era meglio malloc\n", 1);
	lonely = new Zombie("Mega Rayquaza", true);
	i = 0;
	while (horde[i].empty() == false)
	{
		std::cout << "[" << i << "]";
		horde[i].announce();
		++i;
	}
	lonely->announce();
	delete[] horde;
	delete lonely;
}

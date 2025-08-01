/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/13 15:40:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int		i;

	horde = zombieHorde(-1, "Silvio Berlusconi");
	if (horde == NULL)
		return (std::cout << "Era meglio malloc\n", 1);
	i = 0;
	while (horde[i].empty() == false)
	{
		std::cout << "[" << i << "]";
		horde[i].announce();
		++i;
	}
	delete[] horde;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/12 14:27:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*silvio;

	silvio = newZombie("Silvio Berlusconi");
	if (silvio == NULL)
		return (std::cout << "Era meglio malloc\n", 1);
	silvio->announce();
	delete silvio;
	randomChump("Hihi Michael Jackson");
}

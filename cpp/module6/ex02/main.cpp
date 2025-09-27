/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main1() 
{
	Base	*random;

	std::srand(random_gen());
	tty_clear();
	random = generate();
	std::cout << "Base is:\t";
	identify(random);
	std::cout << std::endl;
	delete random;
	return 0;
}

int main() 
{
	Base	*random;

	std::srand(random_gen());
	tty_clear();
	random = generate();
	std::cout << "Identify result:\t";
	identify(*random);
	std::cout << std::endl;
	delete random;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/01 23:07:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//	D	359
//	I	300
//	W	534
//	E	394
//	divided by ten
int	main(int argc, char *argv[])
{
	if (argc != 2 || valid_input(argv[1]) == false)
		return (std::cerr << USAGE << std::endl, 1);
	Harl	harl(alpha_hash(argv[1]));

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("ERRO");
	harl.complain("ERRORR");
	return (0);
}

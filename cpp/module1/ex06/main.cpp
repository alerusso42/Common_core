/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 12:41:43 by alerusso         ###   ########.fr       */
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
	Harl	harl(argv[1]);
	harl.complain();
	return (0);
}

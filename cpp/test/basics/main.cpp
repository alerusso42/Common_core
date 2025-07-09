/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:37:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/09 14:49:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

//NOTE cosa succede se fallisce cin
/*
int	main()
{
	int		a;
	char	b[20];
	int		c;

	std::cin >> a >> b >> c;
	std::cout << a << b << c;
}*/

#include <fstream>
#include <iostream>


int main(int argc, char *argv[]) 
{
	std::string	s;
	int			i;
	int			j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		s = argv[i];
		while (s[j])
		{
			s[j] = std::toupper(s[j]);
			j++;
		}
		std::cout << s;
		++i;
	}
	std::cout << std::endl;
}

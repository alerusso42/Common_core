/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:52:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:52:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main()
{
	std::map<Date, double>	m;

	try
	{
		Date	date("2004-03-31", '-', false);
		std::cout << date << std::endl;
		date.basic_print(std::cout);
		std::cout << std::endl;
	}
	catch(const Error &e)
	{
		e.print();
	}
	(void)m;
	std::cout << sizeof(Date) << std::endl;
	return 0;
}

int main2() 
{
	std::cout << sizeof(Date) << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:15:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/30 10:15:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main() 
{
	Span	span(4);

	random_seed();
	try
	{
		span.addNumber(0);
		span.addNumber(2);
		span.addNumber(4);
		std::cout << span.shortestSpan() << "\n";
		std::cout << span.longestSpan() << "\n";
	}
	catch(const Error& e)
	{
		e.print();
	}
	std::cout << std::endl;
}

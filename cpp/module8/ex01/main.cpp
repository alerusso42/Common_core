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
	Span	span(3);

	random_seed();
	try
	{
		span.addNumber(24);
		span.addNumber(42);
		span.addNumber(880);
		span.generate();
		span.print();
		std::cout << "shortestSpan:\t" << span.shortestSpan() << "\n";
		std::cout << "longestSpan:\t" << span.longestSpan() << "\n";
	}
	catch(const Error& e)
	{
		e.print();
	}
	std::cout << std::endl;
}

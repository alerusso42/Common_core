/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:05:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/16 15:05:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//SECTION - cannot decrement
int main()
{
	Bureaucrat	b(150);

	std::srand(random_gen());
	try
	{
		b.decrement();
	}
	catch(const Error &e)
	{
		e.print();
	}
	std::cout << b;
	return (0);
}

//SECTION - cannot increment
int main2()
{
	Bureaucrat	b(1);

	std::srand(random_gen());
	try
	{
		b.increment();
	}
	catch(const Error &e)
	{
		e.print();
	}
	std::cout << b;
	return (0);
}

//SECTION - constructor grade too high
int main3()
{
	std::srand(random_gen());
	try
	{
		Bureaucrat	a(0);
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

//SECTION - constructor grade too low
int main4()
{
	std::srand(random_gen());
	try
	{
		Bureaucrat	a(151);
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

//SECTION - normal use
int main5()
{
	Bureaucrat	b(150);

	std::srand(random_gen());
	try
	{
		b.increment();
		b.decrement();
	}
	catch(const Error &e)
	{
		e.print();
	}
	std::cout << b;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Base::Base()
{

}

Base::~Base()
{

}

Base::Base(const Base &other)
{ 
	(void)other;
}

Base &Base::operator=(const Base &other)
{
	if (this != &other) 
	{
		// add field
	}
	return (*this);
}

/*
It randomly instantiates A, B, or C and returns the instance as a Base pointer.
 Feel free to use anything you like for the random choice implementation.
*/
Base * generate(void)
{
	std::cout << "Generated class:\t";
	switch (std::rand() % CLASS_TOTAL)
	{
		case (CLASS_A):
			return (std::cout << "A\n", new A());
		case (CLASS_B):
			return (std::cout << "B\n", new B());
		case (CLASS_C):
			return (std::cout << "C\n", new C());
		default:
			return (NULL);
	}
}

/*
It prints the actual type of the object pointed to by p: "A", "B", or "C".
*/
void identify(Base* p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	if (a)
		return (std::cout << "A", (void)0);
	b = dynamic_cast<B *>(p);
	if (b)
		return (std::cout << "B", (void)0);
	c = dynamic_cast<C *>(p);
	if (c)
		return (std::cout << "C", (void)0);
}

/*
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.
*/
void identify(Base& p)
{
	if (dynamic_cast<A *>(&p))
		return (std::cout << "A", (void)0);
	if (dynamic_cast<B *>(&p))
		return (std::cout << "B", (void)0);
	if (dynamic_cast<C *>(&p))
		return (std::cout << "C", (void)0);
}

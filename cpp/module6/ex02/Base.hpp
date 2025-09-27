/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include "lib/lib.hpp"

enum e_classes
{
	CLASS_A,
	CLASS_B,
	CLASS_C,
	CLASS_TOTAL,
};

class	A;
class	B;
class	C;

class Base
{
public:
//	canonic form:
	Base();
	virtual ~Base();
	Base(const Base &other);
	Base &operator=(const Base &other);
};

/*
It randomly instantiates A, B, or C and returns the instance as a Base pointer.
 Feel free to use anything you like for the random choice implementation.
*/
Base * generate(void);

/*
It prints the actual type of the object pointed to by p: "A", "B", or "C".
*/
void identify(Base* p);

/*
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.
*/
void identify(Base& p);

#endif
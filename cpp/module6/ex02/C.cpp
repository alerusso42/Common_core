/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C():	Base(Base())
{

}

C::~C()
{

}

C::C(const C &other):	Base(Base())
{ 
	(void)other;
}

C &C::operator=(const C &other)
{
	if (this != &other) 
	{
		// add field
	}
	return (*this);
}

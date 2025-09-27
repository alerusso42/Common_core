/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B():	Base(Base())
{

}

B::~B()
{

}

B::B(const B &other):	Base(Base())
{ 
	(void)other;
}

B &B::operator=(const B &other)
{
	if (this != &other) 
	{
		// add field
	}
	return (*this);
}

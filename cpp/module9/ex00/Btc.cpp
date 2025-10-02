/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btc.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:52:00 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:52:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Btc.hpp"

Btc::Btc()
{

}

Btc::~Btc()
{

}

Btc::Btc(const Btc &other)
{ 
	(void)other;
}

Btc &Btc::operator=(const Btc &other)
{
	if (this != &other) 
	{
		// add field
	}
	return (*this);
}

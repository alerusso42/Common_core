/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:19:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 15:29:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#define TPP template<typename T>

template	<typename T>
void	swap(T &x, T &y)
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template	<typename T>
T	&min(T &x, T &y)
{
	return (x < y ? x: y);
}

TPP T	&max(T &x, T &y)
{
	return (x > y ? x: y);
}

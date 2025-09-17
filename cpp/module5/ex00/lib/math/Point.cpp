/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:33:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/10 11:33:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y)
{}

Point::~Point()
{}

Point::Point(const Point &other) : x(other.x), y(other.y)
{ 
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

void	Point::get_coords(Fixed coords[2]) const
{
	coords[X] = this->x;
	coords[Y] = this->y;
}

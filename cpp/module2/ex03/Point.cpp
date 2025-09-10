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

#include "Point.hpp"

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

//	1/2	|	x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)	|
Fixed const	triangle_area(Point const a, Point const b, Point const c)
{
	Fixed	area;
	Fixed	coord_a[2];
	Fixed	coord_b[2];
	Fixed	coord_c[2];

	a.get_coords(coord_a);
	b.get_coords(coord_b);
	c.get_coords(coord_c);
	area = coord_a[X] * (coord_b[Y] - coord_c[Y]);
	area += coord_b[X] * (coord_c[Y] - coord_a[Y]);
	area += coord_c[X] * (coord_a[Y] - coord_b[Y]);
	if (area < 0)
		area *= -1;
	area /= 2;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	point_area[3];
	Fixed	original_area;
	int		i;

	original_area = triangle_area(a, b, c);
	i = 0;
	point_area[i++] = triangle_area(a, b, point);
	point_area[i++] = triangle_area(b, c, point);
	point_area[i++] = triangle_area(c, a, point);
	while (i--)
	{
		if (point_area[i] == 0)
			return (false);
		original_area -= point_area[i];
	}
	if (original_area != 0)
		return (false);
	return (true);
}

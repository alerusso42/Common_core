/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:33:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 09:10:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../lib.hpp"

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

/*
	return false if a Point is outside a triangle;
	return false if the Point is touching a corner;
	else, return true.
			C
			/
		/		/			1)	we find triangle ABC area;
	/		.P		/		2)	we find triangle ABP, BCP, CAP area;
/_______________________/	3)	so, the we have found the area of the
A						B		three subtriangles;
							4)	the sum of these triangles area must be
								equal to the ABC triangle;
							5)	if it is, that's inside. Else, is outside;
							6)	if one of the three is zero, the point P
								is colliding to at least one side of
								ABC. We don't want it, so false is returned.

*/
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

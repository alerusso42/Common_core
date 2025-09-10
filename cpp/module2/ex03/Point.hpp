/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:33:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/10 11:33:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "header.hpp"

class Point
{
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point();
	Point(Fixed const x, Fixed const y);
	~Point();
	Point(const Point &other);
	Point &operator=(const Point &other);
	void	get_coords(Fixed coords[2]) const;
};

bool		bsp(Point const a, Point const b, Point const c, Point const point);
Fixed const	triangle_area(Point const a, Point const b, Point const c);

#endif

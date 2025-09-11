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

#pragma once
#ifndef POINT_HPP
# define POINT_HPP
# include "fpoint/Fixed.hpp"

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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 08:59:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/13 10:12:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp" 

int32_t	&Map::operator()(int32_t x, int32_t y)
{
	this->_normalize_access(x, y);
	return (this->_map[y][x]);
}

int32_t	&Map::operator()(int32_t x, int32_t y, bool mode)
{
	this->setmode(mode);
	this->_normalize_access(x, y);
	return (this->_map[y][x]);
}

int32_t	&Map::operator()(int32_t pos[2])
{
	this->_normalize_access(pos[X], pos[Y]);
	return (this->_map[pos[Y]][pos[X]]);
}

int32_t	&Map::operator()(int32_t pos[2], bool mode)
{
	this->setmode(mode);
	this->_normalize_access(pos[X], pos[Y]);
	return (this->_map[pos[Y]][pos[X]]);
}

void	Map::_normalize_access(int32_t &x, int32_t &y)
{
	if (this->_mode_pixel == true)
	{
		x /= this->BLOCK;
		y /= this->BLOCK;
	}
	if (x < 0)
		x = 0;
	else if (x >= (int32_t)this->_x_size)
		x = this->_x_size - 1;
	if (y < 0)
		y = 0;
	else if (y >= (int32_t)this->_y_size)
		y = this->_y_size - 1;
}

void	Map::setmode(bool mode)
{
	this->_mode_pixel = mode;
}

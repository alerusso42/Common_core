/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:33:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/12 17:59:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

Map::Map(int32_t x, int32_t y)
{
	this->_x_size = 0;
	this->_y_size = 0;
	try
	{
		this->_allocate_map(x, y);
	}
	catch(const Error& e)
	{
		e.print();
	}
}

Map::Map(const int8_t **map)
{
	int32_t	x = 0;
	int32_t	y = 0;

	while (map[y])
		++y;
	while (map[0][x])
		++x;
	this->_x_size = 0;
	this->_y_size = 0;
	try
	{
		this->_allocate_map(x, y);
		this->fill(map, x, y);
	}
	catch(const Error& e)
	{
		e.print();
	}
}

Map::~Map()
{
	for (u_int32_t i = 0; i < this->_y_size; i++)
		delete [] (this->_map[i]);
	delete [] (this->_map);
}

Map::Map(const Map &other)
{
	(void)other;
}

Map	&Map::operator=(const Map &other)
{
	(void)other;
	return (*this);
}

void	Map::_allocate_map(int32_t x, int32_t y)
{
	if (x < 0)
		throw (Error(EX_MAP_X_LOW, 0, x));
	else if (y < 0)
		throw (Error(EX_MAP_Y_LOW, 0, y));
	else if (x > this->MAX)
		throw (Error(EX_MAP_X_HIGH, 0, MAX));
	else if (y > this->MAX)
		throw (Error(EX_MAP_Y_HIGH, 0, MAX));
	this->_map = new int32_t *[y];
	this->_x_size = x;
	for (int32_t i = 0; i != y; i++)
	{
		this->_map[i] = new int32_t[x];
		for (int32_t j = 0; j < x; j++)
			this->_map[i][j] = '\0';
		this->_y_size += 1;
	}
}

void	Map::fill(const int8_t **map)
{
	int32_t	x = 0;
	int32_t	y = 0;

	while (map[y])
		++y;
	while (map[0][x])
		++x;
	for (int32_t i = 0; i < y; i++)
	{
		for (int32_t j = 0; j < x; j++)
			this->_map[i][j] = map[i][j];
	}
}

void	Map::fill(const int8_t **map, int32_t x, int32_t y)
{
	for (int32_t i = 0; i < y; i++)
	{
		for (int32_t j = 0; j < x; j++)
			this->_map[i][j] = map[i][j];
	}
}

void	Map::print(void) const
{
	std::cout << "MAP:\n";
	for (u_int32_t y = 0; y < this->_y_size; y++)
	{
		std::cout << std::endl;
		for (u_int32_t x = 0; x < this->_x_size; x++)
			std::cout << (int8_t)this->_map[y][x];
	}
	std::cout << std::endl;
}

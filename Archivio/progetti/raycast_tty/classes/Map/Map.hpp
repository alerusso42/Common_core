/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:06:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/12 18:08:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../../includes/lib/lib.hpp"
# include <stdarg.h>
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <mutex>
# include <thread>
# include <map>
# ifdef _WIN32
#  include <conio.h>
#  include <windows.h>
# elif defined(__linux__) || defined(__APPLE__)
#  include <termios.h>
#  include <unistd.h>
#  include <sys/ioctl.h>
# else
#  error "OS has not terminal support"
# endif

class Map
{
private:
	int32_t		**_map;
	u_int32_t	_x_size;
	u_int32_t	_y_size;
	bool		_mode_pixel;

	//SECTION - init
	void	_allocate_map(int32_t x, int32_t y);
public:
	Map(int32_t x, int32_t y);
	Map(const int8_t **map);
	~Map();
	Map(const Map &other);
	Map	&operator=(const Map &other);

	enum e_map
	{
		BLOCK =		64,
		MAX =		1000,
		Mdata =		0,
		Mpixel =	1,
	};
	void	print(void) const;
	void	fill(const int8_t **map);
	void	fill(const int8_t **map, int32_t x, int32_t y);
	void	setmode(bool mode);
	int32_t	&operator()(int32_t x, int32_t y);
	int32_t	&operator()(int32_t x, int32_t y, bool mode);
	int32_t	&operator()(int32_t pos[2]);
	int32_t	&operator()(int32_t pos[2], bool mode);
};

# define SAMPLE_MAP "111111111\0",\
					"100000001\0",\
					"101100101\0",\
					"1010P0001\0",\
					"100100101\0",\
					"100000001\0",\
					"111111111\0",\
					NULL
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 08:07:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/13 10:17:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/raycast_tty.hpp"

static void		hit_finder(Map &map, Fixed &angle, int32_t hit_coord[2]);
static bool		the_wall_checker(Map &map, Fixed coord[2]);
static int32_t	heigth_finder(Map &map, Fixed &angle, int32_t hit[2], Term &tty);

void	raycast(Term &tty, Map &map)
{
	int32_t	x_size;
	int32_t	y_size;
	Fixed	p_pov;
	Fixed	angle;
	int32_t	hit_coord[2];

	map.setmode(map.Mpixel);
	tty.get_size(&x_size, &y_size);
	p_pov = map.get_player_pov();
	for (int32_t i = 0; i < x_size; i++)
	{
		angle = (float)((RADIANT * i) / x_size) * FOV;
		angle += p_pov;
		hit_finder(map, angle, hit_coord);
		tty.draw_column(heigth_finder(map, angle, hit_coord, tty));
	}
	map.setmode(map.Mdata);
}

static void	hit_finder(Map &map, Fixed &angle, int32_t hit_coord[2])
{
	Fixed	coord[2];
	Fixed	step[2];

	map.get_player_pos(&hit_coord[X], &hit_coord[Y]);
	coord[X] = hit_coord[X];
	coord[Y] = hit_coord[Y];
	step[X] = std::cos(angle.toFloat());
	step[Y] = std::sin(angle.toFloat());
	while (the_wall_checker(map, coord) == false)
	{
		coord[X] += step[X];
		coord[Y] += step[Y];
	}
	hit_coord[X] = coord[X].toInt();
	hit_coord[Y] = coord[Y].toInt();
}

static bool	the_wall_checker(Map &map, Fixed coord[2])
{
	int32_t	value;

	value = map(coord[X].toInt(), coord[Y].toInt());
	if (value == map.S_WALL)
		return (true);
	return (false);
}

static int32_t	heigth_finder(Map &map, Fixed &angle, int32_t hit[2], Term &tty)
{
	Fixed	ray;
	int32_t	px;
	int32_t	py;
	int32_t	rx;
	int32_t	ry;

	map.get_player_pos(&px, &py);
	rx = hit[X];
	ry = hit[Y];
	ray = (float)sqrt(pow((float)(rx - px), 2) + pow((float)(ry - py), 2));
	ray *= std::cos(angle.toFloat() - map.get_player_pov().toFloat());//fisheye
	return ((int32_t)tty.get_size_y() * 15 / ray.toFloat());
}

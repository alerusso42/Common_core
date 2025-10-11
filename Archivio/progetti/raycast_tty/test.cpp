/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:51:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/10 21:58:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.hpp"

/*
# define MAP 	"111111111", \
				"100000001", \
				"100011101", \
				"100000101", \
				"1100P0001", \
				"100010001", \
				"100000001", \
				"111111111", \
				"#"

void	copy_map(term *t)
{
	int		i;
	int		j;
	char	map[10][10] = {MAP};

	i = 0;
	while (map[i][0] != '#')
	{
		j = 0;
		while (map[i][j])
		{
			t->map[i][j] = map[i][j];
			++j;
		}
		++i;
	}
}
void	print_column(term *t)
{
	int	y;
	int	stop;

	y = t->term_y / 2;
	std::cout << "\033[" << t->term_y / 2 << ";" << t->column << "H";
	stop = y + (t->height / 2);
	while (y < stop && y < t->term_y)
	{
		std::cout << "\u2588";
		std::cout << "\033[1B";
		std::cout << "\033[1D";
		++y;
	}
	y = t->term_y / 2;
	std::cout << "\033[" << t->term_y / 2 << ";" << t->column << "H";
	stop = y - (t->height / 2);
	while (y && y > stop)
	{
		std::cout << "\u2588";
		std::cout << "\033[1A";
		std::cout << "\033[1D";
		--y;
	}
	t->column++;
}*/
			

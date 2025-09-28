/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:57:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 10:26:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.hpp"

int	random_char()
{
	fstream	fd;
	char	s[2] = "";

	fd.open("/dev/random");
	if (fd.fail())
		return (std::cerr << "cannot open /dev/random", 0);
	fd.read(s, 1);
	fd.close();
	if (s[0] < 0)
		return (s[0] + 255);
	return (s[0]);
}

int	random_int()
{
	int	i;
	int	byte;
	int	curr_byte;
	int	random_value;

	random_value = 0;
	curr_byte = 8;
	i = 0;
	while (i != 32)
	{
		byte = random_char();
		while (i != curr_byte)
		{
			random_value += ((byte & 1 << (i % 8)) != 0) << i;
			++i;
		}
		curr_byte += 8;
	}
	return (random_value);
}

void	random_seed()
{
	std::srand(random_gen());
}

int	random_gen()
{
	return (random_int());
}

int	random_gen(size_t size)
{
	return (random_gen() % size);
}

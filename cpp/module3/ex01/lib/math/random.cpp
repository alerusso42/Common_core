/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:57:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 11:28:56 by alerusso         ###   ########.fr       */
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

int	random_gen()
{
	return (random_char());
}

int	random_gen(size_t size)
{
	return (random_gen() % size);
}

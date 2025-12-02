/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* std::string	 .cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:55:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/11 17:38:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

//	returns 0 on success, 1 on failure.
//	func parameter must be a function int (*func)(int).
bool	check_str(std::string s, int (*func)(int), int expect_res, int pos)
{
	int		i;
	int		res;	

	if (pos < 0 || pos > (int)s.size())
		return (1);
	i = pos;
	while (i < (int)s.size())
	{
		res = func(s[i]);
		if (res == false && expect_res == true)
			return (1);
		else if (res != false && expect_res == false)
			return (1);
		++i;
	}
	return (0);
}

/*
//REVIEW - valid_input

Return true(1) if success, else false(0)
input is invalid when:

1)	Is empty;
2)	Its size surpasses INPUT_MAX;
3)	It has non printable characters.
*/
bool	valid_input(std::string s)
{
	int	i;

	if (s.empty() == true)
		return (std::cerr << "\033[1;31mBad value\n\033[0m", false);
	if (s.size() >= 10000)
		return (std::cerr << "\033[1;31mBad value\n\033[0m", false);
	i = 0;
	while (s[i])
	{
		if (std::isprint(s[i]) == false)
			return (std::cerr << "\033[1;31mBad value\n\033[0m", false);
		++i;
	}
	return (true);
}

//	Returns:
//	0:	success
//	1:	std::string is invalid
//	2:	non digit char in s
int	ft_atoi(std::string s, int *n)
{
	if (valid_input(s) == false)
		return (1);
	if (std::isdigit(s[0]) == false && s[0] != '+' && s[0] != '-')
		return (2);
	if (check_str(s, std::isdigit, true, 1) == 1)
		return (2);
	if (n)
		*n = std::atoi(s.c_str());
	return (0);
}

//	Returns:
//	0:	success
//	1:	std::string is invalid
//	2:	non digit char in s
//	3:	pos is invalid
//	N can be NULL.
int	ft_atoi(std::string s, int *n, int pos)
{
	if (pos < 0)
		return (3);
	if (s.length() <= (size_t)pos)
		return (3);
	if (valid_input(s) == false)
		return (1);
	if (std::isdigit(s[pos]) == false && s[pos] != '+' && s[pos] != '-')
		return (2);
	if (std::isdigit(s[pos]) == false && std::isdigit(s[pos + 1]) == false)
		return (2);
	if (n)
		*n = std::atoi(s.c_str() + pos);
	return (0);
}

//	Returns:
//	0:	success
//	1:	std::string is invalid
//	2:	bad first char
//	3:	invalid char in string
//	4:	too many dots
//	4:	.f
//#include <math.h>
bool	valid_number(std::string s, bool is_float)
{
	int	i;
	int	n_dots;

	if (valid_input(s) == false)
		return (1);
	if (s.length() == 1 && s[0] > 31 && s[0] < 127)
		return (0);
	if (std::isdigit(s[0]) == false && s[0] != '+' && s[0] != '-')
		return (2);
	i = 1;
	n_dots = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (!s[i + 1] || s[i + 1] == 'f')
				return (4);
			n_dots += 1;
		}
		else if (std::isdigit(s[i]) == false && (s[i] != 'f' || s[i + 1]))
			return (3);
		i++;
	}
	if (s[i - 1] != 'f' && std::isdigit(s[i - 1] == false))
		return (3);
	if (n_dots > is_float)
		return (4);
	return (0);
}

/*
int	main()
{
	std::cout << ft_itoa(0) << std::endl;
	std::cout << ft_itoa(8) << std::endl;
	std::cout << ft_itoa(-1) << std::endl;
	std::cout << ft_itoa(-9) << std::endl;
	std::cout << ft_itoa(120) << std::endl;
	std::cout << ft_itoa(-1230) << std::endl;
	std::cout << ft_itoa(9348394) << std::endl;
}*/

/*
int	main(int ac, char *av[])
{
	int	n;

	if (ac == 1)
		return (1);
	if (ft_atoi(av[1], &n) != 0)
		return (std::cout << "error\n", 2);
	std::cout << n << std::endl;
}*/

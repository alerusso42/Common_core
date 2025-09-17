/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std::string.cpp                                         :+:      :+:    :+:   */
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

//	revert the content of a string
std::string	ft_reverse(std::string s)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (int)s.size() / 2)
	{
		temp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = temp;
		i++;
	}
	return (s);
}

//	integer to ascii
std::string	ft_itoa(int n)
{
	std::string	s;
	bool	minus;

	if (n == 0)
	{
		s += '0';
		return (s);
	}
	minus = false;
	if (n < 0)
		minus = true;
	while (n != 0)
	{
		s += ((char)std::abs(n % 10) + '0');
		n /= 10;
	}
	if (minus == true)
		s += '-';
	s = ft_reverse(s);
	return (s);
}

/*
//REVIEW - valid_input

Return true(1) if success, else false(0)
input is invalid when:

1)	Is empty;
2)	Its size surpasses 1000;
3)	It has non printable characters.
*/
bool	valid_input(std::string s)
{
	int	i;

	if (s.empty() == true)
		return (std::cout << "\033[1;31mBad value\n\033[0m", false);
	if (s.size() >= 1000)
		return (std::cout << "\033[1;31mBad value\n\033[0m", false);
	i = 0;
	while (s[i])
	{
		if (std::isprint(s[i]) == false)
			return (std::cout << "\033[1;31mBad value\n\033[0m", false);
		++i;
	}
	return (true);
}

//	Returns:
//	0:	success
//	1:	string is invalid
//	2:	non digit char in s
bool	ft_atoi(std::string s, int *n)
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

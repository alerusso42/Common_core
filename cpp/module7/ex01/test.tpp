/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:08:12 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 18:20:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_TPP
# define TEST_TPP
# include "iter.hpp"
# include "lib/lib.hpp"

# define STRINGS "012", "345", "678", "901", ""

void	ft_toupper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
}

template	<typename T>
void		ft_tolower(T &c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
}

void	print_upper(const char c)
{
	if (c >= 'a' && c <= 'z')
		std::cout << (char)(c - ('a' - 'A'));
	else
		std::cout << (char)(c);
}

template	<typename T>
void		print_lower(const T c)
{
	if (c >= 'A' && c <= 'Z')
		std::cout << (T)(c + ('a' - 'A'));
	else
		std::cout << (T)(c);
}

void	ft_positive(int &n)
{
	if (n < 0)
		n *= -1;
}

template	<typename T>
void		ft_negative(T &n)
{
	if (n > 0)
		n *= -1;
}

void	print_positive(const int n)
{
	if (n < 0)
		std::cout << n * -1;
	else
		std::cout << n;
}

template	<typename T>
void		print_negative(const T n)
{
	if (n > 0)
		std::cout << n * -1;
	else
		std::cout << n;
}

void	reverse_string(std::string &s)
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
}

void	print_reverse(const std::string &s)
{
	int		i;

	i = s.length();
	while (i >= 0)
	{
		std::cout << s[i];
		i--;
	}
	std::cout << "|";
}

std::ostream	&operator<<(std::ostream &stream, int *array)
{
	for (int i = 0; i < ARR_LENGTH; i++)
		stream << array[i] << "|";;
	stream << "\n";
	return (stream);
}

std::ostream	&operator<<(std::ostream &stream, const int *array)
{
	for (int i = 0; i < ARR_LENGTH; i++)
		stream << array[i] << "|";;
	stream << "\n";
	return (stream);
}

std::ostream	&operator<<(std::ostream &stream, string *array)
{
	for (int i = 0; i < ARR_LENGTH; i++)
		stream << array[i] << "|";
	stream << "\n";
	return (stream);
}

std::ostream	&operator<<(std::ostream &stream, const string *array)
{
	for (int i = 0; i < ARR_LENGTH; i++)
		stream << array[i] << "|";;
	stream << "\n";
	return (stream);
}

#endif
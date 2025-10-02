/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:52:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 15:52:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"
# include "test.tpp"

//SECTION - ft_toupper, ft_tolower = 	non const
//			print_upper, print_lower = 	const
//			ft_tolower, print_lower =	template function
int main()
{
	char	s[ARR_LENGTH] = "minuscolo";

	std::cout << s << "\n";
	iter(s, ARR_LENGTH, ft_toupper);
	std::cout << s << "\n";
	iter(s, ARR_LENGTH, ft_tolower<char>);
	std::cout << s << "\n";
	iter(s, ARR_LENGTH, print_upper);
	iter(s, ARR_LENGTH, print_lower<char>);
	std::cout << std::endl;
	return (0);
}

//SECTION - ft_positive, ft_negative = 			non const
//			print_positive, print_negative = 	const
//			ft_negative, print_negative =		template function
int main2()
{
	int	s[ARR_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	std::cout << "original array:\n";
	std::cout << s;
	std::cout << "negative array:\n";
	iter(s, ARR_LENGTH, ft_negative<int>);
	std::cout << s;
	std::cout << "positive array:\n";
	iter(s, ARR_LENGTH, print_positive);
	std::cout << "\nnegative array:\n";
	iter(s, ARR_LENGTH, print_negative<int>);
	std::cout << "\npositive array:\n";
	iter(s, ARR_LENGTH, ft_positive);
	std::cout << std::endl;
	return (0);
}

//SECTION - using to_lower with numbers
int main3()
{
	int	s[ARR_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	std::cout << s;
	iter(s, ARR_LENGTH, ft_negative<int>);
	std::cout << s;
	iter(s, ARR_LENGTH, ft_tolower<int>);
	std::cout << s;
	iter(s, ARR_LENGTH, ft_positive);
	iter(s, ARR_LENGTH, print_lower<int>);
	std::cout << std::endl;
	return (0);
}

//SECTION - only const function
int main4()
{
	const int	s[ARR_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	std::cout << "original array:\n";
	std::cout << s;
	std::cout << "\nnegative array:\n";
	iter(s, ARR_LENGTH, print_negative<int>);
	std::cout << "\npositive array:\n";
	iter(s, ARR_LENGTH, print_positive);
	std::cout << std::endl;
	return (0);
}

//SECTION - only const function
int main5()
{
	const char	s[ARR_LENGTH] = "minuscolo";

	std::cout << "original array:\n";
	std::cout << s;
	std::cout << "\nnegative array:\n";
	iter(s, ARR_LENGTH, print_lower<char>);
	std::cout << "\npositive array:\n";
	iter(s, ARR_LENGTH, print_upper);
	std::cout << std::endl;
	return (0);
}

//SECTION - example with type string
int main6()
{
	std::string	 s[ARR_LENGTH] = {STRINGS};

	std::cout << "original matrix:\n";
	std::cout << s;
	std::cout << "\nreverted strings:\n";
	iter(s, ARR_LENGTH, reverse_string);
	std::cout << s;
	std::cout << "\nreverted again:\n";
	iter(s, ARR_LENGTH, print_reverse);
	std::cout << std::endl;
	return (0);
}

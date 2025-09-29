/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:30:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/29 22:30:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"


//SECTION - Success
int main() 
{
	std::vector<int>	arr(100000, 10);
	
	random_seed();
	std::generate(arr.begin(), arr.end(), std::rand);
	for_each(arr.begin(), arr.end(), print<int>);
	try
	{
		std::cout << "\033[32mSearch...\n\033[0m";
		std::cout << easyfind(arr, arr[3]);
		std::cout << "\033[32m\nSuccess.\033[0m";
	}
	catch(const Error& e)
	{
		e.print();
		std::cout << "\033[32mFailed.\033[0m";
	}
	std::cout << std::endl;
	return 0;
}

//SECTION - Failed
int main2() 
{
	std::vector<int>	arr(100000, 10);

	random_seed();
	std::generate(arr.begin(), arr.end(), std::rand);
	for_each(arr.begin(), arr.end(), print<int>);
	try
	{
		std::cout << "\033[32mSearch...\n\033[0m";
		std::cout << easyfind(arr, 42);
		std::cout << "\033[32m\nSuccess.\033[0m";
	}
	catch(const Error& e)
	{
		e.print();
		std::cout << "\033[32mFailed.\033[0m";
	}
	std::cout << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:26:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 18:26:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

# define STRINGS "012", "345", "678", "901", ""

//SECTION - Empty array
int main() 
{
	try
	{
		Array<int>	arr;
		arr[0] = 42;
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

//SECTION - size too big
int main2()
{
	try
	{
		Array<int>	arr(UINT_MAX / 2);
		arr[0] = 42;
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

//SECTION - std::string Array with argc
int main3(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "\033[31mArgv must not be empty.\033[0m" << std::endl;
		return (1);
	}
	try
	{
		Array<string>	arr(argc);
		for (int i = 1; i < argc; i++)
			arr[i - 1] = argv[i];
		arr.print();
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

//SECTION - std::string Array with macro
int main4()
{
	std::string	 strings[] = {STRINGS};
	try
	{
		Array<string>	arr(2);
		for (int i = 1; strings[i].empty() == false; i++)
			arr[i - 1] = strings[i];
		arr.print();
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

//SECTION - copy of an array
int main5()
{
	std::string	 strings[] = {STRINGS};
	try
	{
		Array<string>	arr(5);
		Array<string>	arr_copy(5);
		for (int i = 1; strings[i].empty() == false; i++)
			arr[i - 1] = strings[i];
		arr_copy = arr;
		arr_copy[0] = "Guarda mamma sono diverso";
		std::cout << "\033[32mPrint of the original:\n\033[0m";
		arr.print();
		std::cout << "\033[33mPrint of the copy:\n\033[0m";
		arr_copy.print();
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

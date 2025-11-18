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

void test1(const char *s);
void test2(const char *s);
void test3(const char *s);
void test4(const char *s);
void test5(const char *s);

int	main(int argc, char **av)
{
	int	n;
	int	curr = 1;

	if (argc >= 2)
		n = std::atoi(av[1]);
	else
		n = 42;
	if (n == curr++ || n == 42)
		test1("TEST 1:	Empty array\n");
	if (n == curr++ || n == 42)
		test2("TEST 2:	Size too big\n");
	if (n == curr++ || n == 42)
		test3("TEST 3:	std::string array KO\n");
	if (n == curr++ || n == 42)
		test4("TEST 4:	std::string array OK\n");
	if (n == curr++ || n == 42)
		test5("TEST 5:	Array copy\n");
}

//SECTION - Empty array
void test1(const char *s)
{
	std::cout << s;
	try
	{
		Array<int>	arr;
		arr[0] = 42;
	}
	catch(const Error &e)
	{
		e.print();
	}
}

//SECTION - size too big
void test2(const char *s)
{
	std::cout << s;
	try
	{
		Array<int>	arr(UINT_MAX / 2);
		arr[0] = 42;
	}
	catch(const Error &e)
	{
		e.print();
	}
}

//SECTION - std::string Array with macro
void test3(const char *s)
{
	std::cout << s;
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
}

//SECTION - std::string Array with macro
void test4(const char *s)
{
	std::cout << s;
	std::string	 strings[] = {STRINGS};
	try
	{
		Array<string>	arr(5);
		for (int i = 1; strings[i].empty() == false; i++)
			arr[i - 1] = strings[i];
		arr.print();
	}
	catch(const Error &e)
	{
		e.print();
	}
}

//SECTION - copy of an array
void test5(const char *s)
{
	std::cout << s;
	std::string	 strings[] = {STRINGS};
	try
	{
		Array<string>	arr(5);
		Array<string>	arr_copy(5);
		Array<string>	other_copy(arr);
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
}

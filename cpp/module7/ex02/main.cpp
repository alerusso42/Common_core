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

int main() 
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

//SECTION - string Array
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
			arr[i] = argv[i];
	}
	catch(const Error &e)
	{
		e.print();
	}
	return (0);
}

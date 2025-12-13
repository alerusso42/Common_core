/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 23:45:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/13 11:31:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "PmergeMe.hpp"

template <typename T>
void	fill_container(T &container, int argc, char *argv[])
{
	u_int64_t	i;
	int32_t		arg;
	std::string	buffer;

	arg = 1;
	while (arg < argc)
	{	
		buffer = argv[arg];
		i = -1;
		do
		{
			i += 1;
			if (valid_number(buffer.substr(i), false) == 0)
				container.push_back(std::atoi(buffer.substr(i).c_str()));
			buffer = buffer.substr(i);
			i = buffer.find(' ');
		}
		while (i != buffer.npos);
		++arg;
	}
}

/*
template <typename T>
void	parse_container(T &container, bool before)
{
	for (T::iterator j = container.begin(); j != container.end(); i++)
	{
		for (T::iterator j = container.begin(); j != container.end(); i++)
		{
			if (i != j && *i == *j)
				
		}
	}
	std::cout << std::endl;
}*/

template <typename T>
void	print_container(T &container, bool before)
{
	if (before)
		std::cout << "\033[32mBefore:\t\033[0m";
	else
		std::cout << "\033[33mAfter:\t\033[0m";
	for (u_int32_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	check_container_sorting(T &container)
{
	T	biggest(2);

	biggest[0] = container[0];
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i] < biggest[0])
		{
			std::cout << "\033[31mCRITICAL ERROR! CONTAINER IS NOT SORTED!!!";
			std::cout << "\033[0m\n" << "\033[32mBad position:\033[0m" << i;
			std::cout << "\n\033[32mValue:\033[0m" << container[i] << std::endl;
			throw Error(EX_SORT_FAILED);
		}
		else
		{
			biggest[0] = container[i];
		}
	}
}

template <typename T, typename F>
void	print_time(T &container, F &function, std::string container_name)
{
	struct timeval	clock;
	double			start;
	double			end;

	gettimeofday(&clock, NULL);
	start = clock.tv_usec + (clock.tv_sec / 10e6);
	function(container);
	gettimeofday(&clock, NULL);
	check_container_sorting(container);
	end = clock.tv_usec + (clock.tv_sec / 10e6);
	std::cout << "Time to process a range of ";
	std::cout << container.size();
	std::cout << " elements with " << container_name << " : ";
	std::cout << end - start << " us" << std::endl;
}

#endif
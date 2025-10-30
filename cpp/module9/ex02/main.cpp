/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:29:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/06 21:29:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	std::vector<int32_t>	vector;
	std::deque<int32_t>		deque;

	if (argc < 2 || valid_input(argv[1]) == false)
		return (print_error(ERROR_ARGV), 1);
	fill_container(vector, argc, argv);
	fill_container(deque, argc, argv);
	print_container(vector, true);
	sort(vector);
	print_container(vector, false);
	vector.erase(vector.begin(), vector.end());
	fill_container(vector, argc, argv);
	print_time(vector, sort<std::vector<int32_t> >, "std::vector");
	print_time(deque, sort<std::deque<int32_t> >, "std::deque");
	return (0);
}

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
	std::list<int32_t>		list;

	if (argc < 2 || valid_input(argv[1]) == false)
		return (print_error(ERROR_ARGV), 1);
	fill_container(vector, argc, argv);
	fill_container(list, argc, argv);
	print_container(vector, true);
	sort(vector);
	print_container(vector, false);
	print_time(vector, sort<std::vector<int32_t> >, "std::vector");
	print_time(list, sort_list<int32_t>, "std::list");
	return (0);
}

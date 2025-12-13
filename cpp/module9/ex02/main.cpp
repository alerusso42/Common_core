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

int main2(int argc, char *argv[])
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
	check_container_sorting(vector);
	vector.erase(vector.begin(), vector.end());
	fill_container(vector, argc, argv);
	print_time(vector, sort<std::vector<int32_t> >, "std::vector");
	print_time(deque, sort<std::deque<int32_t> >, "std::deque");
	return (0);
}

int	brutal_testing(int max_size)
{
	size_t					size = std::rand() % max_size;
	if (size == 0)
		size = 1;
	std::vector<int32_t>	vector(size);
	std::deque<int32_t>		deque(size);

	for (size_t i = 0; i < size; i++)
	{
		vector[i] = std::rand() * (std::rand() % 2 ? 1 : -1);
		deque[i] = vector[i];
	}
	print_container(vector, true);
	sort(vector);
	print_container(vector, false);
	check_container_sorting(vector);
	for (size_t i = 0; i < size; i++)
		vector[i] = deque[i];
	print_time(vector, sort<std::vector<int32_t> >, "std::vector");
	print_time(deque, sort<std::deque<int32_t> >, "std::deque");
	return (0);
}

int main()
{
	int	times = 100000;
	int	max_size = 1000;

	random_seed();
	while (times--)
		brutal_testing(max_size);
	return (0);
}

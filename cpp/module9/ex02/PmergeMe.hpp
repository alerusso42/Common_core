/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:30:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/11 14:47:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include "lib/lib.hpp"
# include <vector>
# include <deque>
# include <list>
# include "Pair.hpp"
# include <sys/time.h>
# include "Jacobsthal.hpp"

template <typename T>
void	sort(T &big);
template <typename T>
void	sort_list(std::list<T> &big);
template <typename T>
void	fill_container(T &container, int argc, char *argv[]);
template <typename T>
void	print_container(T &container, bool before);
template <typename T, typename F>
void	print_time(T &container, F &function, std::string container_name);

# include "PmergeMe.tpp"
//# include "PmergeMe_list.tpp"
# include "utils.tpp"

# define ERROR_ARGV "Please insert a list of integer to sort (as one argument)"

#endif
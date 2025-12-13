/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:30:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/13 10:20:46 by alerusso         ###   ########.fr       */
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
template <typename T>
void	check_container_sorting(T &container);
template <typename T, typename F>
void	print_time(T &container, F &function, std::string container_name);

# include "PmergeMe.tpp"
//# include "PmergeMe_list.tpp"
# include "utils.tpp"

# define ERROR_ARGV "Please insert a list of integer to sort (as one argument)"

#endif
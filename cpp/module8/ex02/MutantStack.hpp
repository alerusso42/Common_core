/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:50:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T>
{
private:

public:
	typedef typename C::iterator iterator;
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();

	const MutantStack& operator=(const MutantStack& other);
	iterator	begin();
	iterator	end();
};

# include "MutantStack.tpp"

#endif
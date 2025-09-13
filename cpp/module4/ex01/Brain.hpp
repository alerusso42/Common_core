/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:34:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/13 17:00:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include "header.hpp"

# define RAND_IDEAS "Pisa" "Livorno" "Mega_Rayquaza" "Gabibbo"
# define TOTAL_IDEAS 4

class Brain
{
private:
	enum data
	{
		IDEAS = 100,		
	};
protected:
	string	ideas[Brain::IDEAS + 1];
public:
	Brain();
	Brain(string s);
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
};

#endif
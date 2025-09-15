/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:34:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 08:58:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include "lib/lib.hpp"

# define RAND_IDEAS "Pisa", "Livorno", "Mega_Rayquaza", "Gabibbo"
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

	void	thinking(void) const;
};

#endif
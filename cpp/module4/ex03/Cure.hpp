/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "lib/lib.hpp"
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria
{
//private:
//	Cure	*_last_clone;
public:
//	canonic form:
	Cure();
	~Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	
	Cure	*clone() const;
	void	 use(ICharacter& target);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "lib/lib.hpp"
#include "ICharacter.hpp"

# define RAND_NAMES "Totti", "Bello_Figo", "Mega_Rayquaza", "Gabibbo"
# define TOTAL_NAMES 4

class Character : public ICharacter
{
private:
	enum e_character
	{
		INV_SIZE = 4,
	};
	std::string	 	name;
	AMateria	*inventory[INV_SIZE + 1];
	int			curr_item;
public:
//	canonic form:
	Character();
	Character(std::string s);
	~Character();
	Character(const Character &other);
	Character &operator=(const Character &other);

	std::string const &getName() const;

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
	bool	valid_slot(int idx);
};

/*
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;*/

#endif

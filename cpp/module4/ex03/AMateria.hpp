/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "lib/lib.hpp"

class ICharacter;

enum e_types
{
	ICE,
	CURE,
	NONE,
	TYPES_NUM,
};

class AMateria
{
private:
	int		type_val;
protected:
	AMateria();
	AMateria(const AMateria &other);

	std::string	 type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	void				setType(std::string const newtype);
	int					getIdx() const;
	virtual AMateria* 	clone() const = 0;
	virtual void 		use(ICharacter& target);
};

int	AMateria_type_finder(const std::string &s);

#endif

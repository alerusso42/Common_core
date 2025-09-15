/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "lib/lib.hpp"
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"

//typedef AMateria* (*Creator)(string const &);

class MateriaSource : public IMateriaSource
{
private:
	enum e_materia_source
	{
		MAT_NUM = 42,
	};
	AMateria	*all[MAT_NUM + 1];
	AMateria	*creator[TYPES_NUM + 1];
	int			curr_mat;
	void		resetMateria(void);
public:
//	canonic form:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);

	void		learnMateria(AMateria *obj);
	AMateria	*createMateria(string const &type);
};

#endif

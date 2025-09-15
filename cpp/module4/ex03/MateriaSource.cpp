/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->creator[0] = NULL;
	this->creator[1] = NULL;
	this->creator[2] = NULL;
	for (int i = 0; i < this->MAT_NUM; i++)
	{
		this->all[i] = NULL;
	}
	this->curr_mat = 0;
}

MateriaSource::~MateriaSource()
{
	resetMateria();
	for (int i = 0; i < TYPES_NUM; i++)
	{
		if (this->creator[i])
			delete (this->creator[i]);
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{ 
	for (int i = 0; i < TYPES_NUM; i++)
	{
		this->creator[i] = other.creator[i];
	}
	for (int i = 0; i < this->MAT_NUM; i++)
	{
		this->all[i] = other.all[i];
	}
	this->curr_mat = other.curr_mat;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other) 
		return (*this);
	for (int i = 0; i < TYPES_NUM; i++)
	{
		this->creator[i] = other.creator[i];
	}
	for (int i = 0; i < this->MAT_NUM; i++)
	{
		this->all[i] = other.all[i];
	}
	this->curr_mat = other.curr_mat;
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *obj)
{
	if (!obj)
		return ;
	if (this->creator[obj->getIdx()])
		delete this->creator[obj->getIdx()];
	this->creator[obj->getIdx()] = obj;
}

AMateria	*MateriaSource::createMateria(string const &type)
{
	int	idx;

	if (this->curr_mat == this->MAT_NUM)
	{
		this->resetMateria();
	}
	idx = AMateria_type_finder(type);
	if (this->creator[idx] == NULL)
		return (NULL);
	this->all[this->curr_mat] = this->creator[idx]->clone();
	return (this->all[this->curr_mat++]);
}

void	MateriaSource::resetMateria(void)
{
	for (int i = 0; i < this->MAT_NUM; i++)
	{
		if (this->all[i])
			delete (this->all[i]);
		this->all[i] = NULL;
	}
	this->curr_mat = 0;
}

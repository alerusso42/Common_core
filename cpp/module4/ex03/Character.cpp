/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::string	 names[] = {RAND_NAMES};

	for (int i = 0; i < INV_SIZE; i++)
		this->inventory[i] = NULL;
	this->inventory[INV_SIZE] = NULL;
	this->name = names[std::rand() % INV_SIZE];
	this->curr_item = 0;
}

Character::Character(std::string s)
{
	for (int i = 0; i < INV_SIZE; i++)
		this->inventory[i] = NULL;
	this->inventory[INV_SIZE] = NULL;
	this->name = s;
	this->curr_item = 0;
}

Character::~Character()
{}

Character::Character(const Character &other)
{ 
	for (int i = 0; i < INV_SIZE; i++)
		this->inventory[i] = other.inventory[i];
	this->inventory[INV_SIZE] = NULL;
	this->name = other.name;
	this->curr_item = other.curr_item;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other) 
	{
		for (int i = 0; i < INV_SIZE; i++)
			this->inventory[i] = other.inventory[i];
		this->name = other.name;
		this->curr_item = other.curr_item;
		this->inventory[INV_SIZE] = NULL;
	}
	return *this;
}

/*
public:

	void use(int idx, ICharacter& target);
};
*/

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < INV_SIZE && this->inventory[i])
	{
		++i;
	}
	if (i >= this->INV_SIZE)
		return (print_error("inventory is full"));
	this->inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (this->valid_slot(idx) == false)
		return ;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->valid_slot(idx) == false)
		return ;
	this->inventory[idx]->use(target);
	this->inventory[idx] = NULL;
}

bool	Character::valid_slot(int idx)
{
	if (idx >= this->INV_SIZE)
		return (print_error("slot too high"), false);
	else if (idx < 0)
		return (print_error("slot too low"), false);
	else if (this->inventory[idx] == NULL)
		return (print_error("slot is empty"), false);
	return (true);
}

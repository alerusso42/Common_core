/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:07:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 16:07:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("name")
{
	this->hit_points = HP;
	this->energy_points = EP;
	this->attack_damage = AD;
	std::cout << "\033[32m";
	std::cout << this->name << ":\tFragTrap constructor!" << std::endl;
	std::cout << "\033[0m";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = HP;
	this->energy_points = EP;
	this->attack_damage = AD;
	std::cout << "\033[32m";
	std::cout << this->name << ":\tFragTrap constructor!" << std::endl;
	std::cout << "\033[0m";
}

FragTrap::~FragTrap()
{
	std::cout << "\033[33m";
	std::cout << this->name << ":\tFragTrap destructor!" << std::endl;
	std::cout << "\033[33m";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other) 
	{
		this->name = other.name;
		this->attack_damage = other.attack_damage;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (is_ko())
		return ;
	std::cout << this->name << "\tHIGH FIVES GUYS!" << std::endl;
}

bool	FragTrap::is_ko(void)
{
	if (this->hit_points <= 0)
		return (this->death(), true);
	else if (this->energy_points <= 0)
		return (this->no_energy(), true);
	this->energy_points--;
	return (false);
}

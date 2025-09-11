/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:56:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 11:56:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guard_mode = false;
	std::cout << "\033[32m";
	std::cout << this->name << ":\tScavTrap constructor!" << std::endl;
	std::cout << "\033[0m";
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guard_mode = false;
	std::cout << "\033[32m";
	std::cout << this->name << ":\tScavTrap constructor!" << std::endl;
	std::cout << "\033[0m";
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[33m";
	std::cout << this->name << ":\tScavTrap destructor!" << std::endl;
	std::cout << "\033[33m";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->guard_mode = other.guard_mode;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other) 
	{
		this->name = other.name;
		this->attack_damage = other.attack_damage;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->guard_mode = other.guard_mode;
	}
	return *this;
}

void ScavTrap::guardGate()
{
	if (this->guard_mode)
	{
		std::cout << this->name << "\tis already in guardgate." << std::endl;
		return ;
	}
	std::cout << this->name << "\tENTERS GUARDGATE MODE!!!" << std::endl;
	this->guard_mode = true;
	this->name += "🚪";
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << this->name << " SCAV BOMB ON\t" << target << std::endl;
}

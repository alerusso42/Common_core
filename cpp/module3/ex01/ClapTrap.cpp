/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:17:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 09:17:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "name";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << this->name << " is born.." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	static int	n;

	this->name = name.append(ft_itoa(n));
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "\033[32m";
	std::cout << this->name << ":\tClapTrap constructor" << std::endl;
	std::cout << "\033[0m";
	n++;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[33m";
	std::cout << this->name << ":\tdestructor" << std::endl;
	std::cout << "\033[0m";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{ 
	this->attack_damage = other.attack_damage;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other) 
	{
		this->attack_damage = other.attack_damage;
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (is_ko())
		return ;
	std::cout << "attack():\t" << name << " attacks " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= amount;
	std::cout << "takeDamage():\t" << name << " took " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (is_ko())
		return ;
	this->hit_points += amount;
	std::cout << "beRepaired():\t" << name << " gains " << amount << std::endl;
}

void ClapTrap::death(void)
{
	std::cout << this->name << " IS DEAD.. why??" << std::endl;
}

void ClapTrap::no_energy(void)
{
	std::cout << this->name << " IS tired.. give him a break!" << std::endl;
}

bool	ClapTrap::is_ko(void)
{
	if (this->hit_points <= 0)
		return (this->death(), true);
	else if (this->energy_points <= 0)
		return (this->no_energy(), true);
	this->energy_points--;
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:46:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/09 11:45:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
	this->name = "name";
	ClapTrap::name.append("clap_name");
	this->hit_points = FragTrap::HP;
	this->energy_points = ScavTrap::EP;
	this->attack_damage = FragTrap::AD;
	std::cout << "\033[32m";
	std::cout << this->name << ":\tDiamondTrap constructor!" << std::endl;
	std::cout << "\033[0m";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	static int	n;

	this->name = name;
	this->name.append(ft_itoa(n));
	ClapTrap::name.append("clap_name");
	this->hit_points = FragTrap::HP;
	this->energy_points = ScavTrap::EP;
	this->attack_damage = FragTrap::AD;
	std::cout << "\033[32m";
	std::cout << this->name << ":\tDiamondTrap constructor!" << std::endl;
	std::cout << "\033[0m";
	n++;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[33m";
	std::cout << this->name << ":\tDiamondTrap destructor!" << std::endl;
	std::cout << "\033[0m";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(), FragTrap(), ScavTrap()
{
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
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

void 	DiamondTrap::whoAmI()
{
	if (is_ko())
		return ;
	std::cout << "Name:\t\t" << this->name;
	std::cout << "\nClapName:\t" << ClapTrap::name << std::endl;
}

void 		DiamondTrap::print_stats()
{
	this->whoAmI();
	std::cout << "Hit points:\t" << this->hit_points << std::endl;
	std::cout << "energy points:\t" << this->energy_points << std::endl;
	std::cout << "attack damage:\t" << ScavTrap::attack_damage << std::endl;
	std::cout << "They should start at: 100, 50, 30" << std::endl;
}

bool	DiamondTrap::is_ko(void)
{
	if (this->hit_points <= 0)
		return (this->death(), true);
	else if (this->energy_points <= 0)
		return (this->no_energy(), true);
	this->energy_points--;
	return (false);
}

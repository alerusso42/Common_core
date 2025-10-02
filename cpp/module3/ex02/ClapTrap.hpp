/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:17:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 09:17:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include "header.hpp"
# define RAND_NAMES "Giovannino", "Giovanna", "Giovannone"

//	root class
class ClapTrap
{
protected:
	void 	death(void);
	void 	no_energy(void);
	std::string	 name;
	int		hit_points;
	int		energy_points;
	int		attack_damage;
	int	n;
public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	std::string	 &getname();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

# include "ScavTrap.hpp"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:56:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 11:56:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

//	takes from ClapTrap
class ScavTrap : virtual public ClapTrap
{
private:
	bool	guard_mode;
protected:
	enum e_stats
	{
		HP = 100,
		EP = 50,
		AD = 20,
	};
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	void guardGate();
	void attack(const std::string& target);
};

# include "FragTrap.hpp"

#endif

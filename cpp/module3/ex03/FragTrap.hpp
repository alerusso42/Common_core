/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:07:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/11 16:07:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	enum e_stats
	{
		HP = 100,
		EP = 100,
		AD = 30,
	};
public:
	FragTrap();
	FragTrap(std::string name);
	virtual	~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	void highFivesGuys(void);
	virtual bool	is_ko(void);
};

# include "DiamondTrap.hpp"

#endif

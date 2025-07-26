/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/26 10:46:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include "lib/lib.hpp"

class Weapon
{
public:
	Weapon(string type, int damage);
	Weapon();
	~Weapon();
	const string	*get_type();
	void			*set_type(string new_type);
private:
	string	type;
	int		damage;
};

#endif
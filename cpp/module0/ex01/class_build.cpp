/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_build.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:49:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/09 15:51:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

PhoneBook::~PhoneBook(void)
{
	return ;
}

PhoneBook::PhoneBook(Contact contacts[PHONE_SIZE + 1])
{
	int	i;

	i = 0;
	while (i != PHONE_SIZE + 1)
	{
		contacts[i] = (Contact){0};
		++i;
	}
}

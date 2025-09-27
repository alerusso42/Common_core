/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 16:10:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	return ((void)other, *this);
}

uintptr_t 	Serializer::serialize(Data* ptr)
{
	return (*(uintptr_t *)(void *)ptr);
	//return (*reinterpret_cast<uintptr_t *>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw)
{
	Data		*data = new(Data);
	uintptr_t	*val;

	if (!data)
		return (NULL);
	val = (uintptr_t *)(void *)data;
	//val = reinterpret_cast<uintptr_t *>(data);
	*val = raw;
	return (data);
}

Data::Data()
{}

Data::~Data()
{}

std::ostream	&operator<<(std::ostream &stream, Data &data)
{
	stream << (*(uintptr_t *)(void *)&data);
	return (stream);
}

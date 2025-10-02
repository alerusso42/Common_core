/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 16:10:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "lib/lib.hpp"

typedef u_int32_t	uintptr_t;

typedef struct Data
{
	private:
		uintptr_t	password;
		void		*foto_piedi_gabibbo;
	public:
		std::string	 questa_struct_non_contiene_dati_confidenziali;
		Data();
		~Data();
}	Data;

class Serializer
{
private:
	Serializer();
	~Serializer();
public:
//	canonic form:
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);

	static uintptr_t 	serialize(Data* ptr);
	static Data* 		deserialize(uintptr_t raw);
};

std::ostream	&operator<<(std::ostream &stream, Data &data);

#endif

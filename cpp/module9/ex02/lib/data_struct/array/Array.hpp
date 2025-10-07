/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:26:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 18:26:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include "../../lib.hpp"

template	<typename T>
class	 	Array
{
private:
	T			*_data;
	u_int32_t	_size;
	enum	e_Array
	{
		ARRAY_MAXSIZE = (u_int32_t)1e8,
	};
public:
//	canonic form:
	Array<T>(void);
	Array<T>(u_int32_t size);
	~Array();
	Array(const Array &other);
	Array &operator=(const Array &other);

	u_int32_t	size(void) const;
	const T		*get_data(void) const;
	T			&operator[](u_int32_t index);
	void		print(void) const;
};

# include "Array.tpp"

#endif

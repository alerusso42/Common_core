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
# include "lib/lib.hpp"

template	<typename T>
class	 	Array
{
private:
	T		*_data;
	int		_size;
	enum	e_Array
	{
		ARRAY_MAXSIZE = (int)1e8,
	};
public:
//	canonic form:
	Array<T>(void);
	Array<T>(u_int32_t size);
	~Array();
	Array(const Array &other);
	Array &operator=(const Array &other);

	int		size(void) const;
	const T	*get_data(void) const;
	T		&operator[](int index);
};

# include "Array.tpp"

#endif

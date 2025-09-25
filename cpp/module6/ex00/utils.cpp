/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:27:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/25 09:41:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

static bool	ft_strchr(string s, string charset);

int		find_type(string s)
{
	int	n1;
	int	n2;

	if (ft_strchr(s, ".f") == false)
	{
		if (std::atoi(s.c_str()) <= 255)
			return (T_CHAR);
		return (T_INT);
	}
	if (std::atof(s.c_str()) < 3.40e+38)
		return (T_FLOAT);
	return (T_DOUBLE);
}

static bool	ft_strchr(string s, string charset)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[j])
		{
			if (s[i] == charset[j])
				return (true);
			++j;
		}
		i++;
	}
	return (false);
}
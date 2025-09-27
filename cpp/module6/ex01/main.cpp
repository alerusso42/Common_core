/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 16:10:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main() 
{
	Data		data_original;
	Data		*data_derived;
	uintptr_t	val_original;
	uintptr_t	val_derived;

	tty_clear();
	data_original = *Serializer::deserialize(1);
	val_original = 2;
	std::cout << "\033[32m" << "data_original:\t\t" << data_original << "\n";
	std::cout << "\033[33m" << "val_original:\t\t" << val_original << "\n";
	data_derived = Serializer::deserialize(val_original);
	val_derived = Serializer::serialize(&data_original);
	std::cout << "\033[32m" << "val_derived from data:\t" << val_derived << "\n";
	std::cout << "\033[33m" << "data_derived from val:\t" << *data_derived << "\n";
	std::cout << "\033[0m";
	std::cout << std::flush;
	return (0);
}

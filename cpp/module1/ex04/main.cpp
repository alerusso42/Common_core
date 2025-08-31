/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/31 22:54:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

/*

	source: https://www.cs.uic.edu/~jbell/CourseNotes/CPlus/FileIO.html

					ios_base	(flag, robe interne classe)
						|
						|
						ios		(gestione buffer)
						|
						|
					iostream	(input, output)
						|
						|
				_____________________
				|					|
			istream				ostream
				|					|
				|					|
(INPUT FILE) ifstream			ofstream (OUTPUT FILE)
				|					|
				|					|
				-------fstream-------
				(input + output file)
				
1	
ofstream O_WRONLY

This data type represents the output file stream 
and is used to create files and to write 
information to files.

2	
ifstream O_RDONLY

This data type represents the input file stream 
and is used to read information from files.

3	
fstream O_RDWR

This data type represents the file stream generally, 
and has the capabilities of both ofstream and 
ifstream which means it can create files, 
write information to files, and read information 
from files.
std::ios::in → lettura

std::ios::out → scrittura

std::ios::app → append

std::ios::trunc → tronca a zero

std::ios::binary → modalità binaria
*/

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (std::cout << USAGE, 1);
	return (sed(argv[1], argv[2], argv[3]));
}

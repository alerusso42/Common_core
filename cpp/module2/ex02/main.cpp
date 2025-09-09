/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:51:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/02 16:51:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"


/*	NOTES (written in italian)
	cosa succede a un int
	int: 	3 	(BIN: 0000 0011)
	float:	3.25(BIN: 0000 0011 0100)*


*float reale:		3 in bit  +		0.25 in bit
					2^1 | 2^0 | 2^-1(0.5) | 2^-2(0.25)
					 1		1 .		0			1
					prendiamo la parte piu significativa e shiftiamo:
					 2^1 | 2^0 | 2^-1(0.5) | 2^-2(0.25) | 2^-3(0.125)
					 0		1 .		1			0			1
					 
					 1.101 e il bit normalizzato, da mettere nella mantissa.
					 si ignora la parte intera, sottointeso sia a 1.
					 segno: 	+	(0)
					 esponente: 128*(10000010)
					 mantissa:	101	(10100000000000000000000)
					 float:		3.25(01000001010100000000000000000000)

*l'esponente e 128 perche positivo (2 + (255 / 2))
					 
//float to int: (−1)segno×1.mantissa×2esponente−127

	1)	shiftiamo il numero di frac_bits posizioni, per fare posto alla parte
		decimale;
		int: 3 (BIN: 0001 1000)
	2)	
*/
/*
int	main( void ) 
{
	Fixed	a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}*/

/*
	6.375

		2^2	| 2^1 | 2^0 | 2^-1(0.5) | 2^-2(0.25) |	2^-3(0.125)
		 1		1	0		0			1				1

		 bit int:		110.011
		 normalizzato:	1.10011	* 2^2

		1.10011 e il bit normalizzato, da mettere nella mantissa.
		si ignora la parte intera, sottointeso sia a 1.
			segno: 		+		(0)
			esponente: 	129 	(10000011)
			mantissa:	10011	(10011000000000000000000)
			float:		6.375	(01000001110011000000000000000000)
*/
/*
	01000001110011000000000000000000 (6.375) in fixed point

	ritorno in int: (−1)segno×1.mantissa×2esponente−127	
					1 	*	1 *	10011 * (2 << (129 - 127))
					1	*	1.10011 * 4
	bit int:		110.011
	
					110.011 * (1 << frac_bits(8)) = 110011 (51)

	arrotondamento:	110011 + 0.1 OPPURE - 0.1 se fosse negativo.
*/

/*
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/

#include <iostream>
int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:34:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/26 23:51:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

//REVIEW - 	proportion
/*
	(30, 60, X, 100) gives back 50
	allows to make regular proportion
*/
double	proportion(double a, double b, double c, double d)
{
	double	prod;
	double	div;

	if (a == X)
		prod = b * c;
	if (a == X)
		div = d;
	else if (b == X)
	{
		prod = a * d;
		div = c;
	}
	else if (c == X)
	{
		prod = a * d;
		div = b;
	}
	else if (d == X)
	{
		prod = b * c;
		div = a;
	}
	else
		return (0);
	return (safe_division(prod, div));
}

//REVIEW - 	safe_division
/*
	Divides two number.
	If floating exception (dividend == 0), returns 0.
*/
double	safe_division(double divisor, double dividend)
{
	if (dividend == 0)
		return (0);
	return (divisor / dividend);
}

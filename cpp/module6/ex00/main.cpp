/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:35:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 21:35:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

/*
//SECTION - Explicit vs Implicit cast
	double b = 0.54;
Explicit cast: int a = (int) b
Implicit cast int a = b

//SECTION - Reinterpretation (identity) cast
float	a = 420.042f;

void	*b = &a;		// implicit reinterpretation cast
void	*c = (void *)&a;// explicit reinterpretation cast

void	*d = &a;		// implicit promotion
void	*e = d;			// implicit demotion
void	*f = (int *)d;	// Explicit demotion: best practice

RESULT: float may be read as an int (using same bit notation).

//SECTION - Type qualifier cast
you can remove const by doing:

int	const 	b	= 42;
int			*c = (int *)&b;
*c = 21;
(undefined behaviour)

//SECTION - Upcast, Downcast
	class Parent	{};
	class Child1: public Parent	{};
	class Child2: public Parent	{};

	Child1	a;

	Parent	*b = &a;			//implicit reinterpretation cast
	Parent	*c = (Parent *)&a;	//explicit reinterpretation cast
	
	Parent	*d = &a;			//implicit upcast: ok			
	Child1	*e = d;				//implicit downcast: ERROR
	Child2	*f = (Child2 *)d;	//explicit downcast: ok
(void)a, (void)b, (void)c, (void)d, (void)e, (void)f;
*/

int main() 
{

}

#include "../h.h"

//REVIEW - 	random
/*
	Random number generator.
	Uses gettimeofday with microseconds.
	Good for single assignment, bad for multiple assignment in an array.
*/
int	_random(int size)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_usec % size);
}

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

//REVIEW - 	elapsed_time
/*
	Returns time passed, in microseconds, between now and start time.
	Start time is a struct timeval already set with gettimeofday.
*/
long	elapsed_time(t_time start)
{
	struct timeval	tv;
	long			diff;

	gettimeofday(&tv, NULL);
	diff = (tv.tv_sec - start.tv_sec) * 1000000
		 + (tv.tv_usec - start.tv_usec);
	return (diff);
}

int	random_color(void)
{
	int	r;
	int	g;
	int	b;

	r = _random(256) * 16e4;
	g = _random(256) * 16e2;
	b = _random(256) * 16e0;
	return (r + g + b);
}

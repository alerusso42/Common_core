#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t add(int32_t a, int32_t b);
int32_t minus(int32_t a, int32_t b);
int32_t _div(int32_t a, int32_t b);
int32_t _pow(int32_t a, int32_t b);
int32_t bigg(int32_t a, int32_t b);
int32_t radix(int32_t a, int32_t b);

int main(int ac, char **av)
{
	int32_t a;
	int32_t b;

	if (ac != 3)
		return (printf("I need two numbers.\n"));
	a = atoi(av[1]);
	b = atoi(av[2]);
	printf("%d and %d:\t%d\n", a, b, radix(a, b));
	return (0);
}

int32_t add(int32_t a, int32_t b)
{   
	if (a+b)
		return (a+b);
	else
		return (0);
}

int32_t minus(int32_t a, int32_t b)
{
	return (a-b);
}

int32_t _div(int32_t a, int32_t b)
{if (b==0)
	return 153;
else
	return (a / b);

}

int32_t _pow(int32_t a, int32_t b)
{
	int32_t	a1 = a;
	int32_t c = 1;
	while (c < b)
	 
{a1 = a1+a;

c = c+1 ;
}
	return a1;
}

int32_t bigg(int32_t a, int32_t b)
{
if (a<b)
	return a;
else 
 return b;
}

int32_t radix(int32_t a, int32_t b)
{
	(void)b;
	int a1 = 0;

	if (a1 * a1 == a)
		return a1;
	while (a1 * a1 < a)
		a1++;
	a = a1 * a1;
	return a1;
}

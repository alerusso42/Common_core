#include <stdio.h>
#include <math.h>

double magnitude(double re, double im);

int main() {
    int a = 3565;
    int		b;

	b = a << 8;
	a = b >> 8;
	printf("%d\t%d\n", b, a);
    return 0;
}

// double magnitude(double re, double im)
// {
//     double r;
 
//     re = fabs(re);
//     im = fabs(im);
//     if (re > im) {
//         r = im/re;
//         return re*sqrt(1.0+r*r);
//     }
//     if (im == 0.0)
//         return 0.0;
//     r = re/im;
//     return im*sqrt(1.0+r*r);
// }

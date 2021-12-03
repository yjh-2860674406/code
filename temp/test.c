#include <stdio.h>
#include <stdlib.h>

#define g 9.788
#define L 77.2
#define pai 3.14
#define d (0.156+0.079)
#define k (1.85/1800)


int main () {
    float res = (4*g*L)/(k*pai*d*d);
    printf("%f\n", res);
}
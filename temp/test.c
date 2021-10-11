#include <stdio.h>

int main () {
    float x = 0; float y = 0; float z = 0;
    while (1) {
        scanf("%f", &x); getchar();
        printf("%.3f\n", 1/(x*x));
    }
    
}
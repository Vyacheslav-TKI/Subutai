#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x = 2.2f, y = 9.2f, z = 10.2f;
    double a = log(z+x*x)+sin(x/y)*sin(x/y), b = exp(-1*z)*((x+sqrt(x+z))/(x-sqrt(abs(x-y))));

    printf("A equals:  %.2f\n", a);
    printf("B equals: %.5f\n", b);
    return 0;
}

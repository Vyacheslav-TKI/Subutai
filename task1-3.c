#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float k, x, res;
    printf("Insert the k value first, then the x value, all values is number\n");
    scanf("%f", &k);
    scanf("%f", &x);
    if (k >= 0.0 && x >= 0.0){
        res = (k*x*x)/2;
        printf("Potential energy equals: %f\n", res);
    }
    else {
        printf("Insert non-negative numbers\n");
    }
}
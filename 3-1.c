#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x = 0.5f, y;
    while(x < 1.05){
        y = x + cos(powf(x, 0.52)+2);
        printf("y: %f, x: %.2f\n", y, x);
        x = x + 0.05;
    }
}
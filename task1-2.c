#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float i, j, sr_ar, sr_geo;

    printf("In the next strings insert just non-negative or just negative numbers\n");
    scanf("%f", &i);
    scanf("%f", &j);

    if((i > 0.0 && j > 0.0) || (i < 0.0 && j < 0.0)) {
        sr_ar = (i*i*i+j*j*j)/2;
        sr_geo = sqrt(i*j);
        system("pause");
        printf("The arithmetic mean of cubes of numbers is equal to: %.2f\n", sr_ar);
        printf("The geometric mean of the numbers is: %.2f\n", sr_geo);
    } else {
        printf("Insert just non-negative or just negative numbers\n");
    }
    
    return 0;

}
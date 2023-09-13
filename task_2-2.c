#include <stdio.h>
#include <math.h>

int main(){
    float a = 0.3f;
    float x;
    float y;
    printf("Enter value of x\n");
    scanf("%f", &x);

    if(a*x < 1){
        y = a * sin((x*x+1)/10);
        printf("The value of y equals: %f", y);
    }
    else if(a*x >= 1){
        y = a * cos((x-1)/10);
        printf("The value of y equals: %f", y);
    }
    return 0;
}
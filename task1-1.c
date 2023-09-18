#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 *  @brief Возвращает результат переменной а
 *  @param x, y, z Являются заданными константами
*/
double aCounter(double x, double y, double z);
/**
 *  @brief Возвращает результат переменной b
 *  @param x, y, z Являются заданными константами
*/
double bCounter(double x, double y, double z);

int main(){
    float x = 2.2f, y = 9.2f, z = 10.2f;
    double a, b;
    a = aCounter(x, y, z);
    b = bCounter(x, y, z);

    printf("x equals: %.1f\n", x);
    printf("y equals: %.1f\n", y);
    printf("z equals: %.1f\n", z);

    printf("A equals:  %.2f\n", a);
    printf("B equals: %.5f\n", b);
    return 0;
}

double aCounter(double x, double y, double z){
    double a = log(z + x * x) + sin(x / y) * sin(x / y);
    return a;
}

double bCounter(double x, double y, double z){
    double numerator, denominator;
    numerator = x + sqrt(x + z);
    denominator = x - sqrt(abs(x - y));
    return exp(-1 * z) * (numerator / denominator);
}

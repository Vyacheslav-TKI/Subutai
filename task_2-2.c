#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Функция вычисляет первое(верхнее уравнение)
 * @param a Заданная константа
 * @param x Заданная пользователем переменная
*/
double upper_equation(double a, double x);

/**
 * @brief Функция вычисляет второе(нижнее) уравнение
 * @param a Заданная константа
 * @param x Заданная пользователем переменная
*/
double lower_equation(double a, double x);

int main(){
    double a = 0.3f;
    double x;
    double y;
    double result;
    puts("Enter value of x\n");
    if(scanf("%f", &x) != 1){
        puts("Please insert a valid value\n");
        abort();}

    if(a*x < 1){
        result = upper_equation(a, x);
        printf("X equals: %lf", result);
    }
    else if(a*x >= 1){
        result = lower_equation(a, x);
        printf("X equals: %lf", result);
    }
    return 0;
}

double upper_equation(double a, double x){
    return a * sin((x*x+1)/10);
}

double lower_equation(double a, double x){
    return a * cos((x-1)/10);
}
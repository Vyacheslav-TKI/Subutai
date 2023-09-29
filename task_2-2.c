#include <stdio.h>
#include <math.h>

/**
 * @brief Функция вычисляет первое(верхнее уравнение)
 * @param a Заданная константа
 * @param x Заданная пользователем переменная
*/
double first_equation(double a, double x);

/**
 * @brief Функция вычисляет второе(нижнее) уравнение
 * @param a Заданная константа
 * @param x Заданная пользователем переменная
*/
double second_equation(double a, double x);

int main(){
    double a = 0.3f;
    double x;
    double y;
    puts("Enter value of x\n");
    scanf("%f", &x);

    if(a*x < 1){
        first_equation(a, x);
    }
    else if(a*x >= 1){
        second_equation(a, x);
    }
    return 0;
}

double first_equation(double a, double x){
    double y = a * sin((x*x+1)/10);
    printf("The value of y equals: %f", y);
}

double second_equation(double a, double x){
    double y = a * cos((x-1)/10);
    printf("The value of y equals: %f", y);
}
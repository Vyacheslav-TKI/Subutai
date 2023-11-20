#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

/**
 * @brief Проверяет введенное значение как цифру
 * @return Веденная переменная
*/
double check_number();

/**
 * @brief Вычисляет результат заданной функции
 * @param x аргумент функции
 * @return atan(x) значение функции
*/
double result_of_function(double x);

/**
 * @brief Вычисляет сумму ряда с заданной точностью
 * @param x переменная ряда
 * @param e точность вычисления
 * @return result сумма ряда
*/
double summation_of_series(double x, double e);

/**
 * @brief точка входа в программу
 * @return 0 программа исправна
*/
int main(){
    double e = pow(40, -5);

    puts("Insert a start value\n");
    double x_start = check_number();
    puts("Insert a stop value\n");
    double x_stop = check_number();
    puts("Insert a step number\n");
    double x_step = check_number();

    while (x_start < x_stop + x_step){
        printf("X: %lf       Y: %lf     Summ(x): %lf\n",  x_start, result_of_function(x_start), summation_of_series(x_start, e));
        x_start += x_step;
    }
    return 0;
}

double check_number(){
    double x;
    if (scanf("%lf", &x) != 1)
    {
        puts("Insert valid value!\n");
        abort();
    }
    return x;
}

double result_of_function(double x){
    return atan(x);
}

double summation_of_series(double x, double e){
    double r = 0.0f;
    double result = x, x_past = x;
    while (x_past + DBL_EPSILON > e + DBL_EPSILON){
        result += x_past * (-1 * ((pow(x, 2)) * (2 * r + 1) / (2 * r + 3)));
        x_past *= -1 * ((pow(x, 2)) * (2 * r + 1) / (2 * r + 3));
        r += 1;
    }
    return result;
}

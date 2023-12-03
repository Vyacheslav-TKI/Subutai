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
 * @brief Проверяет значения на правильность
 * @param x_start начальное значение
 * @param x_stop конечное значение
 * @param x_step значение шага
 * @return true переменные правильно введены
 */
bool check_arguments(double x_start, double x_stop, double x_step);

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
double summation_of_series(double x,  const double e);

/**
 * @brief точка входа в программу
 * @return 0 программа исправна
*/
int main(){
    const double e = pow(40, -5);

    puts("Insert a start value\n");
    double x_start = check_number();
    puts("Insert a stop value\n");
    double x_stop = check_number();
    puts("Insert a step number\n");
    double x_step = check_number();
    
    check_arguments(x_start, x_stop, x_step);

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

double summation_of_series(double x, const double e)
{
    double r = 0.0f;
    double result = x, last_term = x;
    while (result_of_function(x) - last_term - e > DBL_EPSILON)
    {
        last_term *= -1 * ((pow(x, 2)) * (2 * r + 1) / (2 * r + 3));  
        result += last_term;
        r++;
    }
    return result;
}

bool check_arguments(double x_start, double x_stop, double x_step)
{
    if (x_stop - x_start < DBL_EPSILON)
    {
        if (x_step > -DBL_EPSILON)
        {
            puts("Inserted a wrong arguments!");
            abort();
        }
    }
    else if (x_stop - x_start > -DBL_EPSILON)
    {
        if (x_step < DBL_EPSILON)
        {
            puts("Inserted a wrong arguments!");
            abort();
        }
    }
    return true;
}

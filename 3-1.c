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
 * @brief Проверяет на определенность функции при введенном аргументе
 * @param x Введенный аргумент
 * @return false Функция не определена
 * @return true Функция определена
*/
bool check_function(double x);

/**
 * @brief Проверяет значения на правильность
 * @param x_start начальное значение
 * @param x_stop конечное значение
 * @param x_step значение шага
 * @return true переменные правильно введены
 */
bool check_arguments(double x_start, double x_stop, double x_step);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
*/
int main(){
    puts("Insert a start value\n");
    double x_start = check_number();
    puts("Insert a stop value\n");
    double x_stop = check_number();
    puts("Insert a step number\n");
    double x_step = check_number();

    check_arguments(x_start, x_stop, x_step);
    
    while (x_start <= x_stop)
    {
        if (!check_function(x_start))
        {
            printf("X: %.2lf      Y: Function not defined\n", x_start);
        }
        else
        {
            double y = x_start + cos(powf(x_start, 0.52)+2);
            printf("X: %.2lf      Y: %lf\n", x_start, y);
        }
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

bool check_function(double x){
    if ((x + cos(powf(x, 0.52)+2) + DBL_EPSILON) < -0.57 + DBL_EPSILON || x < DBL_EPSILON)
    {
        return false;
    }
    return true;
}

bool check_arguments(double x_start, double x_stop, double x_step){
    if (x_start - x_stop > -DBL_EPSILON && x_step > -DBL_EPSILON)
    {
        puts("Start value is bigger than stop value!\n");
        abort();
    }
    return true;
}

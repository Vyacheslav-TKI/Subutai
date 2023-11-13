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
    
    while (x_start < x_stop + x_step)
    {
        if (!check_function(x_start))
        {
            puts("Function not defined\n");
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * @brief Функция проверяет введеный символ на число
 * @return x непосредственно число
 */
int check_number_int();

/**
 * @brief Функция проверяет введеный символ на число
 * @return x непосредственно число
 */
double check_number_float();

/**
 * @brief Функция вычисляет сумму членов заданного ряда
 * @param k Указатель, до какого числа последовательности необходимо подсчитать
 * @return result возвращает сумму до k-ого элемента
*/
double sum_of_sequence(int k);

/**
 * @brief Функция вычисляет сумму членов заданного ряда, не меньших заданного числа
 * @param e Заданное число
 * @return result возвращает сумму, элементы которых не меньше параметра e
*/
double verified_sum_of_series(double e);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправно завершилась
 * @return 1 Программа завершилась с ошибкой
*/
int main(){
    puts("Enter a trailing element pointer\n");
    int n = check_number_int();
    puts("Enter a number\n");
    double e = check_number_float();

    printf("Sum of sequence untill %d-th element equals: %lf\n", n, sum_of_sequence(n));
    printf("Sum of sequence not less than a number %lf equals: %lf\n", e, verified_sum_of_series(e));

    return 0;
}


double sum_of_sequence(int k){
    double result = 8.0f;
    double last_elem = 8.0f;
    for(int r = 1; r < k; r++)
    {
        result += last_elem * (pow(r+2, 3) / pow(r+1, 4));
        last_elem *= (pow(r+2, 3) / pow(r+1, 4));
    }
    return result;
}

double verified_sum_of_series(double e){
    double result = 8.0f;
    double last_elem = 8.0f; 
    int r = 1;
    while(last_elem >= e + DBL_EPSILON)
    {
        result += last_elem*(pow(r+2, 3) / pow(r+1, 4));
        r++;
        last_elem *= (pow(r+2, 3) / pow(r+1, 4));
    }
    return result;
}

double check_number_float(){
    double x;
    if(scanf("%lf", &x) != 1)
    {
        puts("Please, insert a valid value!\n");
        abort();
    }
    return x;
}

int check_number_int(){
    int x;
    if(scanf("%d", &x) != 1)
    {
        puts("Please, insert a valid value!\n");
        abort();
    }
    return x;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Функция рассчитывает факториал числа
 * @param n Введенное число 
*/
int factorial(int n);

/**
 * @brief Функция вычисляет сумму членов заданного ряда
 * @param k Указатель, до какого числа последовательности необходимо подсчитать
*/
double sum_of_sequence(int k);

/**
 * @brief Функция вычисляет сумму членов заданного ряда, не меньших заданного числа
 * @param e Заданное число
*/
double verified_sum_of_series(double e);

int main(){
    int n;
    double e;

    puts("Enter a trailing element pointer\n");
    if (scanf("%d", &n) != 1){
        puts("Please insert a valid value!\n");
        abort();
    }

    puts("Enter a number\n");
    if (scanf("%lf", &e) != 1){
        puts("Please insert a valid value!\n");
        abort();
    }

    printf("Sum of sequence untill %d-th element equals: %lf\n", n, sum_of_sequence(n));
    printf("Sum of sequence not less than a number %lf equals: %lf\n", e, verified_sum_of_series(e));

    return 0;
}

int factorial(int n){
    int r;
    for (r = 1; n > 1; r *= (n--))
        ;
    return r;
}

double sum_of_sequence(int k){
    double result = 0.0f;
    for(int r = 1; r < k+1; r++){
        result = result + (pow(r+1, 3)/factorial(r));
    }
    return result;
}

double verified_sum_of_series(double e){
    double result = 0.0f;
    int r = 1;
    while(pow(r+1, 3)/factorial(r) >= e){
        result += pow(r+1, 3)/factorial(r);
        r++;
    }
    return result;
}
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Функция выделяет число сотен из введенного числа
 * @param number введенное число
*/
int number_of_hundreds(int number);

/**
 * @brief Функция выделяет число десятков из введенного числа
 * @param number введенное число
*/
int tens_number(int number);

/**
 * @brief Функция выделяет число единиц из введенного числа
 * @param number введенное число
*/
int number_of_units(int number);

/**
 * @brief Функция вычисляет количество подходящих чисел, где сумма чисел равна а, а заканчивается числом b
 * @param a сумма цифр
 * @param b последняя цифра числа
*/
int suitable_digits(int a, int b);

/**
 * @brief функция получает и проверяет целочисленное число
 * @return number введенное число
 */
int get_int();

/**
 * @brief точка входа в программу
 * @return 0 программа исправна
 */
int main()
{
    int a = get_int();
    int b = get_int();

    printf("Number of suitable digits: %d\n", suitable_digits(a, b));
}

int number_of_hundreds(int number)
{
    return (int)number / 100;
}

int tens_number(int number)
{
    return ((int)number / 10) % 10;
}

int number_of_units(int number)
{
    return number % 10;
}

int suitable_digits(int a, int b)
{
    int counter = 0;
    for(int n = 100; n < 1000; n++)
    {
        if (number_of_hundreds(n) + tens_number(n)  == a - b && number_of_units(n) == b)
        {
            counter++;
        }
    }
    return counter;
}

int get_int()
{
    int number;
    if (scanf("%d", &number) != 1)
    {
        puts("Inserted a invalid value!");
        abort();
    }
}
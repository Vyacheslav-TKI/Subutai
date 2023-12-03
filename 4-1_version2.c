#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @return целочисленная цифра
*/
int get_int();

/**
 * @brief Функция присваивает переменной целочисленное значение и проверяет его на положителность
 * @return number положительное число
*/
size_t get_size_t();

/**
 * @brief структура хранит константы, указывающие выбор пользователя заполнить массив
*/
enum Choices
{
    user_choice = 1,
    random_choice = 2,
};

/**
 * @brief Функция выделяет память под массив
 * @param length длина массива
 * @return array указатель на пустой массив
*/
int* get_mem_array(const int length);

/**
 * @brief Функция заполняет массив, элементы вводит пользователь
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void user_array(int* const array, const size_t length);

/**
 * @brief Функция заполняет массив рандомными числами в диапазоне [-100:200]
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void random_array(int* const array, const size_t length);

/**
 * @brief Находит сумму четных элементов, значения которых больше заданного числа.
 * @param array указатель на массив
 * @param length размерность массива
 * @param number Заданное число
 * @return result результат
*/
int first_task(int* const array, size_t length, const int number);

/**
 * @brief Умножает все четные положительные элементы на последний элемент массива.
 * @param array указатель на массив
 * @param length размерность массива
 * @return result результат
*/
int second_task(int* const array, size_t length);

/**
 * @brief Находит номер первой пары соседних элементов с разными знаками.
 * @param array указатель на массив
 * @param length размерность массива
 * @return result результат
*/
int third_task(int* const array, const int length);

/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
*/
void free_array(int* array);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
 * @return 1 Программа досрочно закрылась с ошибкой
*/
int main()
{
    puts("insert a length of array\n");
    size_t length = get_size_t();
    puts("if you fill array by youself, press 1, if you fill array by random numbers, press 2\n");
    int choice = get_int();
    int* mas = get_mem_array(length);
    if (mas == 0)
    {
        puts("Inserted a wrong choice\n");
        return 1;
    }
    switch ((enum Choices)choice)
    {
        case random_choice:
            random_array(*mas, length);
            break;
        case user_choice:
            user_array(*mas, length);
            break;
        default:
            puts("Insert a valid choice!\n");
            return 1;
    }
    
    puts("insert a integer number\n");
    int number = get_int();
    printf("First task: %d\n", first_task(*mas, length, number));
    printf("Second task: %d\n", second_task(*mas, length));
    if (third_task(*mas, length) == 0)
    {
        puts("Third task: Not found\n");
    }
    else
    {
        printf("Third task: %d", third_task(*mas, length));
    }
    free_array(*mas);
    return 0;
}

int get_int()
{
    int number;
    if (scanf("%d", &number) != 1)
    {
        puts("Inserted a wrong value\n");
        abort();
    }
    return number;
}

size_t get_size_t()
{
    int number = get_int();
    if (number <= 0)
    {
        errno = ERANGE;
        perror("Error: \n");
        abort();
    }
    return (size_t)number;
}

int* get_mem_array(const int length)
{
    int* array = malloc(length * sizeof(int));
    if (NULL == array)
    {
        errno = ENOMEM;
        perror("Error: ");
        abort();
    }
    return array;
}

void user_array(int* const array, const size_t length)
{
    puts("Insert array elements:\n");

    for (size_t i = 0; i < length; i++)
    {
        array[i] = get_int();
    }
}

void random_array(int* const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand() % 200 - 100;
    }
}

int first_task(int* const array, size_t length, const int number)
{
    int result = 0;
    for (size_t i = 0; i < length; i += 2)
    {
        result += array[i];
    }
    return result;
}

int second_task(int* const array, size_t length)
{
    int result = array[length-1];
    for (size_t i = 1; i < length-1; i += 2)
    {
        if (array[i] > 0)
        {
            result *= array[i];
        }
    }
    return result;
}

int third_task(int* const array, const int length)
{
    for (int i = 1; i < length; i++)
    {
        if ((array[i] * array[i-1]) < 0)
        {
            return i;
        }
    }
    return 0;
}

void free_array(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}
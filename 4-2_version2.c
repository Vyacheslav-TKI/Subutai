#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <math.h>

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

enum Choices
{
    user_choice = 1,
    random_choice = 2,
};

/**
 * @brief Функция заполняет массив по выбору пользователя (сам или рандом)
 * @param choice целочисленное значение, означающее выбор способа заполнения массива
 * @param length длина массива
 * @return mas указатель на заполненный массив
 * @return 0 ошибка при выборе заполнения массива
*/
int* choices_to_fill_array(const int choice, const int length);

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

void show_array(const int* const array, const size_t length);

void copy_array(int* const array_original, int* array_copy, const size_t length);

int find_negative_elements(int* const array, size_t length);

int find_abs_min(int* const array, size_t length);

int *first_task(int* array, size_t length);

int new_index(int* array, size_t length);

int* second_task(int* const array, size_t length);

int is_even(int number);

int* third_task(int* const array, size_t length);

/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
*/
void free_array(int* array);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
*/
int main()
{
    puts("insert a length of array\n");
    size_t length = get_size_t();
    puts("if you fill array by youself, press 1, if you fill array by random numbers, press 2\n");
    int choice = get_int();
    int* mas = choices_to_fill_array(choice, length);
    if (mas == 0)
    {
        puts("Inserted a wrong choice\n");
        return 1;
    }
    if (first_task(*mas, length) == 1)
    {
        show_array(*mas, length);
    }
    puts("First task:\n");
    show_array(first_task(*mas, length), length);
    if (second_task(*mas, length) == 1)
    {
        show_array(*mas, length);
    }
    show_array(second_task(*mas, length), new_index(*mas, length));
    show_array(third_task(*mas, length), length);
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

int* choices_to_fill_array(const int choice, const int length)
{
    int* mas = get_mem_array(length);
    if (choice == (enum Choices)(user_choice))
    {
        user_array(*mas, length);
        return mas;
    }
    else if (choice == (enum Choices)(random_choice))
    {
        random_array(*mas, length);
        return mas;
    }
    return 0;
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

void show_array(const int* const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("Element[%d]  %d\n", i, array[i]);
    }
}

void copy_array(int* const array_original, int* array_copy, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        array_copy[i] = array_original[i];
    }
}

int find_negative_elements(int* const array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < 0)
        {
            return 0;
        }
    }
    return 1;
}

int find_abs_min(int* const array, size_t length)
{
    int index = length;
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < 0 && index > i)
        {
            index = i;
        }
    }
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < 0)
        {
            if (abs(array[index]) > abs(array[i]))
            {
                index = i;
            }
        }
    }
    return index;
}

int new_index(int* array, size_t length)
{
    int new_index = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] % 10 != 0)
        {
            new_index++;
        }
    }
    return new_index;
}

int is_even(int number)
{
    if (number % 2 == 0)
    {
        return 0;
    }
    return 1;
}

int *first_task(int* array, size_t length)
{
    if (find_negative_elements(array, length) == 1)
    {
        return 1;
    }
    int* new_array = get_mem_array(length);
    int ind_minimum;
    copy_array(*array, *new_array, length);
    ind_minimum = find_abs_min(*new_array, length);
    new_array[ind_minimum] = new_array[0];
    return new_array;
}

int* second_task(int* const array, size_t length)
{
    if (new_index(*array, length) == 0)
    {
        return 1;
    }
    int new_length = new_index(*array, length);
    int* new_array = get_mem_array(new_length);
    int top = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] % 10 != 0)
        {
            new_array[top] = array[i];
            top++;
        }
    }
    return new_array;
}

int* third_task(int* const array, size_t length)
{
    int* new_array = get_mem_array(length);
    copy_array(*array, *new_array, length);
    for (size_t i = 0; i < length; i++)
    {
        if (is_even(array[i]) == 0)
        {
            new_array[i] = i * array[i];
        }
        else
        {
            new_array[i] = -1 * array[i]; 
        }
    }
    return new_array;
}

void free_array(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}
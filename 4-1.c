#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/**
 * @brief Проверка введенного значения на целочисленность
 * @return x Целочисленное число
*/
int check_number();

/**
 * @brief Создаёт и заполняет массив рандомными числами в диапазоне [-100:200]
 * @param x размерность массива
 * @return array массив
*/
int *random_array(size_t size);

/**
 * @brief Создаёт динамический массив и заполнение происходит самим пользователем 
 * @param x размерность массива
 * @return array массив
*/
int *user_array(size_t size);

/**
 * @brief Находит сумму четных элементов, значения которых больше заданного числа.
 * @param number Заданное число
 * @param x размерность массива
 * @param mas указатель на массив
 * @return result результат
*/
int *first_task(int number, size_t size, int *mas);

/**
 * @brief Умножает все четные положительные элементы на последний элемент массива.
 * @param x размерность массива
 * @param mas указатель на массив
 * @return result результат
*/
int *second_task(int x, int *mas);

/**
 * @brief Находит номер первой пары соседних элементов с разными знаками.
 * @param x размерность массива
 * @param mas указатель на массив
 * @return result результат
*/
int *third_task(int x, int *mas);

enum Choices
{
random_choice = 1,
user_choice = 2,
};

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
*/
int main(){
    puts("Please, insert a integer number\n");
    int dimension = check_number();
    puts("If you want to fill the array yourself, press 1, if you want the program to fill the array itself, press 2\n");
    int choice = check_number_for_choices();
    int *mas = NULL;
    switch (choice)
    {
        case (enum Choices)(random_choice):
            int *mas = random_array(dimension);
        case (enum Choices)(user_choice):
            int *mas = user_array(dimension);
        default:
            puts("Inserted a wrong value\n");
            return 1;

    }
    puts("Insert a integer number\n");
    int number = check_number();
    printf("First task: %d\n", first_task(number, dimension, mas));
    printf("Second task: %d\n", second_task(dimension, mas));
    if (third_task(dimension, mas) == 0)
    {
        puts("Third task: Not found\n");
    }
    else
    {
        printf("Third task: %d", third_task(dimension, mas));
    }
    if (mas != NULL)
    {
        free(mas);
    }
    return 0;
}

int check_number(){
    int x;
    if (scanf("%d", &x) != 1)
    {
        puts("Inserted a wrong value!\n");
        abort();
    }
    return x;
}

int *random_array(size_t size){
    int *array = NULL;
    if (array == NULL)
        array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 200 - 100;
    }
    return array;
}

int *user_array(size_t size){
    int *array = NULL;
    if (array == NULL)
        array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        array[i] = check_number();
    }
    return array;
}

int *first_task(int number, size_t size, int *mas){
    int result = 0;
    for (int i = 0; i < size; i += 2)
    {
        if (mas[i] > number)
        {
            result += mas[i];
        }
    }
    return result;
}

int *second_task(int x, int *mas){
    int result = mas[x-1];
    for (int i = 0; i < x; i += 2)
    {
        if (mas[i] > 0)
        {
            result *= mas[i];
        }
    }
    return result;
}

int *third_task(int x, int *mas){
    for (int i = 1; i < x; i++)
    {
        if ((mas[i] * mas[i-1]) < 0)
        {
            return i;
        }
    }
    return 0;
}
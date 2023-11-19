#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/**
 * @brief Проверка введенного значения на целочисленность
 * @return x Целочисленное число
*/
int check_number();

/**
 * @brief Проверка числа на правильность
 * @return x число 1 или 2
*/
int check_number_for_choices();

/**
 * @brief Создаёт и заполняет массив рандомными числами в диапазоне [-100:200]
 * @param x размерность массива
 * @return array массив
*/
int *random_array(int x);

/**
 * @brief Создаёт динамический массив и заполнение происходит самим пользователем 
 * @param x размерность массива
 * @return array массив
*/
int *user_array(int x);

/**
 * @brief Находит сумму четных элементов, значения которых больше заданного числа.
 * @param number Заданное число
 * @param x размерность массива
 * @param mas указатель на массив
 * @return result результат
*/
int *first_task(int number, int x, int *mas);

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

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
*/
int main(){
    puts("Please, insert a integer number\n");
    int dimension = check_number();
    puts("If you want to fill the array yourself, press 1, if you want the program to fill the array itself, press 2\n");
    int choice = check_number_for_choices();
    if (choice == 1)
    {
        int *mas = user_array(dimension);
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
    }
    else 
    {
        int *mas = random_array(dimension);
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

int check_number_for_choices(){
    int x;
    if (scanf("%d", &x) != 1)
    {
        puts("Inserted a wrong value!\n");
        abort();
    }
    else if (x < 0 || x > 2)
    {
        puts("Inserted a wrong number!\n");
        abort();
    }
    return x;
}

int *random_array(int x){
    int *array = NULL;
    array = malloc(x * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        array[i] = rand() % 200 - 100;
    }
    return array;
}

int *user_array(int x){
    int *array = NULL;
    array = malloc(x * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        array[i] = check_number();
    }
    return array;
}

int *first_task(int number, int x, int *mas){
    int result = 0;
    for (int i = 0; i < x; i += 2)
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
        if ((mas[i] < 0 && mas[i-1] > 0) || (mas[i] > 0 && mas[i-1] < 0))
        {
            return i;
        }
    }
    return 0;
}
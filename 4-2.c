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
 * @brief Показывает элементы массива (1 элемент на одной строке)
 * @param mas указатель на массив
*/
int *show_array(int *mas);

/**
 * @brief Заменяет минимальный по модулю отрицательный элемент массива первым элементом.
 * @param x размерность массива
 * @param mas указатель на исходный массив
 * @return new_array получившийся массив
*/
int *first_task(int x, int *mas);

/**
 * @brief Удаляет из него все элементы, в записи которых последняя цифра равна 0.
 * @param x размерность массива
 * @param mas указатель на исходный массив
 * @return new_array получившийся массив
*/
int *second_task(int x, int *mas);

/**
 * @brief Из элементов массива P сформировать массив M той же размерности по правилу: если номер четный, то M[i]=i*P[i] , если нечетный, то M[i]=-P[i].
 * @param x размерность массива
 * @param mas указатель на исходный массив
 * @return new_array получившийся массив
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
        puts("First task:\n");
        if (first_task(dimension, mas) == 0)
        {
            show_array(mas);
        }
        else
        {
        show_array(first_task(dimension, mas));
        }
        puts("Second task\n");
        if (second_task(dimension, mas) == 0)
        {        
            show_array(mas);
        }
        else
        {
            show_array(second_task(dimension, mas));
        }
        puts("Third task: \n");
        show_array(third_task(dimension, mas));
    }
    else 
    {
        int *mas = random_array(dimension);
        
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

int *show_array(int *mas){
    int x = _msize(mas) / 4;
    for (int i = 0; i < x; i++)
    {
        printf("Array[%d] = %d\n", i, mas[i]);
    }
}

int *first_task(int x, int *mas){
    int minimum = 1000000000, ind_minimum = x + 1;
    int *new_array = NULL;
    new_array = malloc(x * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        if (mas[i] < 0)
        {
            if (minimum > abs(mas[i]))
            {
                minimum = abs(mas[i]);
                ind_minimum = i;
            }
        }
    }
    if (ind_minimum == x+1)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i <= x; i++)
        {
            if (i == ind_minimum)
            {
                new_array[i] = mas[0];
            }
            else
            {
                new_array[i] = mas[i];
            }
        }
        return new_array;
    }
}

int *second_task(int x, int *mas){
    int *new_array = NULL;
    int new_dimension = 0;
    for (int i = 0; i < x; i++)
    {
        if (mas[i] % 10 != 0)
        {
            new_dimension += 1;
        }
    }
    new_array = malloc(new_dimension * sizeof(int));
    if (new_dimension == x)
    {
        return 0;
    }
    int top = 0;
    for (int i = 0; i <= x; i++)
    {
        if (mas[i] % 10 != 0)
        {
            new_array[top] = mas[i];
            top += 1;
        }
    }
    return new_array;
}

int *third_task(int x, int *mas){
    int *new_array = NULL;
    new_array = malloc(x * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        if (mas[i] % 2 == 0)
        {
            new_array[i] = i * mas[i];
        }
        else
        {
            new_array[i] = -1 * mas[i]; 
        }
    }
    return new_array;
}
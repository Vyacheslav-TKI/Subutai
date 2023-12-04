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

/**
 * @brief структура хранит константы, указывающие выбор пользователя заполнить массив
 * @brief user_choice хранит значение, вызывающее ввод массива вручную
 * @brief random_choice хранит значение, вызывающее ввод массива случайными числами
*/
enum Choices
{
    user_choice = 1,
    random_choice = 2,
};

/**
 * @brief Функция выделяет память под многомерный массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
 * @return array указатель на пустой многомерный массив
*/
int* get_mem_array(const int rows, const int cols);

/**
 * @brief Функция заполняет массив, элементы вводит пользователь
 * @param array указатель на заполняемый массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void user_array(int* const array, const size_t rows, const size_t cols);

/**
 * @brief Функция заполняет массив рандомными числами в диапазоне, указанный пользователем
 * @param array указатель на заполняемый массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void random_array(int* const array, const size_t rows, const size_t cols);

/**
 * @brief Функция, показывающая массив поэлементно
 * @param array ссылка на показываемый массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void show_array(const int* const array, const size_t rows, const size_t cols);

/**
 * @brief Функция копирующая элементы одного массива в другой
 * @param array_original исходный массив
 * @param array_copy пустой массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void copy_array(int* const array_original, int* array_copy, const size_t rows, const size_t cols);

/**
 * @brief Функция проверяет массив на предмет отрицательного числа
 * @param array ссылка на массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
 * @return 0 Есть такие элементы
 * @return 1 Нет таких элементов
*/
int find_negative_elements(int* const array, size_t rows, size_t cols);

/**
 * @brief функция проверяет, есть ли данный элемент в массиве
 * @param array ссылка на массив
 * @param element  введенный элемент
 * @param length количество элементов в массиве
 * @return 1 элемент найдет
 * @return 0 элемент не найден
*/
int element_not_in_array(int* array, const int element, size_t length);

/**
 * @brief Заменяет отрицателный элемент каждого столбца нулем
 * @param array ссылка на массив
 * @param rows количество строк в массиве
 * @param cols количество столбцов в массиве
 * @return NULL отрицательных чисел нет
 * @return new_array новый массив, соответствующий этим требованиям
*/
int *first_task(int* array, size_t rows, size_t cols);

/**
 * @brief Функция вычисляет размерность нового массива по условию из 2 пункта
 * @param array ссылка на массив 
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
 * @return new_index размерность нового массива
*/
int new_index(int* array, size_t rows, size_t cols);

/**
 * @brief Функция заполняет одномерный массив столбцами многомерного массива по условию из функции new_index
 * @param linear_array одномерный массив
 * @param multidimensional_array многомерный массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void fill_linear_array(int* linear_array, int* multidimensional_array, size_t rows, size_t cols);

/**
 * @brief Функция удаляет из массива столбцы, содержащие элемент, кратный 5
 * @param array ссылка на массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
 * @return result_array новый массив, соответствующий этим требованиям
*/
int* second_task(int* const array, size_t rows, size_t cols);

/**
 * @brief Функция выделяет память под одномерный массив 
 * @param length длина массива
 * @return array пустой одномерный массив
*/
int* get_mem_array_with_one_dimension(const int length);

/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
 * @param rows количество строк в массиве
*/
void free_array(int* array, size_t rows);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
*/
int main()
{
    puts("insert a quantity of arrays\n");
    size_t n = get_size_t();
    puts("insert a length a inserted arrays\n");
    size_t m = get_size_t();
    puts("if you fill array by youself, press 1, if you fill array by random numbers, press 2\n");
    int choice = get_int();
    int* mas = get_mem_array(n, m);

    switch ((enum Choices)choice)
    {
        case random_choice:
            random_array(*mas, n, m);
            break;
        case user_choice:
            user_array(*mas, n, m);
            break;
        default:
            puts("Insert a valid choice!\n");
            return 1;
    }

    if (NULL == first_task(*mas, n, m))
    {
        show_array(*mas, n, m);
    }
    else
    {
        puts("First task:\n");
        show_array(first_task(*mas, n, m), n, m);
    }
    show_array(second_task(*mas, n, m), n, (m - (size_t)new_index(*mas, n, m)));
    free_array(*mas, n);
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

int* get_mem_array(const int rows, const int cols)
{
    int** array = malloc(rows * sizeof(*array));
    for (int i = 0; i < rows; i++)
    {
        array[i] = malloc(cols * sizeof(array[0]));
    }
    for (int i = 0; i < rows; i++)
    {
        if (NULL == array[i])
        {
        errno = ENOMEM;
        perror("Error: ");
        abort();
        }
    }
    
    return array;
}

void user_array(int* const array, const size_t rows, const size_t cols)
{
    puts("Insert array elements:\n");

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            array[i][j] = get_int();
        }
    }
}

void random_array(int* const array, const size_t rows, const size_t cols)
{
    puts("Enter a minimal number in range\n");
    int minimum = get_int();
    puts("Enter a maximum number in range\n");
    int maximum = get_int();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            array[i][j] = rand() % maximum - fabs(minimum);
        }
    }
}

void show_array(const int* const array, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("Element[%d][%d]  %d\n", i, j, array[i][j]);
        }
    }
}

void copy_array(int* const array_original, int* array_copy, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            array_copy[i][j] = array_original[i][j];
        }
    }
}

int find_negative_elements(int* const array, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (array[i][j] < 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int element_not_in_array(int* array, const int element, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

int new_index(int* array, size_t rows, size_t cols)
{
    int new_index = 0;
    for (size_t i = 0; i < rows; i++)
    {
        int flag = 0;
        if (flag == 1)
        {
            new_index++;
            flag = 0;
        }
        else
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (array[i] % 5 == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    return new_index;
}

int* get_mem_array_with_one_dimension(const int length)
{
    int* array = malloc(length * sizeof(int));
    if (NULL == array)
    {
        errno = ENOMEM;
        perror("Error: \n");
        abort();
    }
    return array;
}

void fill_linear_array(int* linear_array, int* multidimensional_array, size_t rows, size_t cols)
{
    int temp_col = 0;
    int top = 0;
    int flag = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (flag == 1)
        {
            linear_array[top] = temp_col;
            top++;
            flag = 0;
        }
        else
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (multidimensional_array[i][j] % 5 == 0)
                {
                    flag = 1;
                    temp_col = j;
                    break;
                }
            }
        }
    }
}

int *first_task(int* array, size_t rows, size_t cols)
{
    
    if (find_negative_elements(array, rows, cols) == 1)
    {
        return NULL;
    }
    int* new_array = get_mem_array(rows, cols);
    copy_array(*array, *new_array, rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (new_array[i][j] < 0)
            {
                new_array[i][j] = 0;
            }
        }
    }
    return new_array;
}

int* second_task(int* const array, size_t rows, size_t cols)
{
    if (new_index(*array, rows, cols) == 0)
    {
        return NULL;
    }
    int new_length = new_index(*array, rows, cols);
    int* new_array = get_mem_array_with_one_dimension(new_length);
    fill_linear_array(*new_array, *array, rows, cols);
    int* result_array = get_mem_array(rows, cols - (size_t)new_length);
    size_t top_i = 0, top_j = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (element_not_in_array(*new_array, j, new_length) == 1)
            {
                break;
            }
            else
            {
                result_array[top_i][top_j] = array[i][j];
                top_i++;
            }
        top_i++;
        }
    }
    return result_array;
}

void free_array(int* array, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        if (NULL != array[i])
        {
            free(array[i]);
        }
    }
    if (NULL != array)
    {
        free(array);
    }
}
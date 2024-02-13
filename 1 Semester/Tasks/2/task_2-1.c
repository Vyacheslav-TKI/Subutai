#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/**
*@brief Функция проверяет, положительное ли число?
*@param x проверяемое число
*@return 1 - число положительное и отличное от нуля, 0 - число отрицательное или нуль
*/
int is_positive(const double x);

/**
*@brief Функция вычисляет нужную пользователю искомую величину
*@param x порядковый номер формулы
*/
double formula_selection(int x, double cube_edge);

/**
*@brief Функция сверяет введенное значение из переменной formula
*@param x значение переменной formula
*@return 1 - введенное число принадлежит диапазону [1;3]
*/
int is_right_number(const int x);

enum Values
{
face_area = 1,
total_surface = 2,
volume = 3,
};
/**
*@brief Точка входа в программу
*@return 0 программа работает правильно
*@return 1 в программе есть ошибка
*/
int main(){

    double cube_edge;
    int formula;
    puts("Please, insert a non-negative number\n");

    if(scanf("%lf", &cube_edge) != 1){
        puts("Please insert a valid value\n");
        return 1;}
    if (is_positive(cube_edge) == 0){
        puts("Please, enter a non-negative number!\n");
        return 1;
        }

    puts("Please, write what you want to find: face area, total surface area or volume\n");
    printf("If you want to find face area, press %d\n", (enum Values)(face_area));
    printf("If you want to find total surface, press %d\n", (enum Values)(total_surface));
    printf("If you want to find volume, press %d\n", (enum Values)(volume));

    if(scanf("%d", &formula) != 1){
        puts("Please input a valid value!\n");
        return 1;}
    if(is_right_number(formula) == 0){
        printf("Please, enter %d, %d or %d!\n", (enum Values)(face_area), (enum Values)(total_surface), (enum Values)(volume));
        return 1;
    }
    else{
        formula_selection(formula, cube_edge);
    }
    return 0;
}

int is_right_number(const int x){
    return (x > 0 && x < 4) ? 1 : 0;
}

int is_positive(const double x){ // Зачем мне тут использовать bool?
    return (x > 0) ? 1 : 0;
}

double formula_selection(int x, double cube_edge){
    if(x == (enum Values)(face_area)){
        double x = cube_edge*cube_edge;
        printf("Face area equals: %lf", x);
    }
    else if(x == (enum Values)(total_surface)){
        double y = 6 * cube_edge * cube_edge;
        printf("Total surface equals: %lf", y);
    }
    else if(x == (enum Values)(volume)){
        double z = cube_edge*cube_edge*cube_edge;
        printf("Volume equals: %lf", z);
    }
}
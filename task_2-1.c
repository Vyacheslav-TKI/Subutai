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
    total_surface = 25,
    volume = 3,
};

int main(){

    double cube_edge;
    int formula;
    puts("Please, insert a non-negative number\n");

    if(scanf("%lf", &cube_edge) != 1){
        puts("Please insert a valid value\n");
        abort();}
    if (is_positive(cube_edge) == 0){
        puts("Please, enter a non-negative number!\n");
        abort();
    }

    puts("Please, write what you want to find: face area, total surface area or volume\n");
    printf("If you want to find face area, press %d\n", (enum Values)(face_area));
    printf("If you want to find total surface, press %d\n", (enum Values)(total_surface));
    printf("If you want to find volume, press %d\n", (enum Values)(volume));



    if(scanf("%d", &formula) != 1){
        puts("Please input a valid value!\n");
        abort();}
    if(is_right_number(formula) == 0){
        puts("Please, enter 1, 2 or 3!\n");
        abort();
    }
    else{
        formula_selection(formula, cube_edge);
    }
    return 0;
}

int is_right_number(const int x){
    if(x > 0 && x < 4){
        return 1;
    }
    return 0;
}

int is_positive(const double x){
    if(x>0){
        return 1;
    }
    return 0;
}

double formula_selection(int x, double cube_edge){ // раздробить?
    enum Values face = face_area, total = total_surface, volume_cube = volume;
    if(x == face){
        double x = cube_edge*cube_edge;
        printf("Face area equals: %lf", x);
    }
    else if(x == total){
        double y = 6 * cube_edge * cube_edge;
        printf("Total surface equals: %lf", y);
    }
    else if(x == volume_cube){
        double z = cube_edge*cube_edge*cube_edge;
        printf("Volume equals: %lf", z);
    }
}
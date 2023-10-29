#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
*@brief Функция проверяет положительность числа
*@param x проверяемое число
*@return 1 - число отрицательное или равное нулю, 0 - число положительное
*/
int pozitive_num(double x);

/**
*@brief Функция проверяет принадлежность задданного значения к положительным числам
*@return x введенное правильное значение
*/
double get_number();

/**
*@brief Функция проверяет, можно ли из этих сторон построить треугольник
*@param first_side длина отрезка
*@param second_side длина отрезка
*@param third_side длина отрезка
*@return 1 можно построить треугольник
*@return 0 нельзя построить треугольник
*/
int is_triangle(double first_side, double second_side, double third_side);

/**
*@brief Функция проверяет треугольник на остроугольность по его сторонам
*@param first_side длина стороны
*@param second_side длина стороны
*@param third_side длина стороны
*@return 1 Треугольник остроугольный
*@return 0 Треугольник не остроугольный
*/
int is_acute(double first_side, double second_side, double third_side);

/**
*@brief Точка входа в программу
*/
int main(){
    puts("In the next(3) strings enter non-negative numbers\n");

    double first_side = get_number(), second_side = get_number(), third_side = get_number();

    if(is_triangle(first_side, second_side, third_side) == 0){
        puts("It is impossible to make a triangle from these sides\n");
        }
    else{
        puts("It is possible to make a triangle from these sides\n");
        if(is_acute(first_side, second_side, third_side) == 1){
            puts("Acute triangle\n");
            }
        else{
            puts("Non-acute triangle\n");
            }
    }
    return 0;
}

int pozitive_num(double x){
    return x > 0 ? 0 : 1;
}

double get_number(){
    double x;
    if(scanf("%lf", &x) != 1){
        puts("Please insert a valid value\n");
        abort();}
    if(pozitive_num(x) == 1){
        puts("Please, enter non-negative number\n");
        abort();
        }
    return x;
}

int is_triangle(double first_side, double second_side, double third_side){
    if((first_side+second_side > third_side) && (first_side + third_side > second_side) && (second_side+third_side > first_side)){
    return 1;}
    return 0;
}

int is_acute(double first_side, double second_side, double third_side){
    if((first_side*first_side < second_side*second_side+third_side*third_side) && (second_side*second_side < first_side*first_side+third_side*third_side) && (third_side*third_side < first_side*first_side+second_side*second_side)){
        return 1;}
    return 0;
}
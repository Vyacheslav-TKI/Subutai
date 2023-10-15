#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/** 
 * @brief Функция считает среднее арифметическое кубов заданных чисел
 * @param x Первое рациональное число
 * @param y Второе рациональное число
 */
double arithmetic_mean_of_cubes(double x, double y);
/**
 * @brief Функция считает среднее геометрическое МОДУЛЕЙ чисел
 * @param x Первое рациональное число
 * @param y Второе рациональное число
*/
double geometric_mean(double x, double y);

int main(){
    double i, j, average, geom_mean;

    puts("In the next strings insert just non-negative or just negative numbers\n");

    if(scanf("%lf", &i) != 1){
        puts("Please, insert a valid value!\n");
        abort();}
    if(scanf("%lf", &j) != 1){
        puts("Please, insert a valid value!");
        abort();}

    average = arithmetic_mean_of_cubes(i, j);
    geom_mean = geometric_mean(i, j);
    printf("The arithmetic mean of cubes of numbers is equal to: %.2f\n", average);
    printf("The geometric mean of the numbers is: %.2f\n", geom_mean);
    
    return 0;

}
double arithmetic_mean_of_cubes(double x, double y){
    double cube_x, cube_y;
    cube_x = x * x * x;
    cube_y = y * y * y;
    return (cube_x + cube_y) / 2;
}

double geometric_mean(double x, double y){
    if(x < 0){
        x *= -1;
    }
    if (y < 0){
        y *= -1;
    }
    return sqrt(x * y);
}

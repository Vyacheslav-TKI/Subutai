#include <stdio.h>
#include <math.h>


/** 
 * @brief Функция считает среднее арифметическое кубов заданных чисел
 * @param x, y являются рациональными числами
 */
double arithmetic_mean_of_cubes(double x, double y);
/**
 * @brief Функция считает среднее геометрическое МОДУЛЕЙ чисел
 * @param x, y являются рациональными числами
*/
double geometric_mean(double x, double y);

int main(){
    double i, j, sr_arifm_cube, sr_geom;

    puts("In the next strings insert just non-negative or just negative numbers\n");

    scanf("%lf", &i);
    scanf("%lf", &j);

    sr_arifm_cube = arithmetic_mean_of_cubes(i, j);
    sr_geom = geometric_mean(i, j);
    printf("The arithmetic mean of cubes of numbers is equal to: %.2f\n", sr_arifm_cube);
    printf("The geometric mean of the numbers is: %.2f\n", sr_geom);
    
    return 0;

}
double arithmetic_mean_of_cubes(double x, double y){
    double cube_x, cube_y;
    cube_x = x * x * x;
    cube_y = y * y * y;
    return (cube_x + cube_y) / 2;
}

double geometric_mean(double x, double y){
    x = abs(x);
    y = abs(y);
    return sqrt(x * y);
}

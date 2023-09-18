#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/** 
 * @brief Функция считает среднее арифметическое кубов заданных чисел
 * @param x, y являются рациональными числами
 */
double Srednee_arifmetich_cubov(double x, double y);
/**
 * @brief Функция считает среднее геометрическое МОДУЛЕЙ чисел
 * @param x, y являются рациональными числами
*/
double Srednee_geometricheskoye(double x, double y);

int main(){
    double i, j, sr_arifm_cube, sr_geom;

    printf("%s", "In the next strings insert just non-negative or just negative numbers\n");

    scanf("%lf", &i);
    scanf("%lf", &j);

    sr_arifm_cube = Srednee_arifmetich_cubov(i, j);
    sr_geom = Srednee_geometricheskoye(i, j);
    printf("The arithmetic mean of cubes of numbers is equal to: %.2f\n", sr_arifm_cube);
    printf("The geometric mean of the numbers is: %.2f\n", sr_geom);
    
    return 0;

}
double Srednee_arifmetich_cubov(double x, double y){
    double cube_x, cube_y;
    cube_x = x * x * x;
    cube_y = y * y * y;
    return (cube_x + cube_y) / 2;
}

double Srednee_geometricheskoye(double x, double y){
    x = abs(x);
    y = abs(y);
    return sqrt(x * y);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/** 
 * @brief Функция считает среднее арифметическое кубов заданных чисел
 * @param x, y являются рациональными числами
 */
double frst_num(double x, double y);
/**
 * @brief Функция считает среднее геометрическое МОДУЛЕЙ чисел
 * @param x, y являются рациональными числами
*/
double sec_num(double x, double y);
/**
 * @brief Функция проверяет, что в переменной (в функции массиве) присутствуют только цифры или вспомогательные знаки ('.', '-')
 * @param *check_param является указателем (адресом) для проверяемой переменной
 * @return 0 => В переменной есть другие символы, 1 => В переменной только цифры
*/
int is_num(double *check_param);

int main(){
    double i, j, sr_arifm_cube, sr_geom;

    printf("In the next strings insert just non-negative or just negative numbers\n");

    while(!is_num(&i)){
        printf("In first value contains not number!\n");
    }

    while(!is_num(&j)){
        printf("In second value contains not number!\n");
    }


    sr_arifm_cube = frst_num(i, j);
    sr_geom = sec_num(i, j);
    printf("The arithmetic mean of cubes of numbers is equal to: %.2f\n", sr_arifm_cube);
    printf("The geometric mean of the numbers is: %.2f\n", sr_geom);
    
    return 0;

}
double frst_num(double x, double y){
    double cube_x, cube_y;
    cube_x = x*x*x;
    cube_y = y*y*y;
    return (cube_x+cube_y)/2;
}

double sec_num(double x, double y){
    x = abs(x);
    y = abs(y);
    return sqrt(x*y);
}

int is_num(double *check_param) {
    char buffer[16];
    memset(&buffer, '\0', 16);
    scanf("%s", &buffer);
    for(int i = 0; i < 16; i++){
        if((buffer[i] < 48 || buffer[i] > 57) && buffer[i] != '.' && buffer[i] != '\0' && buffer[i] != '-'){
            return 0;
        }
    }
    sscanf(buffer, "%lf", check_param);
    return 1;
}

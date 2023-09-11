#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
 * @brief Функция рассчитывает потенциальную энергию
 * @param k, x; где k - жесткость пружины, x - растянутость пружины
*/
double Potential_energy(double k, double x);
/**
 * @brief Функция проверяет, что в переменной (в функции массиве) присутствуют только цифры или вспомогательные знаки ('.')
 * @param *check_param является указателем (адресом) для проверяемой переменной
 * @return 0 => В переменной есть другие символы, 1 => В переменной только цифры
*/
int is_num(double *check_param);

int main(){
    double k, x, energy;
    printf("Insert the k value first, then the x value, all values is non-negative number\n");

    while(!is_num(&k)){
        printf("Insert a non-negative number\n");
    }

    while(!is_num(&x)){
        printf("Insert a non-negative number\n");
    }

    energy = Potential_energy(k, x);
    printf("Potential energy equals: %.2f", energy);

    return 0;
}

double Potential_energy(double k, double x){
    double Poten_energy;
    Poten_energy = (k*x*x)/2;
    return Poten_energy;
}

int is_num(double *check_param) {
    char buffer[16];
    memset(&buffer, '\0', 16);
    scanf("%s", &buffer);
    for(int i = 0; i < 16; i++){
        if((buffer[i] < 48 || buffer[i] > 57) && buffer[i] != '.' && buffer[i] != '\0'){
            return 0;
        }
    }
    sscanf(buffer, "%lf", check_param);
    return 1;
}
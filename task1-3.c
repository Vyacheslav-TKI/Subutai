#include <stdio.h>
#include <math.h>

/**
 * @brief Функция рассчитывает потенциальную энергию
 * @param k - жесткость пружины,
 * @param x - растянутость пружины
*/
double Potential_energy(double k, double x);
/**
 * @brief Функция проверяет на положительность или нейтральность(число==0) числа
 * @param check_param проверяемая переменная
 * @return 0 => Число отрицательное, 1 => Число положительное или равно нулю
*/
int is_num(double check_param);

int main(){
    double k, x, energy;
    printf("%s", "Insert the k value first, then the x value, all values is non-negative number\n");

    scanf("%lf", &k);
    scanf("%lf", &x);

    if(is_num(k) && is_num(x)){

        energy = Potential_energy(k, x);
        printf("Potential energy equals: %.2f", energy);

    
    }
    else {
        printf("%s", "Insert only pozitive numbers!\n");
    }
    return 0;
}

double Potential_energy(double k, double x){
    double Poten_energy;
    Poten_energy = (k * x * x) / 2;
    return Poten_energy;
}

int is_num(double check_param) {
    if (check_param >= 0.0f){
        return 1;
    }
    return 0;
}
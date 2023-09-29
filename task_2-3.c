#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Функция проверяет положительность числа
 * @param x проверяемое число
 * @return 1 - число отрицательное или равное нулю, 0 - число положительное
*/
int is_pozitive_num(double x);

int main(){
    float first_side, second_side, third_side;
    
    puts("In the next(3) strings enter non-negative numbers\n");
    scanf("%f", &first_side);
    scanf("%f", &second_side);
    scanf("%f", &third_side);

    if (is_pozitive_num(first_side) || is_pozitive_num(second_side) || is_pozitive_num(third_side)){
        puts("Please, enter non-negative number\n");
    }
    else{
        if((first_side+second_side > third_side) && (first_side + third_side > second_side) && (second_side+third_side > first_side)){
            puts("It is possible to make a triangle from these sides\n");
            if((first_side*first_side < second_side*second_side+third_side*third_side) && (second_side*second_side < first_side*first_side+third_side*third_side) && (third_side*third_side < first_side*first_side+second_side*second_side)){
                puts("Acute triangle\n");
            }
            else {
                puts("Non-acute triangle\n");
            }
        }
    }
    return 0;

}

int is_pozitive_num(double x){
    if(x > 0){
        return 0;
    }
    return 1;
}
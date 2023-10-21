#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Функция подсчитывает разряды целого числа
 * @param y Введенное целочисленное число
 * @return кол-во разрядов 
*/
int counting_digits(int y);

int main(){
    int number, counter = 0;
    if (scanf("%d", &number) != 1){
        puts("Please, insert a natural number!\n");
        abort();
    }
    printf("%d", counting_digits(number));
}

int counting_digits(int y){
    int counter = 0;

    while (y > 0){
        y = (int)y / 10;
        counter = counter + 1;
    }

    return counter;
}
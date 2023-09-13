#include <stdio.h>
#include <math.h>

/**
 * @brief Функция проверяет, положительное ли число?
 * @param x проверяемое число
 * @return 1 - число положительное и отличное от нуля, 0 - число отрицательное или нуль
*/

int is_right_num(double x);

int main(){
    float rebro;
    int formul;
    printf("%s", "Please, insert a non-negative number\n");

    scanf("%f", &rebro);
    if(!is_right_num(rebro)){
        printf("%s", "Insert a valid value!\n");
    }
    else {
        double x = rebro*rebro;
        double y = 6 * rebro * rebro;
        double z = rebro*rebro*rebro;

        printf("%s", "Please, write what you want to find: face area, total surface area or volume\n");
        printf("%s", "If you want to find face area, enter '1'.\n");
        printf("%s", "If you want to find total surface, enter '2'\n");
        printf("%s", "If you want to find volume, enter '3'\n");

        scanf("%d", &formul);
        switch (formul){
        case 1:
            
            printf("Face area equals: %.2f", x);
            break;
        case 2:
            
            printf("Total surface equals: %.2f", y);
            break;
        case 3:
           
            printf("Volume equals: %.2f", z);
            break;
        default:
            printf("%s", "Please, enter your wanted formule\n");
            break;
    }
    }
    return 0;
}

int is_right_num(double x){
    if(x > 0){
        return 1;
    }
    return 0;
}
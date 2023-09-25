#include <stdio.h>
#include <math.h>


/**
 * @brief Функция проверяет, положительное ли число?
 * @param x проверяемое число
 * @return 1 - число положительное и отличное от нуля, 0 - число отрицательное или нуль
*/

int is_right_num(double x);

int main(){
    enum Values
{
    face_area = 1,
    total_surface = 2,
    volume = 3,
};

    float rebro;
    int formul;
    printf("%s", "Please, insert a non-negative number\n");

    scanf("%f", &rebro);
    if(!is_right_num(rebro)){
        printf("%s", "Insert a valid value!\n");
    }
    else {

        printf("%s", "Please, write what you want to find: face area, total surface area or volume\n");
        printf("%s", "If you want to find face area, press '1'.\n");
        printf("%s", "If you want to find total surface, press '2'\n");
        printf("%s", "If you want to find volume, press '3'\n");

        scanf("%d", &formul);
        if(formul == face_area){
            double x = rebro*rebro;
            printf("Face area equals: %lf", x);
        }
        else if(formul == total_surface){
            double y = 6 * rebro * rebro;
            printf("Total surface equals: %lf", y);
        }
        else if(formul == volume){
            double z = rebro*rebro*rebro;
            printf("Volume equals: %lf", z);
        }
    return 0;
}
}

int is_right_num(double x){
    if(x > 0){
        return 1;
    }
    return 0;
}
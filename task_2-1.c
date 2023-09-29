#include <stdio.h>
#include <math.h>


/**
 * @brief Функция проверяет, положительное ли число?
 * @param x проверяемое число
 * @return 1 - число положительное и отличное от нуля, 0 - число отрицательное или нуль
*/
int is_positive(const double x);

/**
 * @brief Функция вычисляет нужную пользователю величину
 * @param x порядковый номер формулы
*/
double formula_selection(int x, double cube_edge);

enum Values
{
    face_area = 1,
    total_surface = 2,
    volume = 3,
};

int main(){
    
    float cube_edge;
    int formula;
    puts("Please, insert a non-negative number\n");

    scanf("%f", &cube_edge);
    if (is_positive(cube_edge) == 0){
        puts("Please, enter a non-negative number!\n");
        return 0;
        abort();
    }
    else{
        if(!is_right_num(cube_edge)){
            printf("%s", "Insert a valid value!\n");
        }
        else {

            puts("Please, write what you want to find: face area, total surface area or volume\n");
            puts("If you want to find face area, press '1'.\n");
            puts("If you want to find total surface, press '2'\n");
            puts("If you want to find volume, press '3'\n");

            scanf("%d", &formula);
            if(is_right_num(formula) == 0){
                puts("Please, enter 1, 2 or 3!\n");
                return 0;
                abort();
            }
            else{
                formula_selection(formula, cube_edge);
            }
        
        return 0;
}
}
}

int is_positive(const double x){
    if(x > 0){
        return 1;
    }
    return 0;
}

double formula_selection(int x, double cube_edge){
    if(x == face_area){
            double x = cube_edge*cube_edge;
            printf("Face area equals: %lf", x);
        }
        else if(x == total_surface){
            double y = 6 * cube_edge * cube_edge;
            printf("Total surface equals: %lf", y);
        }
        else if(x == volume){
            double z = cube_edge*cube_edge*cube_edge;
            printf("Volume equals: %lf", z);
        }
    return 0;
}
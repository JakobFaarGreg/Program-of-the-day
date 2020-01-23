/* Dette program skal kunne printe volumen af en firkant med forskellige hoejder. */
#include <stdio.h>
#include <stdlib.h>
double calculate_volume(double heigth, double length);

int main() {
    double heigth = 0, length = 0;
    int i = 0;
    printf("What is the height and length of your square?\n");
    scanf(" %lf %lf", &heigth, &length);
    for (i = 1; i <= 5; i++){
        printf("height of %d makes the volume = %.3lf\n", i, calculate_volume(heigth, length) * i);
    }
    return EXIT_SUCCESS;
}

double calculate_volume(double heigth, double length){
    return heigth * length;
}

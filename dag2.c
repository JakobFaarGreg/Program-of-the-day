/* Udregning af volume udfra tykkelse og laengde */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define METER_TO_CENTIMETER 100
#define CENTIMETER_TO_METER 100
#define MILLIMETER_TO_CENTIMETER 10

double prompt_for_diameter();
double prompt_for_length();
double calculate_volume_on_barrel(double diameter, double volume);
void   print_length_by_diameter(double volume);
double calculate_length_from_volume(double diameter, double volume);

int main() {
    int answer = 0;
    double lineDiameter = 0, volume = 0, lineLength = 0;
    printf("Velkommen bruger\nVil du indtaste rumfang (1) eller producent-standarder? (2)\n");
    scanf(" %d", &answer);
    if (answer == 1) {
        printf("Hvad er rumfanget?\n");
        scanf(" %lf", &volume);
    }
    else if (answer == 2) {
        printf("For at kunne udregne snoerelaengder skal der bruges en standard fra producenten.\n");
        lineDiameter = prompt_for_diameter();
        lineLength   = prompt_for_length();
        volume = calculate_volume_on_barrel(lineDiameter, lineLength);
        printf("Der er %f kubikcentimeter plads paa tromlen. \n", volume);
    }
    printf("Baseret på volumen %lf cm^3, kan der vaere snoerer med disse tykkelser i disse laengder:\n", volume);
    print_length_by_diameter(volume);
    return EXIT_SUCCESS;
}
/* Skal bede brugeren om input til kalibrering */
double prompt_for_diameter() {
    double diameter = 0;
    printf("Diameter af snoere:\n");
    scanf(" %lf", &diameter);
    return diameter;
}
/* Skal bede brugeren om input til kalibrering */
double prompt_for_length() {
    double length = 0;
    printf("Stoerste laengde:\n");
    scanf(" %lf", &length);
    return length;
}
/* Skal udregne volumen omkring tromlen */
double calculate_volume_on_barrel(double diameter, double length) {
    double volume = 0;
    diameter = diameter / MILLIMETER_TO_CENTIMETER;
    length   = length * METER_TO_CENTIMETER;
    volume   = ((pow((diameter / 2), 2) * M_PI) * length);
    return volume;
}
/* Skal printe en tabel med nogle forskellige snoeretykkelser og deres maksimale laengde */
void print_length_by_diameter(double volume){
    int i = 0;
    double diameter = 0.28, length = 0;
    for (i = 1; i <= 10; i++) {
        length = calculate_length_from_volume(diameter, volume);
        printf("|%.2lf mm. | %.2lf m laengde|\n", diameter, length);
        diameter += 0.01;
    }
}
/* Skal udregne laengde af forskellige tykkelse snoerer */
double calculate_length_from_volume(double diameter, double volume){
    double length = 0;
    length  = (volume / (pow(diameter / 2, 2) * M_PI));
    return length;
}

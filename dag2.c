/* Udregning af volume udfra tykkelse og laengde */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define METER_TO_CENTIMETER 100
#define MILLIMETER_TO_CENTIMETER 10
#define CENTIMETER_TO_METER 100

double prompt_for_diameter();
int    prompt_for_length();
double calculate_volume_on_barrel(double, int);
void   print_volume_to_length(double volume);
double calculate_length_from_volume(double diameter, double volume);

int main() {
    int lineLength = 0;
    double lineDiameter = 0, volume = 0;
    printf("For at kunne udregne snoerelaengder skal jeg bruge en standard fra producenten.\n");
    lineDiameter = prompt_for_diameter();
    lineLength   = prompt_for_length();
    volume = calculate_volume_on_barrel(lineDiameter, lineLength);
    printf("Der er %f kubikcentimeter plads paa tromlen. \n", volume);

    printf("Baseret på den volume kan der vaere snoerer i disse tykkelser i disse laengder:\n");
    print_volume_to_length(volume);
    return EXIT_SUCCESS;
}

double prompt_for_diameter() {
    double diameter = 0;
    printf("Bredde af snoere:\n");
    scanf(" %lf", &diameter);
    return diameter;
}

int prompt_for_length() {
    int length = 0;
    printf("Stoerste laengde:\n");
    scanf(" %d", &length);
    return length;
}

/* Skal udregne volumen omkring tromlen */
double calculate_volume_on_barrel(double diameter, int length) {
    double volume = 0;
    diameter = diameter / MILLIMETER_TO_CENTIMETER;
    length = length * METER_TO_CENTIMETER;
    volume = ((pow((diameter / 2), 2) * M_PI) * length);
    return volume;
}

/* Skal printe en tabel med nogle forskellige snoeretykkelser og deres laengeste laengde */
void print_volume_to_length(double volume){
    int i = 0;
    double diameter = 0;
    for (i = 1; i <= 10; i++) {
        diameter = (0.28 + i/100);
        printf("|%.2lf mm. tykkelse | %.2lf meter laengde|\n", diameter, calculate_length_from_volume(diameter, volume));
    }
}

/* Skal udregne laengde af forskellige tykkelse snoerer */
double calculate_length_from_volume(double diameter, double volume){
    double length = 0;
    length = (volume / (pow(diameter / 2, 2) * M_PI));
    length *= CENTIMETER_TO_METER;
    return length;
}

/* Dette program skal foreslå det størst mulige areal efter en hegnslaengde */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void prompt_user_for_choice(int* choice);
void prompt_user_for_fence_length(double* l);
void prompt_user_for_fenced_area(double* l);
double calculate_greatest_area(double l);
double calculate_shortest_length(double area);

int main(){
    int choice = 0;
    double l = 0;

    prompt_user_for_choice(&choice);
    if (choice == 1){
        prompt_user_for_fence_length(&l);
        printf("For the fence length %lf the greatest possible area is %lf.\n", l, calculate_greatest_area(l));
    }
    else {
        prompt_user_for_fenced_area(&l);
        printf("For the desired area %lf the shortest possible fence is %lf.\n", l, calculate_shortest_length(l));
    }

    return EXIT_SUCCESS;
}
void prompt_user_for_choice(int* choice){
    int scanres = 0;
    printf("Do you want to find Area from Length (1) or Length from Area (2): ");

    /* STUB Her vil jeg have at den kan screene for korrekt input. */
    do {
        scanres = scanf(" %d", choice);
    }   while(scanres == 0);
}

void prompt_user_for_fence_length(double* l){
    printf("How long of a fence do you have?\n");
    scanf(" %lf", l);
}

void prompt_user_for_fenced_area(double* l){
    printf("How big of an area do you want fenced in?\n");
    scanf(" %lf", l);
}

double calculate_greatest_area(double l){
    double area = 0;
    area = sqrt(l);
    return area;
}

double calculate_shortest_length(double area){
    double length = 0;
    length = pow(area,2);
    return length;
}

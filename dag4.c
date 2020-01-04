/* Dette program skal være en nip-napper */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void any_number_choice(int* playerChoice);
void number_choice(int* playerChoice);
int color_choice();
void print_result(int playerChoice);

enum colors {Roed = 3, Groen = 2, Blaa = 3, Hvid = 2};

int main() {
    int playerChoice = 0, countdown = 4;

    do {
        if (countdown == 0) {
            any_number_choice(&playerChoice);
            countdown--;
        }
        else if (playerChoice % 2 == 0) {
            number_choice(&playerChoice);
            if (playerChoice % 2 != 0) {
                playerChoice = 1;
            }
            countdown--;
        }
        else if (playerChoice % 2 != 0){
            if (color_choice() % 2 != 0) {
                playerChoice = 2;
            }
            countdown--;
        }
    } while (countdown != 0);
    print_result(playerChoice);
    return EXIT_SUCCESS;
}

void any_number_choice(int* playerChoice) {
    int number = 0;
    printf("Choose any number:\n");
    scanf(" %d", &number);
    if (number % 2 == 0)
        *playerChoice = 2;
    else {
        *playerChoice = 1;
    }
}

int color_choice() {
    int color = 0;
    char str1[7] = "       ";
    printf("Hvilken farve?\nRoed, Groen, Blaa, Hvid\n");
    scanf(" %s", &str1[0]);
    if (strcmp(str1, "Roed") == 0)
        color = Roed;
    else if (strcmp(str1, "Groen") == 0)
        color = Groen;
    else if (strcmp(str1, "Blaa") == 0)
        color = Blaa;
    else if (strcmp(str1, "Hvid") == 0)
        color = Hvid;
    else{
        printf("Invalid Input!\n");
    }
    return color;
}

void number_choice(int* playerChoice) {
    printf("Et tal mellem 1 og 8:\n");
    scanf(" %d", playerChoice);
}

void print_result(int playerChoice) {
    number_choice(&playerChoice);
    switch (playerChoice)
    {
    case 1: printf("Du er 16 aar gammel\n"); break;
    case 2: printf("Du er nu stjernetegnet Krebsen\n"); break;
    case 3: printf("Du er nu en Hollywood celebrity\n"); break;
    case 4: printf("Du burde gaa til laegen\n"); break;
    case 5: printf("Du har mistet al din charme\n"); break;
    case 6: printf("Du kunne traenge til ferie\n"); break;
    case 7: printf("Du faar snart et opkald fra banken\n"); break;
    case 8: printf("Du mangler hvide t-shirts med print\n"); break;
    default: break;
    }
}

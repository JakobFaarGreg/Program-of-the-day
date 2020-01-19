/* Dette program skal kunne bede om et navn på en vinge og give metermål samt produktionspris og salgspris. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 30
#define NUMBER_OF_WINGS 10

struct wing {
    char name[NAME_SIZE];
    int size, productionCost, salesPrice;
};
typedef struct wing wing;
wing array[NUMBER_OF_WINGS];

int main() {
    FILE *file_pointer;
    int i = 0;
    char userInput[NAME_SIZE], ch = '0';

    /* Her laver jeg en filpointer der peger på filen wing.txt og er i read tilstand. */
    file_pointer = fopen("wing.txt", "r");
    if (file_pointer != NULL){
        /* Her er en do-while løkke der ignorerer den første linje i dokumentet wing.txt. */
        do {
            ch = fgetc(file_pointer);
        } while (ch != '.');
        /* Her indlæses alle vingerne i deres structs. */
        for (i = 0; i < NUMBER_OF_WINGS; i++){
            fscanf(file_pointer, " %s - %d - %d - %d", array[i].name, &array[i].size, &array[i].productionCost, &array[i].salesPrice);
        }
    }
    /* Her prompter jeg brugeren for navnet på vingen, personen vil vide mere om. */
    printf("What type of name do you want to search for?\n");
    scanf(" %s", userInput);

    /* Her printer jeg kun den ene vinge, hvis navn matcher tekststrengen fra brugeren. */
    for (i = 0; i < NUMBER_OF_WINGS; i++){
        if (strcmp(array[i].name, userInput) == 0){
            printf("%s the wing you wanted to know about\n", userInput);
            printf("Is %d meters long, it costs %d DKK to make and is sold at %d DKK\n", array[i].size, array[i].productionCost, array[i].salesPrice);
        }
    }
    /* Her lukker jeg filpointeren. */
    fclose(file_pointer);
    return EXIT_SUCCESS;
}

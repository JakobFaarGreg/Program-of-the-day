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

char* prompt_for_name();
void print_name_list();

int main() {
    FILE *file_pointer;
    int i = 0;
    char *userInput, ch = '0';

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
    /* Her printer jeg en liste over de vinger jeg har i tekstdokumentet. */
    print_name_list();

    /* Her prompter jeg brugeren for navnet på vingen, personen vil vide mere om. */
    userInput = prompt_for_name();

    /* Her printer jeg kun den ene vinge, hvis navn matcher tekststrengen fra brugeren. */
    for (i = 0; i < NUMBER_OF_WINGS; i++){
        if (strcmp(array[i].name, userInput) == 0){
            printf("The wing you wanted to know about, %s,\n", userInput);
            printf("Is %d meters long, it costs %d DKK to make and is sold at %d DKK\n", array[i].size, array[i].productionCost, array[i].salesPrice);
        }
    }
    /* Her lukker jeg filpointeren. */
    fclose(file_pointer);
    return EXIT_SUCCESS;
}

void print_name_list(){
    int i = 0;
    printf("This is a list of Wing names: \n");
    for (i = 0; i < NUMBER_OF_WINGS; i++){
        printf("%s\n", array[i].name);
    }
}

char* prompt_for_name(){
    char *name;
    name = (char*) calloc(NUMBER_OF_WINGS, sizeof(char));
    printf("Type out the wing you want to know more about: \n");
    scanf(" %s", name);
    return name;
}

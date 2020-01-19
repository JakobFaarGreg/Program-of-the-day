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
void print_wing_information(char* userInput);
void load_wing_array_from_file(FILE* file);

int main() {
    FILE *file_pointer;
    char *userInput;

    /* Her laver jeg en filpointer der peger på filen wing.txt og er i read tilstand. */
    file_pointer = fopen("wing.txt", "r");
    load_wing_array_from_file(file_pointer);

    /* Her printer jeg en liste over de vinger jeg har i tekstdokumentet. */
    print_name_list();

    /* Her prompter jeg brugeren for navnet på vingen, personen vil vide mere om. */
    userInput = prompt_for_name();

    /* Her printer jeg kun den ene vinge, hvis navn matcher tekststrengen fra brugeren. */
    print_wing_information(userInput);

    /* Her lukker jeg filpointeren. */
    fclose(file_pointer);
    return EXIT_SUCCESS;
}

void load_wing_array_from_file(FILE* file){
    int i = 0;
    char ch = '0';
    if (file != NULL){
        /* Her er en do-while løkke der ignorerer den første linje i dokumentet wing.txt. */
        do {
            ch = fgetc(file);
        } while (ch != '.');
        /* Her indlæses alle vingerne i deres structs. */
        for (i = 0; i < NUMBER_OF_WINGS; i++){
            fscanf(file, " %s - %d - %d - %d", array[i].name, &array[i].size, &array[i].productionCost, &array[i].salesPrice);
        }
    }
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

void print_wing_information(char* userInput){
    int i = 0, notFound = 0;
    for (i = 0; i < NUMBER_OF_WINGS; i++){
        if (strcmp(array[i].name, userInput) == 0){
            printf("The wing you wanted to know about, %s,\n", userInput);
            printf("Is %d meters long, it costs %d DKK to make and is sold at %d DKK\n", array[i].size, array[i].productionCost, array[i].salesPrice);
        }
        else {
            notFound++;
        }
    }
    if (notFound == i){
        printf("Invalid name. Terminating program!\n");
        exit(EXIT_FAILURE);
    }
}

/* Dette program skal kunn bede om et navn på en vinge og give metermål samt produktionspris og salgspris. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 10
#define NUMBER_OF_WINGS 10

struct wing {
    char name[NAME_SIZE];
    int size,
        productionCost,
        salesPrice;
};
typedef struct wing wing;
wing array[NUMBER_OF_WINGS];

int main(){
    FILE* file_pointer = NULL;
    int i = 0;
    char userInput[NAME_SIZE], ch = 0;
    file_pointer = fopen("wing-doc.txt", "r");

    if (file_pointer != NULL){
        do {
            ch = fgetc(file_pointer);
        } while (ch != 'B');
        for (i = 0; i < NUMBER_OF_WINGS; i++){
            fscanf(file_pointer, "%s %d %d %d", array[i].name, &array[i].size, &array[i].productionCost, &array[i].salesPrice);
        }
    }
    printf("What type of name do you want to search for?\n");
    scanf("%s", userInput);

    for (i = 0; i < NUMBER_OF_WINGS; i++){
        if (strcmp(array[i].name, userInput) == 0)
            printf("%s the wing you wanted to know about\n", userInput);
            printf("Is %d meters long, it costs %d DKK to make and is sold at %d DKK\n", array[i].size, array[i].productionCost, array[i].salesPrice);
    }
    fclose(file_pointer);
    return EXIT_SUCCESS;
}

/* Dette program skal kunne sortere i en array af structs efter forskellige medlemmer/felter 
   P.t. sorterer det efter stoerrelse, kan også efter antal traeer og billetpris. */
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 20
#define NUMBER_OF_PARKS 10

struct park
{
    char    name[MAX_NAME_LENGTH];
    int     sizeOutOfTen,
            numberOfTrees,
            entryFee;
};
typedef struct park park;
park parklist[10];

int compare(const void *p1, const void *p2);

int main() {
    int i = 0;
    FILE *park_ptr;

    park_ptr = fopen("dag10.txt", "r");
    if (park_ptr != NULL) {
        for (i = 0; i < NUMBER_OF_PARKS; i++) {
            fscanf(park_ptr, " %s - %d - %d - %d", parklist[i].name, &parklist[i].sizeOutOfTen, &parklist[i].numberOfTrees, &parklist[i].entryFee);
        }
    }
    /* Her meddeler jeg om fejl ved initialisering af filpointer. */
    else {
        printf("File pointer initialization failed. ");
    }
    qsort(parklist, NUMBER_OF_PARKS, sizeof(park), compare);

    for (i = 0; i < NUMBER_OF_PARKS; i++){
        printf("The park: %s, is size %d out of 10 - it has got approx. this many trees: %d, and the entry fee is: %d\n", 
        parklist[i].name, parklist[i].sizeOutOfTen, parklist[i].numberOfTrees, parklist[i].entryFee);
    }

    fclose(park_ptr);
    return EXIT_SUCCESS;
}

/* Taget fra https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs */
int compare(const void *p1, const void *p2) {
    const struct park *elem1 = p1;    
    const struct park *elem2 = p2;
   if (elem1->sizeOutOfTen < elem2->sizeOutOfTen)
      return -1;
   else if (elem1->sizeOutOfTen > elem2->sizeOutOfTen)
      return 1;
   else
      return 0;
}

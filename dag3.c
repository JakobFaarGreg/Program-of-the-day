/* Dette program skal fylde et array med tal */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_LENGTH 10

int main(){
    int array[ARRAY_LENGTH], i = 0;
    srand(time(NULL));
    for (i = 0; i < ARRAY_LENGTH; i++){
        array[i] = rand() % 10;
    }
    for (i = 0; i < ARRAY_LENGTH; i++){
        if (i == 0)
            printf("Talraekkefoelgen er: ");
        printf("%d ", array[i]);
        if (i == ARRAY_LENGTH - 1)
            printf("\n");
    }
    return EXIT_SUCCESS;
}

/* Dette program skal finde et 'hus' i yatzy */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_die();
int is_house(int* array, int n);
int cmpfunc (const void * a, const void * b);

int main() {
    int *array;    
    int n = 0, i = 0;
    srand(time(NULL));
    printf("How many dice to roll:\n");
    scanf(" %d", &n);
    array = calloc(n, sizeof(int));
    if (array != NULL) {
        for (i = 0; i < n; i++) {
            array[i] = roll_die();
        }
    }
    qsort(array, n, sizeof(int), cmpfunc);

    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("You found a Full House = %d points", is_house(array, n));
    return EXIT_SUCCESS;
}

int roll_die() {
    return rand() % 6 + 1;
}

int is_house(int* array, int n) {
    int i = 0, treEns = 0, toEns = 0;
    i = n;
    while (i > 0 && toEns != 0) {
        if (array[i] == array[i-1] && array[i] == array[i-2]) {
            treEns = array[i];
            if ( array[i] == treEns) {
                i--;
            }
            else if (array[i] == array[i-1]) {
                toEns = array[i];
            }
        }
        else {
            i--;
        }
    }
    return ((treEns * 3)+(toEns * 2));
    /*  STUB  
    her skal der sammenlignes og findes den største værdi af et sæt tre ens.

    Så skal det højeste par, der ikke er samme værdi findes.
    
    Så skal de og pointene printes.
    */
} 

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}





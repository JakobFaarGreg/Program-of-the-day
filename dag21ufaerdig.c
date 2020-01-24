/* Dette program skal finde et hus i yatzy. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int roll_die(void);
int* create_array(int* n);
int is_house(int* array, int n);
int cmpfunc (const void * a, const void * b);

int main() {
    int n = 0, i = 0;
    int *array;
    srand(time(NULL));
    assert(n == 0);

    /* Her afleverer funktionen en int pointer til array. */
    array = create_array(&n);
    assert(array != NULL);
    
    /* Her sorterer jeg mit int array. */
    qsort(array, n, sizeof(int), cmpfunc);

    /* Her printer jeg indholdet af int arrayet. */
    for (i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    /* Her printer jeg en newline. */
    printf("\n");

    /* Her printer jeg antallet af point scoret af brugeren. */
    printf("You found a Full House = %d points\n", is_house(array, n));

    /* Her frigiver jeg pladsen på heapen som array optager. */
    free(array);
    return EXIT_SUCCESS;
}

int roll_die(void){
    return rand() % 6 + 1;
}

int* create_array(int* n){
    int i = 0, *array;
    printf("How many dice to roll:\n");
    scanf(" %d", n);
    array = calloc(*n, sizeof(int));
    if (array != NULL) {
        for (i = 0; i < *n; i++){
            array[i] = roll_die();
        }
    }
    return array;
}

int is_house(int* array, int n){
    int i = 0, j = 0, k = 0, treEns = 1, toEns = 1;
    i = n-1;
    j = n-2;
    k = n-3;
    do
    {
        if (array[i] == array[j] && array[i] == array[k]){
            treEns = array[i] * 3;
            i = 0;
        }
        else{
            i--;
            j--;
            k--;
        }
    } while (treEns != 0 || i != 0);
    i = n-1;
    j = n-2;
    do
    {
        if (array[i] == array[j] && array[i] != (treEns / 3)){
            toEns = array[i] * 3;
            i = 0;
        }
        else{
            i--;
            j--;
        }
    } while (toEns != 0 || i != 0);
    
   return treEns + toEns;
} 

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

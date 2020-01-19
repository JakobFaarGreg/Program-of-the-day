/* Dette program skal kunne modtage et antal tal og printe dem sorteret. */
#include <stdio.h>
#include <stdlib.h>
void prompt_for_n_in_array(int* n);
int* fill_array_with_n_numbers(int n);
int cmpfunc (const void * a, const void * b);

int main() {
    int *array, n = 0, i = 0;
    /* Here the user is prompted for the amount of numbers they want sorted. */
    prompt_for_n_in_array(&n);

    /* Here the user enters the numbers one by one. */
    array = fill_array_with_n_numbers(n);

    /* Here the array of unsorted numbers are sorted. */
    qsort(array, n, sizeof(int), cmpfunc);

    /* Here the array is printed one by one. */
    printf("Here are your sorted numbers: \n");
    for (i = 0; i < n; i++)
        printf("%d ",array[i]);

    return EXIT_SUCCESS;
}
void prompt_for_n_in_array(int* n){
    printf("How many numbers do you want sorted?\n");
    scanf(" %d", n);
}

int* fill_array_with_n_numbers(int n){
    int i = 0, *array;
    /* This is dynamic storage allocation of the array. */
    array = (int*) calloc(n, sizeof(int));
    printf("Pass me the %d numbers: ", n);
    /* This enters the numbers into the i' position. */
    for (i = 0; i < n; i++){
        scanf(" %d", &array[i]);
    } 
    return array;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

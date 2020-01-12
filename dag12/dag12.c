/* Dette program skal modtage input og sortere en liste efter det. */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 100
#define NUMBER_OF_SERIES 17

struct series{
    char    name[MAX_STRING_LENGTH],
            firstCategory[MAX_STRING_LENGTH],
            secondCategory[MAX_STRING_LENGTH];
};
typedef struct series series;
series array[NUMBER_OF_SERIES];

char* scan_search_term();
void ignore_first_line(FILE *file);
int compare(const void *a, const void *b);

int main(){
    FILE *dag12_ptr;
    int i = 0;
    char *searchTerm;

    searchTerm = scan_search_term();
    dag12_ptr = fopen("dag12.txt", "r+");
    if (dag12_ptr != NULL){
        ignore_first_line(dag12_ptr);
        for (i = 0; i < NUMBER_OF_SERIES; i++){
            fscanf(dag12_ptr, " %s - %s - %s", array[i].name, array[i].firstCategory, array[i].secondCategory);
        }
    } 
    /* Sorterer arrayet efter navn. */
    qsort(array, NUMBER_OF_SERIES, sizeof(series), compare);

    /* Her printer jeg mit array af structs. */
    for (i = 0; i < NUMBER_OF_SERIES; i++){
        printf("The Netflix series: %-12s Categories: %s and %s\n", array[i].name, array[i].firstCategory, array[i].secondCategory);
    } 
    /* Her husker jeg at lukke min filpointer igen. */
    fclose(dag12_ptr);
    return EXIT_SUCCESS;
}

char* scan_search_term(){
    char term[20], *string;
    int sizeOfString = 0;
    /* Indlaeser det soegeord der skal benyttes i sorteringen */
    printf("What category do you want to sort by:\nAnimation, Comedy, Courtroom, Crime, Detective, Drama, Drugs, " 
            "Family, Mockumentary, Superhero, Supernatural, Thriller?\n");
    scanf("%s", term);
    /* Udregner laengden på den string der skal allokeres */
    sizeOfString = sizeof(term) / sizeof(char);
    string = (char*) calloc(sizeOfString, sizeof(char));
    /* Her returnerer jeg en pointer til et array allokeret på heapen. */
    return string;
}
/* Denne funktion skal indlaese hvert tegn i filen indtil den når et punktum. */
void ignore_first_line(FILE *file){
    char ch = '0';
    do {
        ch = fgetc(file);
    } while(ch != '.');
}

/* Kopieret fra http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml */
int compare(const void *a, const void *b){ 
    series *ia = (series *)a;
    series *ib = (series *)b;
    return strcmp(ia->name, ib->name);
} 

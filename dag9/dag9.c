/* Dette program skal kunne hente et spil og dets vurdering ind, sortere det og */
#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH   50
#define MAX_NUMBER_GAMES   10

struct boardgame {
    int rating;
    char name[MAX_STRING_LENGTH];
};
typedef struct boardgame boardgame;
boardgame array[MAX_NUMBER_GAMES];

int compare(const void *p1, const void *p2);

int main() {
    int i = 0;
    /* Her opretter jeg en fil-pointer og peger den på den åbne fil dag9.txt i 'read'-mode. */
    FILE *boardgame_ptr;
    boardgame_ptr = fopen("dag9.txt", "r");

    /* Her tjekker jeg om filpointeren virker */
    if (boardgame_ptr != NULL) {
        for (i = 0; i < MAX_NUMBER_GAMES; i++) {
            /* Her indlæser jeg rating og navn af brætspillet i elementerne i det i'te boardgame i arrayet. */
            fscanf(boardgame_ptr, " %d - %s", &array[i].rating, array[i].name);
        }
    }
    /* Her sorterer jeg brætspillene så de kommer i rækkefølge. */
    qsort(array, 10, sizeof(boardgame), compare);

    /* Her printer jeg hvert brætspil enkeltvis. */
    for (i = 0; i < MAX_NUMBER_GAMES; i++){
        printf(" The game: %-13s I've given the rating: %d out of 10 \n", array[i].name, array[i].rating);
    }
    /* Og jeg husker at lukke filen igen. */
    fclose(boardgame_ptr);

    return EXIT_SUCCESS;
}

/* Taget fra https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs */
int compare(const void *p1, const void *p2) {
    const struct boardgame *elem1 = p1;    
    const struct boardgame *elem2 = p2;
   if (elem1->rating < elem2->rating)
      return -1;
   else if (elem1->rating > elem2->rating)
      return 1;
   else
      return 0;
}

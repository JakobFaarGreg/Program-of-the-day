/* Dette program skal kunne hente et spil og dets vurdering ind, sortere det og */
#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH   50
#define MAX_NUMBER_GAMES   10

struct boardgame {
    int rating;
    char *name;
};
typedef struct boardgame boardgame;
boardgame array[MAX_NUMBER_GAMES];

int main() {
    int i = 0;
    FILE *boardgame_ptr;
    char boardgame_str[MAX_STRING_LENGTH], ch[3];;

    boardgame_ptr = fopen("dag9.txt", "r");

    if (boardgame_ptr != NULL) {
        for (i = 0; i < MAX_NUMBER_GAMES; i++) {
            fgets(boardgame_str, MAX_STRING_LENGTH, boardgame_ptr);
            printf("%s\n", boardgame_str);
            fscanf(boardgame_ptr, "%d %[^QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm] %s;", &array[i].rating, ch, array[i].name);
        }
    }
    /*
    for (i = 0; i < MAX_NUMBER_GAMES; i++){
        printf(" The game: '%s' I've given the rating: %d \n", array[i].name, array[i].rating);
    }*/
    fclose(boardgame_ptr);
    return EXIT_SUCCESS;
}

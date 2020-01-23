/* Dette skal kompileres med en makefil */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funktion1.h"
#include "funktion2.h"

int main() {
    int i = 0;
    char *string;
    
    /* Her seedes der. */
    srand(time(NULL));

    /* Her printer jeg med funktion fra headerfil "funktion1.h" */
    for (i = 0; i < 10; i++)
        printf("%d ", roll_die());
    printf("\n");

    /* Her indlaeser jeg en tekststreng med funktion fra headerfil "funktion2.h" */
    string = scan_input();
    printf("%s\n", string);
    return EXIT_SUCCESS;
}

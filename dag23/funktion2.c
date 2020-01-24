#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_SIZE 100

/* Funktionsdefinition
   Denne funktion indlaeser en tekststreng med whitespaces indtil den moeder et newline tegn. */
char* scan_input() {
    char ch = 0, *string;
    int i = 0;
    /* Dynamisk lagerallokering fordi statisk lagerallokering ville returnere en 
    plads der afvikles når funktionen fjernes fra stakken */
    string = (char*) calloc(MAX_STRING_SIZE, sizeof(char));
    printf("Input text here: (terminate with #)\n");
    /* Benytter while-løkke fordi jeg ikke ved hvor mange iterationer den skal køre. 
    Benytter getchar() i stedet for scanf() fordi getchar også indlaeser whitespaces. */
    while ((ch = getchar()) != '\n') {
        string[i] = ch;
        i++;
    }
    return string;
}

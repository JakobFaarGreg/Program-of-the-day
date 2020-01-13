#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 100

int main(){
    char string1[STRING_LENGTH], string2[STRING_LENGTH];

    printf("Please enter a text string:\n");
    scanf("%s", string1);

    /* This copies the latter text string (ie. string1), into the first string (ie. string2) */
    strcpy(string2, string1);

    /* This concatenates the character array on the first string (string2) */
    strcat(string2, " This text is concatenated");

    /* This prints the entire string */
    printf("%s\n",string2);

    return EXIT_SUCCESS;
}

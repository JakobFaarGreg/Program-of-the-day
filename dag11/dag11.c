#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 100

int is_file_empty(FILE *file);

int main() {
    FILE *dag11_ptr;
    char input_string[MAX_STRING_LENGTH];
    int yesNo = 0;

    dag11_ptr = fopen("dag11.txt", "w");
    if (dag11_ptr != NULL) {
        if (is_file_empty(dag11_ptr)) {
            printf("Type out what to add to file 'dag11.txt:\n");
            scanf("%s", input_string);
            fputs(input_string, dag11_ptr);
        }
        else {
            printf("Do you want to write to this non-empty file? yes=1\n");
            scanf(" %d", &yesNo);

            if (yesNo == 1) {
                scanf(" %s", input_string);
                fputs(input_string, dag11_ptr);
            }
            else {
                EXIT_FAILURE;
            }
        }
        scanf(" %s", input_string);
        fputs(input_string, dag11_ptr);
    }
    printf("Did it work?\n");


    fclose(dag11_ptr);
    return EXIT_SUCCESS;
}

/* Checks whether the setup file exists or not (and if it exists, checks if it's empty) */
int is_file_empty(FILE *file) {
    /* Check if file is empty */
    int file_size;

    /* Set the file cursor position to the end of the file and read file size in bytes */
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);

    if (file_size == 0) {
        /* File exists, but is empty - also reset the cursor to the start of the file */
        fseek(file, 0, SEEK_SET);
        return 1;
    }

    /* File is not empty - also reset the cursor to the start of the file */
    fseek(file, 0, SEEK_SET);
    return 0;
}

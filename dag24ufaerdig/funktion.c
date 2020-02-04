#include <stdio.h>
#include <stdlib.h>
#define MAX_NO_OF_STRUCTS 6
#define NAME_LENGTH 10

struct person {
    char name[NAME_LENGTH];
    int heigth, age;
};
typedef struct person person;
person array[MAX_NO_OF_STRUCTS];

person* generate_pointer() {
    int i = 0;
    FILE* fp;
    fp = fopen("tekstfil.txt", "r");
    if (fp != NULL) {
        for (i = 0; i < MAX_NO_OF_STRUCTS; i++) {
            fscanf(fp, " %s - %d - %d", array[i].name, &array[i].heigth, &array[i].age);
        }
    }
    return array;
}

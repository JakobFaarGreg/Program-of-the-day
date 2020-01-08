/* Skal kunne sortere personer efter alder. */
#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX_LENGTH 10

int cmpfunc (const void * a, const void * b);

struct person {
    int age;
    char name[NAME_MAX_LENGTH];
};
typedef struct person person;

int main() {
    person  p1 = {23, "Jakob"},
            p2 = {51, "Lis"},
            p3 = {49, "Morten"},
            p4 = {25, "Kristine"};
    printf(" %d - %s\n", p1.age, p1.name);
    printf(" %d - %s\n", p2.age, p2.name);
    printf(" %d - %s\n", p3.age, p3.name);
    printf(" %d - %s\n", p4.age, p4.name);

    for (i = 0; i < 4; i++) {
        printf(" %d - %s\n", p1.age, p1.name);
    }

    return EXIT_SUCCESS;
}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

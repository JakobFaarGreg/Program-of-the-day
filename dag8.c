/* Skal kunne sortere personer efter alder. */
#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX_LENGTH 10

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

    return EXIT_SUCCESS;
}

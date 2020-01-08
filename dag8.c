/* Skal kunne sortere personer efter alder. */
#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX_LENGTH 10

int compare(const void *p1, const void *p2);

struct person {
    int age;
    char *name;
};
typedef struct person person;
person List[4];

int main() {
    int i = 0;
    person  p1 = {23, "Jakob"},
            p2 = {51, "Lis"},
            p3 = {49, "Morten"},
            p4 = {25, "Kristine"};
    List[0] = p1;
    List[1] = p2;
    List[2] = p3;
    List[3] = p4;
    printf("Before sorting: \n");
    for (i = 0; i < 4; i++) {
        printf(" %d - %s\n", List[i].age, List[i].name);
    }
    /* kald af sorteringsfunktion qsort på struct */
    qsort(List, 4, sizeof(person), compare);

    printf("\nAfter sorting: \n");
    for (i = 0; i < 4; i++) {
        printf(" %d - %s\n", List[i].age, List[i].name);
    }
    return EXIT_SUCCESS;
}
/* Taget fra https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs */
int compare(const void *p1, const void *p2) {
    const struct person *elem1 = p1;    
    const struct person *elem2 = p2;

   if (elem1->age < elem2->age)
      return -1;
   else if (elem1->age > elem2->age)
      return 1;
   else
      return 0;
}

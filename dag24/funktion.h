#define MAX_NO_OF_STRUCTS 6
#define NAME_LENGTH 10

struct person {
    char name[NAME_LENGTH];
    int heigth, age;
};
typedef struct person person;
person array[MAX_NO_OF_STRUCTS];

person* generate_pointer();

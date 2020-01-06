/* Dette program skal kunne laegge et korthus */
#include <stdio.h>
#include <stdlib.h>
void print_venstre();
void print_hoejre();
void print_foerste_niveau();
void print_2_venstre();
void print_2_hoejre();
void print_andet_niveau();
void print_3_venstre();
void print_3_hoejre();
void print_tredje_niveau();

int main(){
    system("clear");
    printf("Nu skal du bygge et korthus, det hele på en gang.\n\n");
    print_tredje_niveau();
    print_andet_niveau();
    print_foerste_niveau();

    return 0; 
}

void print_venstre(){
    printf("/");
}
void print_hoejre(){
    printf("\\");
}
void print_foerste_niveau(){
    int i = 0;
    for(i = 0; i < 3; i++){
        print_venstre();
        print_hoejre();
    }
    printf("\n\n\nGodt gjort.\n");
}
void print_2_venstre(){
    printf(" /");
}
void print_2_hoejre(){
    printf("\\ ");
}
void print_andet_niveau(){
    print_2_venstre();
    print_hoejre();
    print_venstre();
    print_2_hoejre();
    printf("\n");
}
void print_3_venstre(){
    printf("  /");
}
void print_3_hoejre(){
    printf("\\  ");
}
void print_tredje_niveau(){
    printf("  /");
    printf("\\  ");
    printf("\n");
}

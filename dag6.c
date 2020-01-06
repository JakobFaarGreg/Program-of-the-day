/* Dette program skal kunne laegge et korthus, eet kort ad gangen. */
#include <stdio.h>
#include <stdlib.h>
void print_left();
void print_right();
void print_bottom_level();
void print_1_left();
void print_1_right();
void print_first_level();
void print_2_left();
void print_2_right();
void print_second_level();

int main(){
    int /* fallenDown = 1, cardCount = 0,*/ i = 0; 
    
    for(i = 0; i < 12; i++){
        if (i >= 10) {
            if (i == 11) {
                print_second_level();
                print_first_level();
                print_bottom_level();
                printf("SUCCESS SUCCESS SUCCESS!!! GREAT JOB!!!");
            }
            else {
                print_2_left();
                print_first_level();
                print_bottom_level();
                printf("Only one more left!");
            }
        }
        else if (i >= 6) {
            int j = 0;
            for (j = 6; j < i; j++) {  
                if (j == 9) {
                    print_1_right();
                }
                else if (j == 6) {
                    print_1_left();
                }
                else if (j == )
            }




            print_bottom_level();
        }
    }  
    return EXIT_SUCCESS; 
}

void print_left(){
    printf("/");
}
void print_right(){
    printf("\\");
}
void print_bottom_level(){
    int i = 0;
    printf("\n");
    for(i = 0; i < 3; i++){
        print_left();
        print_right();
    }
    printf("\n\n\nGodt gjort.\n");
}
void print_1_left(){
    printf(" /");
}
void print_1_right(){
    printf("\\ ");
}
void print_first_level(){
    printf("\n");
    print_1_left();
    print_right();
    print_left();
    print_1_right();
}
void print_2_left(){
    printf("  /");
}
void print_2_right(){
    printf("\\  ");
}
void print_second_level(){
    printf("\n");
    printf("  /");
    printf("\\  ");
}

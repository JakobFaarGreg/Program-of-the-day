/* Dette program skal kunne laegge et korthus, eet kort ad gangen. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_left();
void print_right();
void print_bottom_level();
void print_1_left();
void print_1_right();
void print_first_level();
void print_2_left();
void print_2_right();
void print_second_level();
/* void print_failure(); */

int main(){
    int i = 0; 
    char goAgain = 0; 
    srand(time(NULL));
    for(i = 0; i <= 12; i++){
        system("clear");
        if (i >= 10) {
            if (i == 12) {
                print_second_level();
                print_first_level();
                print_bottom_level();
                printf("You succesfully stacked a card house! GREAT JOB!!!\n\n\n\n");
            }
            else if (i == 11) {
                print_2_left();
                print_first_level();
                print_bottom_level();
                printf("Only one more left!");
            }
            else {
                print_first_level();
                print_bottom_level();
            }
        }
        else if (i >= 6) {
            int j = 0;
            printf("\n");
            for (j = 6; j < i; j++) {  
                if (j == 9) {
                    print_1_right();
                }
                else if (j == 6) {
                    print_1_left();
                }
                else if (j == 7) {
                    print_right();
                }
                else {
                    print_left();
                }
            }
            print_bottom_level();
        }
        else if (i < 6) {
            int k = 0;
            printf("\n\n");
            for (k = 0; k < i; k++) {
                if (k % 2 == 0) {
                    print_left();
                }
                else {
                    print_right();
                }
            }
            printf("\n\n");
        }
        if (i != 12) {
            printf("Press any key to place next card: \n");
            scanf(" %c", &goAgain);
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
    printf("\n\n");
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
    printf("  /");
    printf("\\  ");
}
/* void print_failure(){
    printf("     \\    /  \\    /  \\    /  \\    /  \\    /  \n");
    printf("      \\  /    \\  /    \\  /    \\  /    \\  /    \n");
    printf("       \\/      \\/      \\/      \\/      \\/      \n");
    printf("       /\\      /\\      /\\      /\\      /\\        You lost, the card house has toppled... \n");
    printf("      /  \\    /  \\    /  \\    /  \\    /  \\    \n");
    printf("     /    \\  /    \\  /    \\  /    \\  /    \\  \n");
    printf("    /      \\/      \\/      \\/      \\/      \\\n");
} */

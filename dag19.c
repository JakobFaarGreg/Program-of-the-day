/* Dette program skal kunne simulere en fisketur. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fish(int time);
int cast_fishing_rod();
void press_any_key();
int what_fish();

int main() {
    int tripTime = 0;
    srand(time(NULL));
    printf("For how long do you want to fish?\n");
    scanf(" %d", &tripTime);

    fish(tripTime);

    return EXIT_SUCCESS;
}

void fish(int time) {
    int i = 0;
    for (i = 0; i < time; i++) {
        press_any_key();
        if (cast_fishing_rod() < 10) {
            printf("WOW! YOU CAUGHT A FISH!\n");
            if (what_fish() == 10) {
                printf("It is a mighty Tuna!\n");
            }
            else if(what_fish() > 8) {
                printf("It is a big Salmon!\n");
            }
            else if(what_fish() > 5) {
                printf("It is a Herring\n");
            }
            else if(what_fish() > 3) {
                printf("What? There is a Shrimp on your hook\n");
            }
            else if(what_fish() <= 3) {
                printf("You caught some seaweed, it is worthless\n");
            }
        }
        else if (cast_fishing_rod() > 10) {
            printf("No bite, cast again. (press any key)\n");
        }
    }
}

int cast_fishing_rod() {
    return rand() % 100;
}

void press_any_key() {
    getc(stdin);
}

int what_fish(){
    return rand() % 10 + 1;
}

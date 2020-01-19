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
    /* Her prompter programmet for antal timer. */
    printf("For how many hours do you want to fish?\n");
    scanf(" %d", &tripTime);

    /* Denne funktion indholder fisketuren. */
    fish(tripTime);

    return EXIT_SUCCESS;
}

void fish(int time) {
    int i = 0;
    printf("Press any key to fish:\n");
    press_any_key();
    for (i = 0; i < time; i++) {
        /* Denne funktion venter på input fra tastaturet. */
        press_any_key();
        /* Denne kontrolstruktur tjekker om der er fangst. */
        if (cast_fishing_rod() < 10) {
            printf("WOW! YOU CAUGHT A FISH!\n");
            /* Denne kontrolstruktur tjekker hvad fangsten er. */
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
        /* Denne gren printer at der ikke er fangst. */
        else if (cast_fishing_rod() > 10) {
            printf("No bite, cast again.\n");
        }
    }
}

int cast_fishing_rod() {
    return rand() % 100;
}

void press_any_key() {
    getc(stdin);
    fflush(stdin);
}

int what_fish(){
    return rand() % 10 + 1;
}

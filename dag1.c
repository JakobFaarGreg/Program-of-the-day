/* Der skal rulles for intiative, angreb og potentielt skade */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ENEMY_ARMOR_CLASS 15
#define ATTACK_MODIFIER 5
#define DEXTERITY_MODIFIER 2
#define PROFICIENCY 2
void combat();
void initiative();
int to_hit();
void damage_calc();
int roll_dice_size(int size);
int roll_great_sword();


int main() {
    srand(time(NULL));
    combat();
    return EXIT_SUCCESS;
}

void combat() {
    int effort = 0;
    initiative();
    effort = to_hit();
    if (effort > ENEMY_ARMOR_CLASS) {
        damage_calc();
    }
    else {
        printf("You missed.\n");
    }
}

void initiative() {
    int initiative = 0;
    initiative = roll_dice_size(20) + DEXTERITY_MODIFIER;
    printf("\nYour initiative roll is = %d\n", initiative);
}

int to_hit() {
    int effort = 0;
    effort = roll_dice_size(20) + ATTACK_MODIFIER + PROFICIENCY;
    printf("%d to hit! \n", effort);
    return effort;
}

void damage_calc() {
    int damage = 0;
    damage = roll_great_sword() + ATTACK_MODIFIER + PROFICIENCY;
    printf("You do %d points of damage to the creature\n\n", damage);
}

int roll_dice_size(int size) {
    int diceRoll = 0;
    diceRoll = (rand() % size);
    return diceRoll;
}

int roll_great_sword() {
    int damage = 0;
    damage = (roll_dice_size(6) + roll_dice_size(6));
    return damage;
}

/* Dette program skal være en nip-napper */
#include <stdio.h>
#include <stdlib.h>
void number_choice(int playerChoice);
char* color_choice(char playerChoice[]);
void end_choice(int endChoice);

int main(){
    int playerChoice = 0, endChoice = 0;
    char* colorChoice[6];

    number_choice(playerChoice);
    *colorChoice = color_choice(*colorChoice);

    end_choice(endChoice);
    return EXIT_SUCCESS;
}
char* color_choice(char colorChoice[]){
    printf("hvilken farve?\nRoed, Groen, Blaa, Lilla\n");
    scanf(" %s", colorChoice);
    return colorChoice;
}

void number_choice(int playerChoice){
    printf("Et tal mellem 1 og 8:\n");
    scanf(" %d",&playerChoice);
}

void end_choice(int endChoice){
    switch (endChoice)
    {
    case 1: printf("Du er 16 aar gammel"); break;
    case 2: printf("Du er nu stjernetegnet Krebsen"); break;
    case 3: printf("Du er nu en Hollywood celebrity"); break;
    case 4: printf("Du burde gaa til laegen"); break;
    case 5: printf("Du har mistet al din charme"); break;
    case 6: printf("Du kunne traenge til ferie"); break;
    case 7: printf("Du faar snart et opkald fra banken"); break;
    case 8: printf("Du mangler hvide t-shirts med print"); break;
    default: break;
    }
}

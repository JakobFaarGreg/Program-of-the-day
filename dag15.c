/* Dette program skal kunne udregne pris på en rejse */
#include <stdio.h>
#include <stdlib.h>
#define KM_PRICE 1.75 
void prompt_info(int* travelLength, int* discountLevel);
int calculate_price(int travelLength, int discountLevel);

int main(){
    int travelLength = 0, discountLevel = 0;

    prompt_info(&travelLength, &discountLevel);

    printf("Your price is = %d DKK\n", calculate_price(travelLength, discountLevel));
    
    return EXIT_SUCCESS;
}

void prompt_info(int* travelLength, int* discountLevel){
    printf("To calculate your ticket price, this program needs:\n");
    printf("Your length of travel: ");
    scanf(" %d", travelLength);
    printf("and your discount level: ");
    scanf(" %d", discountLevel);
}

int calculate_price(int travelLength, int discountLevel){
    return travelLength * (KM_PRICE - (discountLevel* 0.05));
}

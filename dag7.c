/* Put a deck of cards in numerical order, high to low */
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b);

struct kort
{
    int number; 
    char suit[4];
};
typedef struct kort kort;

int main() {
    int i = 0;
    kort    joker1 =  {25,  "N/A"},
        joker2 =  {25,  "N/A"},
        joker3 =  {25,  "N/A"},
        HJack  =  {11,  "H"},
        HQueen =  {12,  "H"},
        HKing  =  {13,  "H"},
        HAce   =  {14,  "H"},
        DJack  =  {11,  "D"},
        DQueen =  {12,  "D"},
        DKing  =  {13,  "D"},
        DAce   =  {14,  "D"},
        CJack  =  {11,  "C"},
        CQueen =  {12,  "C"},
        CKing  =  {13,  "C"},
        CAce   =  {14,  "C"},
        SJack  =  {11,  "S"},
        SQueen =  {12,  "S"},
        SKing  =  {13,  "S"},
        SAce   =  {14,  "S"},
        Htwo = {2, "H"},
        Hthree = {3, "H"},
        Hfour = {4, "H"},
        Hfive = {5, "H"},
        Hsix = {6, "H"},
        Hseven = {7, "H"},
        Height = {8, "H"},
        Hnine = {9, "H"},
        Hten = {10, "H"},
        Dtwo = {2, "D"},
        Dthree = {3, "D"},
        Dfour = {4, "D"},
        Dfive = {5, "D"},
        Dsix = {6, "D"},
        Dseven = {7, "D"},
        Deight = {8, "D"},
        Dnine = {9, "D"},
        Dten = {10, "D"},
        Ctwo = {2, "C"},
        Cthree = {3, "C"},
        Cfour = {4, "C"},
        Cfive = {5, "C"},
        Csix = {6, "C"},
        Cseven = {7, "C"},
        Ceight = {8, "C"},
        Cnine = {9, "C"},
        Cten = {10, "C"},
        Stwo = {2, "S"},
        Sthree = {3, "S"},
        Sfour = {4, "S"},
        Sfive = {5, "S"},
        Ssix = {6, "S"},
        Sseven = {7, "S"},
        Seight = {8, "S"},
        Snine = {9, "S"},
        Sten = {10, "S"};

    kort arr[55];
    arr[0] = joker1;
    arr[1] = joker2;
    arr[2] = joker3;
    arr[3] = HJack;
    arr[4] = HQueen;
    arr[5] = HKing;
    arr[6] = HAce;
    arr[7] = DJack;
    arr[8] = DQueen;
    arr[9] = DKing;
    arr[10] = DAce;
    arr[11] = CJack;
    arr[12] = CQueen;
    arr[13] = CKing;
    arr[14] = CAce;
    arr[15] = SJack;
    arr[16] = SQueen;
    arr[17] = SKing;
    arr[18] = SAce;
    arr[19]   = Htwo;
    arr[20]   = Hthree;
    arr[21]   = Hfour;
    arr[22]   = Hfive;
    arr[23]   = Hsix;
    arr[24]   = Hseven;
    arr[25]   = Height;
    arr[26]   = Hnine;
    arr[27]   = Hten;
    arr[28]   = Dtwo;
    arr[29]   = Dthree;
    arr[30]   = Dfour;
    arr[31]   = Dfive;
    arr[32]   = Dsix;
    arr[33]   = Dseven;
    arr[34]   = Deight;
    arr[35]   = Dnine;
    arr[36]   = Dten;
    arr[37]   = Ctwo;
    arr[38]   = Cthree;
    arr[39]   = Cfour;
    arr[40]   = Cfive;
    arr[41]   = Csix;
    arr[42]   = Cseven;
    arr[43]   = Ceight;
    arr[44]   = Cnine;
    arr[45]   = Cten;
    arr[46]   = Stwo;
    arr[47]   = Sthree;
    arr[48]   = Sfour;
    arr[49]   = Sfive;
    arr[50]   = Ssix;
    arr[51]   = Sseven;
    arr[52]   = Seight;
    arr[53]   = Snine;
    arr[54]   = Sten;
    qsort(arr.number, 54, sizeof(int), cmpfunc);


    for (i = 0; i < 55; i++) {
        printf("%d is a %s \n", arr[i].number, arr[i].suit);
    }
    return EXIT_SUCCESS;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

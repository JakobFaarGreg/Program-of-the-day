/* Put a deck of cards in numerical order */
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b);

/* Struct der indeholder et enkelt kort. */
struct kort {
    int number; 
    char suit[4];
};
typedef struct kort kort;
/* Den liste der skal være mit kortspil. */
kort kortspil[55];

int main() {
    int i = 0;
/* Kæmpe initialisering af kortspillet */
    kort    joker1 =  {25,  "N/A"}, joker2 =  {25,  "N/A"}, joker3 =  {25,  "N/A"},
            HJack  =  {11,  "H"}, HQueen =  {12,  "H"}, HKing  =  {13,  "H"}, HAce   =  {14,  "H"},
            DJack  =  {11,  "D"}, DQueen =  {12,  "D"}, DKing  =  {13,  "D"}, DAce   =  {14,  "D"},
            CJack  =  {11,  "C"}, CQueen =  {12,  "C"}, CKing  =  {13,  "C"}, CAce   =  {14,  "C"},
            SJack  =  {11,  "S"}, SQueen =  {12,  "S"}, SKing  =  {13,  "S"}, SAce   =  {14,  "S"},
            Htwo = {2, "H"}, Hthree = {3, "H"}, Hfour   = {4, "H"}, Hfive = {5, "H"},
            Hsix = {6, "H"}, Hseven = {7, "H"}, Height  = {8, "H"}, Hnine = {9, "H"}, Hten = {10, "H"},
            Dtwo = {2, "D"}, Dthree = {3, "D"}, Dfour   = {4, "D"}, Dfive = {5, "D"},
            Dsix = {6, "D"}, Dseven = {7, "D"}, Deight  = {8, "D"}, Dnine = {9, "D"}, Dten = {10, "D"},
            Ctwo = {2, "C"}, Cthree = {3, "C"}, Cfour   = {4, "C"}, Cfive = {5, "C"},
            Csix = {6, "C"}, Cseven = {7, "C"}, Ceight  = {8, "C"}, Cnine = {9, "C"}, Cten = {10, "C"},
            Stwo = {2, "S"}, Sthree = {3, "S"}, Sfour   = {4, "S"}, Sfive = {5, "S"},
            Ssix = {6, "S"}, Sseven = {7, "S"}, Seight  = {8, "S"}, Snine = {9, "S"}, Sten = {10, "S"};
/* Enormt dum måde at initialisere kortspillet på.. Men det er kun denne måde jeg forstår mig på.s */
    kort kortspil[55];
    kortspil[0] = joker1;   kortspil[1]  = joker2;  kortspil[2]  = joker3;     kortspil[3]  = HJack;    kortspil[4]  = HQueen; kortspil[5] = HKing;
    kortspil[6] = HAce;     kortspil[7]  = DJack;   kortspil[8]  = DQueen;     kortspil[9]  = DKing;    kortspil[10] = DAce;
    kortspil[11] = CJack;   kortspil[12] = CQueen;  kortspil[13] = CKing;      kortspil[14] = CAce;     kortspil[15] = SJack;
    kortspil[16] = SQueen;  kortspil[17] = SKing;   kortspil[18] = SAce;       kortspil[19] = Htwo;     kortspil[20] = Hthree;
    kortspil[21] = Hfour;   kortspil[22] = Hfive;   kortspil[23] = Hsix;       kortspil[24] = Hseven;   kortspil[25] = Height;
    kortspil[26] = Hnine;   kortspil[27] = Hten;    kortspil[28] = Dtwo;       kortspil[29] = Dthree;   kortspil[30] = Dfour;
    kortspil[31] = Dfive;   kortspil[32] = Dsix;    kortspil[33] = Dseven;     kortspil[34] = Deight;   kortspil[35] = Dnine;
    kortspil[36] = Dten;    kortspil[37] = Ctwo;    kortspil[38] = Cthree;     kortspil[39] = Cfour;    kortspil[40] = Cfive;
    kortspil[41] = Csix;    kortspil[42] = Cseven;  kortspil[43] = Ceight;     kortspil[44] = Cnine;    kortspil[45] = Cten;
    kortspil[46] = Stwo;    kortspil[47] = Sthree;  kortspil[48] = Sfour;      kortspil[49] = Sfive;    kortspil[50] = Ssix;
    kortspil[51] = Sseven;  kortspil[52] = Seight;  kortspil[53] = Snine;      kortspil[54] = Sten;
    qsort(kortspil, 55, sizeof(kort), cmpfunc);

    for (i = 0; i < 55; i++) {
        printf("|| %2d is a %-3s ", kortspil[i].number, kortspil[i].suit);
        if (i % 4 == 0 && i != 0) {
            printf("\n");
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

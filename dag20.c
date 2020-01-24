/* Denne funktion skal have en egentlig benyttelse af rekursion. */
#include <stdio.h>
#include <stdlib.h>
int recur_func(int n);
int main() {
    int n = 0;
    printf("Enter an integer:\n");
    scanf(" %d",&n);
    system("clear");
    recur_func(n);
    printf("\n");
    return EXIT_SUCCESS;
}

int recur_func(int n){
    if (n == 1) {
        return 1;
    }
    else if (n == 10){
        printf("Phew, still a long way to go..\n");
        printf("%d ",n);
        return 1 + (recur_func(n-1));
    }
    else if (n == 30) {
        printf("Wow, you went pretty high.\n");
        printf("%d ",n);
        return 1 + (recur_func(n-1));
    }
    else {
        printf("%d ",n);
        return 1 + (recur_func(n-1));
    }
}

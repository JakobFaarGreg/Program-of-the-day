/* Dette program skal lave rekursion. */
#include <stdio.h>
#include <stdlib.h>
int calculate(int n);

int main() {
    int n = 0;
    printf("Pass me an even integer:\n");
    scanf("%d", &n);
    printf("The value of this calculation is = %d\n", calculate(n));

    return EXIT_SUCCESS;
}

int calculate(int n) {
    if (n == 2)
        return 1;
    return n + calculate(n-2);
}

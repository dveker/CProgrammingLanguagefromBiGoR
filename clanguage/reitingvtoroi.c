#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int numerator, denominator;
    printf("числитель: ");
    while(scanf("%d", &numerator) != 1) {
        while(getchar() != '\n');
        printf("error try again \n");
        printf("%d", numerator);
        return 1;
    }
    printf("числитель: ");
    while(scanf("%d", &denominator) != 1) {
        while(getchar() != '\n');
        printf("error try again \n");
        printf("%d", denominator);
        return 1;
    }
    if (denominator == 0) {
        printf("\n"); 
        return 1;
    }
    int commonDivisor = gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;
    printf("сщкрашение дроби: %d/%d\n", numerator, denominator);
    return 0;
}



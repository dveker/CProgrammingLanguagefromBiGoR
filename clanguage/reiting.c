#include <stdio.h>
#include <ctype.h>
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
    if (scanf("%d", &numerator) != 1) {
        printf("error\n");
        return 1;
    }
    printf("знаменатель: ");
    if (scanf("%d", &denominator) != 1) {
        printf("error\n");
        return 1;
    }
    if (denominator == 0) {
        printf("\n"); 
        return 1;
    }
    if (!isdigit(numerator) || !isdigit(denominator)) {
        printf("разрешены числа только 0 до 9 \n");
        return 1;
    }
    int commonDivisor = gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;
    printf("сщкрашение дроби: %d/%d\n", numerator, denominator);
    return 0;
}
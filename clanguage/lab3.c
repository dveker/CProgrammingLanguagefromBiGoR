#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c;
    double descriminant, x1n, x2n; 
    printf("a: ");
    if (scanf("%f", &a) != 1) {
        printf("error");
        return 1;
    }
    printf("b: ");
    if (scanf("%f", &b) != 1) {
        printf("error");
        return 1;
    }
    printf("c: ");
    if (scanf("%f", &c) != 1) {
        printf("error");
        return 1;
    }
    descriminant = b * b - 4 * a * c;
    if (descriminant > 0) {
        x1n = (-b + sqrt(descriminant)) / (2 * a);
        x2n = (-b - sqrt(descriminant)) / (2 * a);
        printf("x1 , x2", x1n, x2n);
    } else if (descriminant == 0) {
        x1n = -b / (2 * a);
        printf("x1" , x1n);
    } else {
        double realpart = -b / (2 * a);
        double imaginarypart = sqrt(-descriminant) / (2 * b);
        printf("x1 , x2 , only one root x1", realpart, imaginarypart, realpart, imaginarypart);
    }
    return 0;
}


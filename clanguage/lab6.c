#include <stdio.h>
#include <math.h>
void convertIntergerPart(int decimalNumber, int base) {
    int remainder;
    if (decimalNumber == 0) {
        return;
    }
    remainder = decimalNumber % base;
    convertIntergerPart(decimalNumber / base, base);
    printf("%c", (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A'));
}
void convertFractionalPart(double fractionalPart, int base, int precision) {
    int i;
    printf(".");
    for (i = 0; i < precision; i++) {
        fractionalPart *= base;
        int digit = (int)fractionalPart;
        printf("%c", (digit < 10) ? (digit + '0') : (digit - 10 + 'A'));
        fractionalPart -= digit;
    }
}
int main() {
    int base;
    double decimalNumber;
    int integerPart;
    double fractionalPart;
    int precision;
    printf("provide number");
    if (scanf("%lf", &decimalNumber) !=1) {
        printf("error \n");
        return 1;
    }
    printf("provide number from 2 to 16: ");
    if (scanf("%d", &base) != 1 || base < 2 || base > 16) {
        printf("error \n");
        return 1;
    }
    printf("provide the ammount of simmbles: ");
    if (scanf("%d", &precision) != 1 || precision < 0) {
        printf("error \n");
        return 1;
    }
    integerPart = (int)decimalNumber;
    fractionalPart = decimalNumber - integerPart;
    if (integerPart == 0) {
        printf("0");
    } else {
        convertIntergerPart(integerPart, base);
    }
    if (fractionalPart > 0) {
        convertFractionalPart(fractionalPart, base, precision);
    }
    printf("\n");
    return 0;
}


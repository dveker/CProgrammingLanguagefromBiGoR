#include <stdio.h>

int main() {
    int age;
    do {
        printf("wrhite year of birght 1 - 100: ");
        scanf("%d", &age);
        if (age < 1 || age > 100) {
            printf("error");
        }
    } while (age < 1 || age > 100);
    if (age == 1 || age % 10 == 1) {
        printf("you are %d year \n", age);
    } else {
        printf("you are %d years \n", age);
    }
    if (age < 18) {
        printf("%d", 18 - age);
    } else {
        printf("%d", age - 18);
    }
    if (age < 60) {
        printf("%d", 60 - age);
    } else {
        printf("%d", age - 60);
    }
    return 0;
}
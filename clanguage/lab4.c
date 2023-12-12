#include <stdio.h>
#include <math.h>
double finbonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    double a = 1, b = 1, c;
    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int n = 2;
    double epsilon = 0.0001;
    double prevRatio = 1;
    double ratio = finbonacci(n) / finbonacci(n - 1);
    while (fabs(ratio - prevRatio) > epsilon) {
        prevRatio = ratio;
        n++;
        ratio = finbonacci(n) / finbonacci(n - 1);
    }
    printf("limit betwen the two numbers is %lf: %lf\n", epsilon, ratio);
}
#include <stdio.h>
#include <math.h>
double f(double x) {
    return sin(x) - x * x + 2;
}
double bisectionMethod(double a, double b, double tolerance) {
    double c;
    while ((b - c) >= tolerance) {
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}
int main() {
    double a, b, tolerance;
    printf("Enter the initial value a: ");
    scanf("%lf", &a);
    printf("Enter the final value b: ");
    scanf("%lf", &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);
    if (f(a) * f(b) >= 0) {
        printf("No root exists on the interval [%.2lf, %.2lf].\n", a, b);
        return 1; 
    }
    double root = bisectionMethod(a, b, tolerance);
    printf("Root of the equation on the interval [%.2lf, %.2lf] with tolerance %.6lf: %.6lf\n", a, b, tolerance, root);
    return 0;
}
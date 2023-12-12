#include <stdio.h>

int main() {
    int array[10][10];
    int num = 1;
    int top = 0, bottom = 9, left = 0, right = 9;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i)
            array[top][i] = num++;
        ++top;
        for (int i = top; i <= bottom; ++i)

            array[i][right] = num++;
        --right;
        for (int i = right; i >= left; --i)

            array[bottom][i] = num++;

        --bottom;
        for (int i = bottom; i >= top; --i)

            array[i][left] = num++;

        ++left;
    }
    printf("Sum of each row:\n");
    for (int i = 0; i < 10; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 10; ++j) {
            rowSum += array[i][j];
            printf("%4d ", array[i][j]);
        }
        printf("= %d\n", rowSum);
    }
    return 0;
}
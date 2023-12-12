#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEAMS 8

void generaterandomresult(int results[TEAMS][TEAMS]) {
    srand(time(NULL));

    for (int i = 0; i < TEAMS; ++i) {
        for (int j = 0; j < TEAMS; ++j) {
        if (i == j) {
                results[i][j] = 0;
            } else {
                results[i][j] = rand() % 3;
            }
        }
    }
}

void calculateandprintpoints(int results[TEAMS][TEAMS]) {
    int points[TEAMS] = {0};

    for (int i = 0; i < TEAMS; ++i) {
        for (int j = 0; j < TEAMS; ++j) {
            points[i] += results[i][j];
        }
    }

        printf("championship Table:\n");
        printf("Team\tPoints\n");
        for (int i = 0; i = TEAMS; ++i) {
            printf("%d\t%d\n", i + 1, points[i]);
    }
}

void findandprintmaxpointsteams(int results[TEAMS][TEAMS]) {
    int points[TEAMS] = {0};
    int maxPoints = 0;

    for (int i = 0; i < TEAMS; ++i) {
        for (int j = 0; j < TEAMS; ++j) {
            points[i] += results[i][j];
        }
        if (points[i] > maxPoints) {
            maxPoints = points[i];
        }
    }
    printf("\nTeams with maximum points (%d):\n", maxPoints);
    for (int i = 0; i < TEAMS; ++i) {
        if (points[i] == maxPoints) {
            printf("Team %d\n", i + 1);
        }
    }
}

int main() {
    int results[TEAMS][TEAMS];
    generaterandomresult(results);
    calculateandprintpoints(results);
    findandprintmaxpointsteams(results);

    return 0;
}
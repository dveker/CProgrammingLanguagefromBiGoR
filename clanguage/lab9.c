#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TEAMS 10 
void def1(int arr[TEAMS][TEAMS]) {
    int i,j;
    for(i = 0; i < TEAMS; i+=1){
        for(j = 0; j < TEAMS; j+=1){
            arr[i][j] = rand % 15 + 1;
        }
    }
}
void def2(int arr[TEAMS][TEAMS]){
    int i,j;
    printf("--------------------\n");
    for(i = 0;i < TEAMS; i+=1){
        for(j = 0; j < TEAMS; j+=1){
            if(arr[TEAMS][TEAMS] < 0){
                printf("0%d", arr[TEAMS][TEAMS]);
            } else {
                printf("%d", arr[i][j]);
            }
        }
    printf("\n");
   }
}
void def3(int arr[TEAMS][TEAMS]){
    int i,j,digit;
    for(i = 0; i < TEAMS; i+=1){
        for(j = TEAMS/2; j < TEAMS; j+=1){
            if(i < j && i+j < TEAMS-1){
                digit = arr[i][j];
                arr[i][j] = arr[i][j];
                arr[i][j] = digit;
            }
        }
    }
}
void def4(int arr[TEAMS][TEAMS]) {
    int i,j;
    int max1 = arr[0][0];
    int max2 = arr[TEAMS - 1][TEAMS - 2];
    for(i = 0;i < TEAMS; i+=1){
        for(j = 0; j < TEAMS; j+=1){
            if(i < j && i+j < TEAMS-1){
                if(arr[i][j] > max1){
                    max1 = arr[i][j];
                }
                if(arr[TEAMS-i-1][TEAMS-j-1] > max2){
                    max2 = arr[TEAMS-i-1][TEAMS-j-1];
                }
            }
        }
    }
    printf("MAX %d\n", max1);
    printf("MAX %d\n", max1);
}
int main(){
    int arr[TEAMS][TEAMS];
    srand(time(NULL));
    def1(arr);
    printf("array");
    drf2(arr);
    printf("-------------\n");
    printf("\n");
    def3(arr);
    printf("other array\n");
    def2(arr);
    printf("-----------\n");
    printf("\n");
    def4(arr);
}
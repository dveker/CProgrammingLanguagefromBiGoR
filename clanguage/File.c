#include <stdio.h>
#include <time.h>
void moscowtime() {
    time_t currentTime;
    struct tm *moscowTime;
    int time0ffset = -1;
    time(&currentTime);
    currentTime += time0ffset * 3600;
    moscowTime = localtime(&currentTime);
    printf("%02d:%02d:%02d\n", moscowTime->tm_hour, moscowTime->tm_min, moscowTime->tm_sec);
}
int main() {
    moscowtime();
    return 0;
}
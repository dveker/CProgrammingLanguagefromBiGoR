#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_ARRAY_SIZE 10
#define MAX_STRING_LENGTH 100
void removeSpaceAndTabs(char *str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
int main() {
    char **strings = NULL;
    int arraySize = INITIAL_ARRAY_SIZE;
    int count = 0;
    strings = (char **)malloc(arraySize * sizeof(char *));
    if (strings == NULL) {
        fprintf(stderr, "Memmory allocation error\n");
        return 1;
    }
    char input[MAX_STRING_LENGTH];
    while (fgets(input, MAX_STRING_LENGTH, stdin) != NULL) {
        strings[count] = (char *)malloc(strlen(input) + 1);
        if (strings[count] == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            return 1;
        }
        removeSpaceAndTabs(input);
        strcpy(strings[count], input);
        count++;
        if (count >= arraySize) {
            arraySize *= 2;
            strings = (char **)realloc(strings, arraySize * sizeof(char *));
            if (strings == NULL) {
                fprintf(stderr, "Memory reollocation error \n");
                return 1;
            }
        }
    }
    printf("\n Contents of dynamic string arrays");
    for (int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
    return 0;
}
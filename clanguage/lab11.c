#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node {
    char data;
    struct Node* next;
};
void push(struct Node** stack, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}
void printStack(struct Node* stack) {
    while (stack != NULL) {
        printf("%c ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}
int main() {
    char delimiter;
    printf("Enter delimiter character: ");
    scanf(" %c", &delimiter);  
    struct Node* stack = NULL;  
    char c;
    while (1) {
        scanf("%c", &c);
        if (c == delimiter) {
            while (stack != NULL && isalpha(stack->data)) {
                printf("%c", stack->data);  
                struct Node* temp = stack;
                stack = stack->next;
                free(temp);  
            }
            printf(" ");  
        } else {
            if (isalpha(c)) {
                push(&stack, c);
            }
        }

        if (c == '\n') {
            break;
        }
    }
    printStack(stack);
    while (stack != NULL) {
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *word;
    int count;
    struct Node *next;
};

void addWord(struct Node **head, const char *word) {
    struct Node *current = *head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    newNode->word = strdup(word);
    if (newNode->word == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    newNode->count = 1;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void writeToFile(struct Node *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (head != NULL) {
        fprintf(file, "%s %d\n", head->word, head->count);
        head = head->next;
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct Node *head = NULL;
    char word[100];

    while (scanf("%99s", word) != EOF) {
        addWord(&head, word);
    }

    writeToFile(head, argv[1]);

    freeList(head);

    return 0;
}

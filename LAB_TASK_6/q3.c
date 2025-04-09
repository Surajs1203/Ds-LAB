#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *nextNode, *prevNode;
};

struct Node *startNode, *newNode, *currentNode;

void initializeList() {
    startNode = NULL;
    int continueChoice = 1;
    while (continueChoice) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newNode->value);
        newNode->nextNode = NULL;
        newNode->prevNode = NULL;

        if (startNode == NULL) {
            startNode = currentNode = newNode;
        } else {
            currentNode->nextNode = newNode;
            newNode->prevNode = currentNode;
            currentNode = newNode;
        }

        printf("Do you want to continue? [0 for NO, 1 for YES]: ");
        scanf("%d", &continueChoice);
    }
}

void deleteFromStart() {
    currentNode = startNode;
    startNode = startNode->nextNode;

    if (startNode != NULL) {
        startNode->prevNode = NULL;
    }

    currentNode->nextNode = NULL;
    free(currentNode);
}

void displayList() {
    currentNode = startNode;
    if (currentNode == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->nextNode;
    }
    printf("\n");
}

int main() {
    initializeList();
    
    printf("The data in the list is: ");
    displayList();

    deleteFromStart();
    printf("The data after deletion of the first node is: ");
    displayList();

    return 0;
}

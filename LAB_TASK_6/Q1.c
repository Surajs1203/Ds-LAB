#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *prevNode;
    struct Node *nextNode;
};

struct Node *start = NULL, *end = NULL, *tempNode, *newNode;
int totalNodes = 0;

void initializeList() {
    int continueChoice = 1;
    while (continueChoice) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Please enter the data: ");
        scanf("%d", &newNode->value);
        newNode->nextNode = newNode->prevNode = NULL;
        totalNodes++;

        if (start == NULL) {
            start = end = newNode;
            start->nextNode = start;
            start->prevNode = start;
        } else {
            end->nextNode = newNode;
            newNode->prevNode = end;
            newNode->nextNode = start;
            start->prevNode = newNode;
            end = newNode;
        }
        printf("Do you want to add more nodes? [1-Yes / 0-No]: ");
        scanf("%d", &continueChoice);
    }
}

void insertNode() {
    int position;
    printf("Enter the position to insert a node: ");
    scanf("%d", &position);

    if (position >= 1 && position <= totalNodes + 1) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Please enter the data for the new node: ");
        scanf("%d", &newNode->value);
        newNode->nextNode = newNode->prevNode = NULL;
        totalNodes++;

        if (position == 1) {
            newNode->nextNode = start;
            newNode->prevNode = end;
            end->nextNode = newNode;
            start->prevNode = newNode;
            start = newNode;
        } else if (position == totalNodes) {
            newNode->nextNode = start;
            newNode->prevNode = end;
            end->nextNode = newNode;
            start->prevNode = newNode;
            end = newNode;
        } else {
            tempNode = start;
            for (int i = 1; i < position - 1; i++) {
                tempNode = tempNode->nextNode;
            }
            newNode->nextNode = tempNode->nextNode;
            newNode->prevNode = tempNode;
            tempNode->nextNode->prevNode = newNode;
            tempNode->nextNode = newNode;
        }
    } else {
        printf("Invalid position\n");
    }
}

void removeNode() {
    int position;
    printf("Enter the position to delete a node: ");
    scanf("%d", &position);

    if (position >= 1 && position <= totalNodes) {
        totalNodes--;

        if (position == 1) {
            tempNode = start;
            start = start->nextNode;
            start->prevNode = end;
            end->nextNode = start;
            free(tempNode);
        } else if (position == totalNodes + 1) {
            tempNode = end;
            end = end->prevNode;
            end->nextNode = start;
            start->prevNode = end;
            free(tempNode);
        } else {
            tempNode = start;
            for (int i = 1; i < position; i++) {
                tempNode = tempNode->nextNode;
            }
            tempNode->prevNode->nextNode = tempNode->nextNode;
            tempNode->nextNode->prevNode = tempNode->prevNode;
            free(tempNode);
        }
    } else {
        printf("Invalid position\n");
    }
}

void printList() {
    if (start == NULL) {
        printf("The list is empty\n");
        return;
    }
    tempNode = start;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d ", tempNode->value);
        tempNode = tempNode->nextNode;
    } while (tempNode != start);
    printf("\n");
}

int main() {
    initializeList();
    int choice;
    do {
        printf("\n1. Insert Node\n2. Delete Node\n3. Display List\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertNode(); break;
            case 2: removeNode(); break;
            case 3: printList(); break;
            case 4: printf("Exiting program...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

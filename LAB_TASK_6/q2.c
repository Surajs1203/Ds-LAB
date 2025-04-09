#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *nextNode;
};

struct Node *headNode = NULL, *newNode, *lastNode, *currentNode;
int nodeCount = 0;

void initializeList() {
    int continueChoice = 1;
    while (continueChoice) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        nodeCount++;
        printf("Enter the data: ");
        scanf("%d", &newNode->value);
        newNode->nextNode = NULL;

        if (headNode == NULL) {
            headNode = lastNode = newNode;
        } else {
            lastNode->nextNode = newNode;
            lastNode = newNode;
        }
        printf("Do you want to continue? [0 for NO & 1 for YES]: ");
        scanf("%d", &continueChoice);
    }
    lastNode->nextNode = headNode;  // Making the list circular
}

void insertNode() {
    int position;
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position >= 1 && position <= nodeCount + 1) {
        struct Node *insertNode = (struct Node*)malloc(sizeof(struct Node));
        nodeCount++;
        printf("Enter the data for the new node: ");
        scanf("%d", &insertNode->value);

        if (position == 1) {
            insertNode->nextNode = headNode;
            lastNode = headNode;
            while (lastNode->nextNode != headNode) {
                lastNode = lastNode->nextNode;
            }
            lastNode->nextNode = insertNode;
            headNode = insertNode;
        } else {
            currentNode = headNode;
            for (int i = 1; i < position - 1; i++) {
                currentNode = currentNode->nextNode;
            }
            insertNode->nextNode = currentNode->nextNode;
            currentNode->nextNode = insertNode;
        }
    } else {
        printf("Invalid position\n");
    }
}

void deleteNode() {
    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position >= 1 && position <= nodeCount) {
        nodeCount--;
        if (position == 1) {
            currentNode = headNode;
            lastNode = headNode;
            while (lastNode->nextNode != headNode) {
                lastNode = lastNode->nextNode;
            }
            headNode = headNode->nextNode;
            lastNode->nextNode = headNode;
            free(currentNode);
        } else {
            lastNode = headNode;
            for (int i = 1; i < position - 1; i++) {
                lastNode = lastNode->nextNode;
            }
            currentNode = lastNode->nextNode;
            lastNode->nextNode = currentNode->nextNode;
            free(currentNode);
        }
    } else {
        printf("Invalid position\n");
    }
}

void displayList() {
    if (headNode == NULL) {
        printf("The list is empty\n");
        return;
    }

    currentNode = headNode;
    int i = 0;
    printf("Circular Linked List: ");
    while (i < nodeCount) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->nextNode;
        i++;
    }
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
            case 2: deleteNode(); break;
            case 3: displayList(); break;
            case 4: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

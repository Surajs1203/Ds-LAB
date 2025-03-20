#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Stack Overflow.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    if (*top != NULL) {
        (*top)->next = newNode;
        newNode->prev = *top;
    }
    *top = newNode;
    printf("Pushed %d into the stack\n", value);
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    Node* temp = *top;
    int poppedValue = temp->data;
    *top = temp->prev;
    if (*top != NULL) {
        (*top)->next = NULL;
    }
    free(temp);
    return poppedValue;
}

void display(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                value = pop(&top);
                if (value != -1) {
                    printf("Popped %d from the stack\n", value);
                }
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

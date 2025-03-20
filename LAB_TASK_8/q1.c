#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the stack


typedef struct {
    int arr[MAX];
    int top;
} Stack;


void initialize(Stack *s) {
    s->top = -1;
}


int isFull(Stack *s) {
    return s->top == MAX - 1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element into the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("Pushed %d into the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}


int main() {
    Stack s;
    initialize(&s);

    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped %d from the stack\n", value);
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


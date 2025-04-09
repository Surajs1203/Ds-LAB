
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow.\n");
        return;
    }
    s->items[++(s->top)] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    return isEmpty(s) ? '\0' : s->items[s->top];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

int isBalanced(char *expression) {
    Stack s;
    initialize(&s);
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expression[MAX];
    printf("Enter an expression with parentheses: ");
    scanf("%s", expression);
    if (isBalanced(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int top;
    float items[100];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, float value) {
    s->items[++(s->top)] = value;
}

float pop(Stack *s) {
    return s->items[(s->top)--];
}

float evaluatePostfix(char *expression) {
    Stack s;
    initialize(&s);
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            float b = pop(&s);
            float a = pop(&s);
            switch (ch) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                case '^': push(&s, pow(a, b)); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    printf("Result: %.2f\n", evaluatePostfix(expression));
    return 0;
}

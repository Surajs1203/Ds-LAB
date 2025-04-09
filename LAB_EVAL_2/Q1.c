#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void append(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

int isPalindrome() {
    if (head == NULL) return 1;
    Node* start = head;
    Node* end = head->prev;
    while (start != end && start->prev != end) {
        if (start->data != end->data)
            return 0;
        start = start->next;
        end = end->prev;
    }
    return 1;
}

int main() {
    char str[] = "radar";
    for (int i = 0; str[i]; i++)
        append(str[i]);

    if (isPalindrome())
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}

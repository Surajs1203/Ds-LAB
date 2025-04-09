#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int detectAndRemoveLoop(Node* head) {
    Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            Node* ptr1 = head;
            while (1) {
                Node* ptr2 = fast;
                while (ptr2->next != fast && ptr2->next != ptr1)
                    ptr2 = ptr2->next;
                if (ptr2->next == ptr1)
                    break;
                ptr1 = ptr1->next;
            }
            ptr2->next = NULL;
            return 1;
        }
    }
    return 0;
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head->next;  // loop

    if (detectAndRemoveLoop(head))
        printf("Loop detected and removed.\n");
    else
        printf("No loop found.\n");

    return 0;
}

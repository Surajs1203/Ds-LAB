#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void LLtraversal(struct node *ptr) {
    while (ptr != NULL) {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatbeg(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insertatindex(struct node *head, int data, int index) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p != NULL) {
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}

struct node *insertatend(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }

    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;

    return head;
}

int main() {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 70;
    second->next = third;

    third->data = 60;
    third->next = NULL;

    // Insertion at first
    printf("Linked list before insertion:\n");
    LLtraversal(head);
    head = insertatbeg(head, 45);
    printf("Linked list after insertion at beginning:\n");
    LLtraversal(head);

    // Insertion at particular position
    head = insertatindex(head, 89, 1);
    printf("Linked list after insertion at index 1:\n");
    LLtraversal(head);

    // Insertion at end
    head = insertatend(head, 67);
    printf("Linked list after insertion at end:\n");
    LLtraversal(head);

    return 0;
}

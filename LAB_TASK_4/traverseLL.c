#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Creating and displaying linked list
int main() {
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *ptr;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    ptr = head; // Corrected here

    while (ptr != NULL) {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}

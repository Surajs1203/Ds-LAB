#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int input = 1,i=0;
    struct node *head, *temp, *nnode;
    head = NULL;

    while (input == 1) {
        nnode = (struct node *)malloc(sizeof(struct node));
        if (nnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter data: ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;

        if (head == NULL) {
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = nnode;
        }
        
        printf("Do you want to add more data? (if yes, press 1)\n");
        scanf("%d", &input);
    }

    printf("Original linked list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }

    printf("\nThe length of linked list is:%d",i);

    return 0;
  }

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int input = 1;
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

    printf("Even elements: ");
    temp = head;
    while (temp != NULL) {
      if(temp->data%2==0){
        printf("%d ", temp->data);
      }
        temp = temp->next;
    }
    temp=head;
    printf("\nOdd elements: ");
    while (temp != NULL) {
      if(temp->data%2!=0){
        printf("%d ", temp->data);
      }
        temp = temp->next;
    }
    
    return 0;
  }

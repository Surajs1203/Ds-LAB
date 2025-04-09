#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *head, *newnode, *temp;

void create() {
    head = NULL;
    int choice = 1;
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        
        printf("Do you want to continue? (0 for NO & 1 for YES): ");
        scanf("%d", &choice);
    }
}

void display() {
    temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_pos() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    
    
    if (head == NULL) {
        printf("The list is empty. No node to delete.\n");
        return;
    }
    
    struct node *curr = head;
    int i = 1;
    
    while (curr != NULL && i < pos) {
        curr = curr->next;
        i++;
    }

    
    if (curr == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (curr == head) {
        head = curr->next;
        if (head != NULL) { 
            head->prev = NULL;
        }
    } else {
       
        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
    }

    
    free(curr);
    printf("Node at position %d deleted.\n", pos);
}

int main() {
    create();
    
    printf("The original list: ");
    display();
    
    delete_pos();
    
    printf("The list after deletion: ");
    display();
    
    return 0;
}


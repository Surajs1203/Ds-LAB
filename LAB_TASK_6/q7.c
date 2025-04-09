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

void insert_beginning() {
    struct node *bnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &bnode->data);
    
    bnode->prev = NULL;  // New node has no previous node
    bnode->next = head;  // New node points to the old head
    
    if (head != NULL) {
        head->prev = bnode;  // Old head's previous pointer points to the new node
    }
    
    head = bnode;  // Move the head to point to the new node
}

void display_forward() {
    temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    create();
    
    printf("Original list: ");
    display_forward();
    
    insert_beginning();
    
    printf("List after inserting at the beginning: ");
    display_forward();
    
    return 0;
}

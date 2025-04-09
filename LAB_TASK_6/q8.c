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

void insert_end() {
    struct node *cnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &cnode->data);
    
    cnode->next = NULL;  // New node is going to be the last node, so its next is NULL
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = cnode;
        cnode->prev = NULL;  // No previous node as it's the first node
    } else {
        temp->next = cnode;
        cnode->prev = temp;
    }
    
    temp = cnode;  // Update temp to point to the newly added node
}

void display_forward() {
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    create();  // Create the initial list
    insert_end();  // Insert a new node at the end
    printf("List after insertion at the end: ");
    display_forward();  // Display the updated list
    
    return 0;
}

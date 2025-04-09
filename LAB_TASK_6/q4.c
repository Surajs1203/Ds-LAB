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
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // If there's only one node in the list
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        // Move temp to the last node
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // Adjust the pointers of the second last node
        temp->prev->next = NULL;
        free(temp);
    }
}

int main() {
    create();
    
    printf("The original data in the list: ");
    display();
    
    delete_end();
    
    printf("The data after the deletion of the last node is: ");
    display();
    
    return 0;
}

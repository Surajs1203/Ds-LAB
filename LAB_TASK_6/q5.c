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
    
    // Check if the list is empty
    if (head == NULL) {
        printf("The list is empty. No node to delete.\n");
        return;
    }
    
    struct node *curr = head;
    int i = 1;
    
    // Traverse the list to find the node at the specified position
    while (curr != NULL && i < pos) {
        curr = curr->next;
        i++;
    }

    // If the position is out of bounds
    if (curr == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    // If the node to be deleted is the first node (head)
    if (curr == head) {
        head = curr->next;
        if (head != NULL) {  // If there are more nodes, set the previous pointer of the new head to NULL
            head->prev = NULL;
        }
    } else {
        // Adjust the pointers of the previous and next nodes
        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
    }

    // Free the memory of the node to be deleted
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


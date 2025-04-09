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

void insert_pos() {
    int pos;
    printf("Enter the position to insert the node: ");
    scanf("%d", &pos);
    
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct node *anode, *curr;
    anode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the inserted node: ");
    scanf("%d", &anode->data);

    anode->next = NULL;
    anode->prev = NULL;

    if (pos == 1) {
        anode->next = head;
        if (head != NULL) {
            head->prev = anode;
        }
        head = anode;
        return;
    }

    int i = 1;
    curr = head;
    while (curr != NULL && i < pos - 1) {
        curr = curr->next;
        i++;
    }

    if (curr == NULL) {
        printf("Position is beyond the end of the list. Insertion failed.\n");
        return;
    }

    anode->next = curr->next;
    anode->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = anode;
    }
    curr->next = anode;
}

int main() {
    create();
    printf("Initial list: ");
    display();

    insert_pos();
    printf("List after insertion: ");
    display();

    return 0;
}


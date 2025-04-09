#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct node* newnode = createNode(value);

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}
struct node* mergeSortedLists(struct node* head1, struct node* head2) {
    struct node* mergedHead = NULL;
    struct node* temp = NULL;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    if (head1->data < head2->data) {
        mergedHead = temp = head1;
        head1 = head1->next;
    } else {
        mergedHead = temp = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 != NULL) {
        temp->next = head1;
    }
    if (head2 != NULL) {
        temp->next = head2;
    }

    return mergedHead;
}
void display(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    int n1, n2;
    struct node *head1, *head2, *mergedHead;

    scanf("%d", &n1);
    head1 = createList(n1);

    scanf("%d", &n2);
    head2 = createList(n2);

    display(head1);

    display(head2);

    mergedHead = mergeSortedLists(head1, head2);

    display(mergedHead);

    return 0;
}

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

    printf("Original linked list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    int min = 32000;
    struct node *minNode =NULL;
    temp = head;
    
    int max=-32000;
    struct node *maxnode=NULL;
    temp=head;

    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
            minNode = temp;
        }
        if(temp->data>max){
        	max=temp->data;
        	maxnode=temp;
		}
        temp = temp->next;
    }

    if (head != NULL && minNode != NULL) {
        int tempData1 = head->data;
        head->data = minNode->data;
        minNode->data = tempData1;
        
        
    }
    temp=head;
    while(temp->next!=NULL){
    	temp=temp->next;
	}
    if(head !=NULL && maxnode !=NULL){
    	int tempData2 =temp->data;
    	temp->data=maxnode->data;
    	maxnode->data=tempData2;
	}

    printf("The new linked list is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    temp = head;
    while (temp != NULL) {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

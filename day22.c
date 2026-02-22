#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          
    struct node *next; 
};

struct node *head = NULL; 

void createList(int n) {
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory cannot be allocated.");
        exit(0);
    }

    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory cannot be allocated.");
            break;
        }
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode; 
        temp = newNode;      
    }
}

int countNodes() {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayList() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, totalNodes;

    scanf("%d", &n);

    createList(n);

    totalNodes = countNodes();

    displayList();

    return 0;
}

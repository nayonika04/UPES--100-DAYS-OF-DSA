#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next; 
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1); 
    }
    newNode->data = data;
    newNode->next = NULL; 
    return newNode;
}

void buildList(struct Node** head, int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        *head = NULL;
        return;
    }
    printf("Enter the elements: ");
    scanf("%d", &data);
    *head = createNode(data);
    temp = *head;

    for (i = 1; i < n; i++) {
        scanf("%d", &data);
        newNode = createNode(data);
        temp->next = newNode;
        temp = temp->next; 
    }
}

void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) { 
        printf("%d ", current->data);
        current = current->next; 
    }
    printf("\n");
}

int main() {
    int n;
    struct Node* head = NULL;
    printf("Input the number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for the number of nodes.\n");
        return 1;
    }
    buildList(&head, n);

    traverseList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode; //
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp; //
}

// Function to traverse and print the list
void traverseForward(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next; //
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data) == 1) insertEnd(&head, data);
    }

    traverseForward(head);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node using dynamic memory allocation
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to traverse and print the list in forward order
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Read n space-separated integers and insert them
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            insertEnd(&head, val);
        }
    }

    // Traverse from head using next pointers to print elements
    displayList(head);

    return 0;
}

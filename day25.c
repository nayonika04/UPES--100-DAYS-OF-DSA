#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node dynamically
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Dynamically allocate memory for a new node
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to count occurrences of a key in the linked list
int countOccurrences(struct Node* head, int key) {
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Function to free the dynamically allocated memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int n, element, key, count;

    // Input the number of nodes
    if (scanf("%d", &n) != 1) return 1;

    // Input the linked list elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &element) != 1) return 1;
        head = insertEnd(head, element);
    }

    // Input the key to be counted
    if (scanf("%d", &key) != 1) return 1;

    // Count the occurrences
    count = countOccurrences(head, key);

    // Print the result
    printf("%d\n", count);

    // Free memory
    freeList(head);

    return 0;
}

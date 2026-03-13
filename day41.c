#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global pointers for the front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to create a new node
struct Node* createNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Enqueues an element
void enqueue(int value) {
    struct Node* newNode = createNewNode(value);
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Dequeues an element
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = front;
    printf("%d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    char operation[10];
    int value;
    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(value);
        } else if (strcmp(operation, "dequeue") == 0) {
            dequeue();
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

// Deque structure
typedef struct {
    Node *front, *rear;
    int count;
} Deque;

// Initialize Deque
void initDeque(Deque *dq) {
    dq->front = dq->rear = NULL;
    dq->count = 0;
}

// 1. push_front: O(1)
void push_front(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL) dq->rear = newNode;
    else dq->front->prev = newNode;
    
    dq->front = newNode;
    dq->count++;
}

// 2. push_back: O(1)
void push_back(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL) dq->front = newNode;
    else dq->rear->next = newNode;

    dq->rear = newNode;
    dq->count++;
}

// 3. pop_front: O(1)
void pop_front(Deque *dq) {
    if (dq->front == NULL) return;
    Node *temp = dq->front;
    dq->front = dq->front->next;
    
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    
    free(temp);
    dq->count--;
}

// 4. pop_back: O(1)
void pop_back(Deque *dq) {
    if (dq->rear == NULL) return;
    Node *temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;

    free(temp);
    dq->count--;
}

// 5 & 6. front and back: O(1)
int front(Deque *dq) { return (dq->front) ? dq->front->data : -1; }
int back(Deque *dq) { return (dq->rear) ? dq->rear->data : -1; }

// 7 & 8. empty and size: O(1)
bool empty(Deque *dq) { return dq->count == 0; }
int size(Deque *dq) { return dq->count; }

// Clear: O(n)
void clear(Deque *dq) {
    while (!empty(dq)) pop_front(dq);
}

// Print Deque state
void printDeque(Deque *dq) {
    Node *curr = dq->front;
    printf("Deque: ");
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    // Sequence of operations
    push_back(&dq, 10);   // [10]
    push_back(&dq, 20);   // [10, 20]
    push_front(&dq, 5);   // [5, 10, 20]
    
    printf("Front: %d\n", front(&dq)); // 5
    printf("Back: %d\n", back(&dq));   // 20
    printf("Size: %d\n", size(&dq));   // 3

    pop_front(&dq);       // [10, 20]
    pop_back(&dq);        // [10]

    printDeque(&dq);      // Final state: 10
    
    clear(&dq);
    return 0;
}

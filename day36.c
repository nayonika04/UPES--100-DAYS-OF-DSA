#include <stdio.h>
#include <stdlib.h>

// Global variables to manage the dynamically allocated queue
int *queue;
int front = -1, rear = -1;
int capacity; // Maximum size of the queue

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % capacity == front;
}

// Function to enqueue (insert) an element
void enqueue(int data) {
    if (isFull()) {
        // In a fixed size array, we print an overflow message.
        // For dynamic allocation, you might resize the array here (more complex, not required by prompt).
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % capacity; // Circular increment
    queue[rear] = data;
}

// Function to dequeue (remove) an element
int dequeue() {
    if (isEmpty()) {
        return -1; // Indicate underflow
    }
    int data = queue[front];
    if (front == rear) {
        // Queue has only one element, reset to empty state
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % capacity; // Circular increment
    }
    return data;
}

// Function to display the queue elements from front to rear
void display() {
    if (isEmpty()) {
        return;
    }
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % capacity;
    }
    printf("%d\n", queue[rear]); // Print the last element
}

int main() {
    int n, m, element;

    // Input the number of elements to enqueue
    if (scanf("%d", &n) != 1) return 1;

    // Dynamically allocate memory for the queue
    capacity = n; // Set capacity based on initial input 'n'
    queue = (int *)malloc(capacity * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input the 'n' space-separated integers and enqueue them
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        enqueue(element);
    }

    // Input the number of dequeue operations
    if (scanf("%d", &m) != 1) return 1;

    // Perform 'm' dequeue operations
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display the remaining queue elements
    display();

    // Free the dynamically allocated memory before exiting
    free(queue);

    return 0;
}

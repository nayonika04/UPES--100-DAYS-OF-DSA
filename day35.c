#include <stdio.h>
#include <stdlib.h>

// Global variables for the queue
int *queue;
int front = -1, rear = -1;
int size;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    // In a circular queue implementation with an array, full condition can vary.
    // For a simple linear array queue with dynamic size, we assume it's never full if we can reallocate.
    // Given the problem constraints, the size is fixed after input.
    return (rear + 1) % size == front;
}

// Function to enqueue an element
void enqueue(int data) {
    if (isFull()) {
        // If the queue is full, print an error or handle dynamically if needed.
        // The problem assumes we only enqueue 'n' elements total.
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % size;
    queue[rear] = data;
}

// Function to display the queue elements from front to rear
void display() {
    if (isEmpty()) {
        return;
    }
    int i;
    // Iterate from front to rear using circular logic
    for (i = front; i != rear; i = (i + 1) % size) {
        printf("%d ", queue[i]);
    }
    // Print the last element
    printf("%d\n", queue[i]);
}

int main() {
    int n, i, element;

    // Read the number of elements (which also defines the maximum queue size)
    if (scanf("%d", &n) != 1) return 1;
    size = n;

    // Dynamically allocate memory for the queue array
    queue = (int *)malloc(size * sizeof(int));
    if (queue == NULL) {
        // Handle memory allocation failure
        return 1;
    }

    // Read the n elements and enqueue them
    for (i = 0; i < n; i++) {
        if (scanf("%d", &element) != 1) return 1;
        enqueue(element);
    }

    // Display the queue elements
    display();

    // Free the dynamically allocated memory
    free(queue);

    return 0;
}

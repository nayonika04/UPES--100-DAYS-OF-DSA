#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Moves the element at index i up to restore Min Heap property
void bubbleUp(int i) {
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Moves the element at index i down to restore Min Heap property
void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

void insert(int x) {
    if (size >= MAX_SIZE) return;
    heap[size] = x;
    bubbleUp(size);
    size++;
}

int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) {
        size--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    minHeapify(0);
    return root;
}

int peek() {
    return (size <= 0) ? -1 : heap[0];
}

int main() {
    int n, val;
    char op[20];
    
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}

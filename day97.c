#include <stdio.h>
#include <stdlib.h>

// Structure to represent a meeting
typedef struct {
    int start;
    int end;
} Interval;

// Comparison function to sort intervals by start time
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Min-Heap structure to track meeting end times
typedef struct {
    int* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;
    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap->data[idx], &heap->data[smallest]);
        minHeapify(heap, smallest);
    }
}

void push(MinHeap* heap, int val) {
    if (heap->size == heap->capacity) return;
    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = val;

    // Fix the min heap property if violated
    while (i != 0 && heap->data[(i - 1) / 2] > heap->data[i]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int pop(MinHeap* heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

int peek(MinHeap* heap) {
    return heap->data[0];
}

int minMeetingRooms(Interval* intervals, int n) {
    if (n == 0) return 0;

    // 1. Sort meetings by start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Create min-heap to store end times
    MinHeap* heap = createMinHeap(n);

    // Add the first meeting's end time
    push(heap, intervals[0].end);

    // 3. Iterate through sorted meetings
    for (int i = 1; i < n; i++) {
        // If the room with the earliest end time is free, reuse it
        if (intervals[i].start >= peek(heap)) {
            pop(heap);
        }
        // Add current meeting's end time
        push(heap, intervals[i].end);
    }

    int result = heap->size;
    free(heap->data);
    free(heap);
    return result;
}

int main() {
    Interval intervals[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    printf("Minimum rooms required: %d\n", minMeetingRooms(intervals, n)); // Output: 2
    return 0;
}

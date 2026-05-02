#include <stdio.h>
#include <stdlib.h>

// Define a structure for Interval
struct Interval {
    int start;
    int end;
};

// Comparator function for qsort to sort by start time
int compareIntervals(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

// Function to merge overlapping intervals
void mergeIntervals(struct Interval arr[], int n) {
    if (n <= 0) return;

    // 1. Sort the intervals based on start time
    qsort(arr, n, sizeof(struct Interval), compareIntervals);

    int index = 0; // Index for the last merged interval

    // 2. Iterate and compare with the previous merged interval
    for (int i = 1; i < n; i++) {
        // If current interval overlaps with the previous one
        if (arr[index].end >= arr[i].start) {
            // Merge: update the end of the previous interval
            if (arr[index].end < arr[i].end) {
                arr[index].end = arr[i].end;
            }
        } else {
            // No overlap: move to next position and store current interval
            index++;
            arr[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged Intervals: \n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
    printf("\n");
}

int main() {
    struct Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}

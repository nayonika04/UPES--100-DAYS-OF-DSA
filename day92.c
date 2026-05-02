#include <stdio.h>

// Standard swap function
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Lomuto partition: uses the last element as the pivot
int partitionLomuto(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partitionLomuto(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSortLomuto(arr, low, pi - 1);
        quickSortLomuto(arr, pi + 1, high);
    }
}

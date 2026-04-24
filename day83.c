#include <stdio.h>

/**
 * Function to perform Selection Sort on an array of size n.
 * It finds the smallest element in each pass and swaps it into its correct position.
 */
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted portion
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n, i;

    // Input: Number of elements
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Input: n space-separated integers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform sorting
    selectionSort(arr, n);

    // Output: Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

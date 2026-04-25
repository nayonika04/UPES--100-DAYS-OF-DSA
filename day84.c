#include <stdio.h>

/**
 * Function to sort an array using insertion sort.
 * It builds the final sorted array one item at a time by comparisons.
 */
void insertionSort(int arr[], int n) {
    int i, key, j;
    // Iterate from the second element to the end of the array
    for (i = 1; i < n; i++) {
        key = arr[i]; // Store the current element to be inserted
        j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than the key
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert the key at its correct position
    }
}

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    
    // Read n space-separated integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform sorting
    insertionSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}

#include <stdio.h>

/**
 * Bubble Sort Implementation
 * Input: n (size), followed by n space-separated integers.
 * Output: Sorted array in ascending order.
 */

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Outer loop for passes through the array
    for (i = 0; i < n - 1; i++) {
        // Inner loop to compare adjacent elements
        // The largest elements "bubble" to the end with each pass
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Read the space-separated integers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform sorting
    bubbleSort(arr, n);

    // Output the sorted array
    for (i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // 1. Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // 2. Build frequency array (count array) initialized with zeros
    int* count = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 3. Compute prefix sums (cumulative counts)
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build output array
    int* output = (int*)malloc(n * sizeof(int));
    // Traverse backwards to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    free(count);
    free(output);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays and counts cross-inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be filled in temp array
    long long inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There is an inversion because arr[i] > arr[j]
            temp[k++] = arr[j++];
            // All elements from arr[i] to arr[mid] are greater than arr[j]
            inv_count += (mid - i + 1);
        }
    }

    // Copy the remaining elements of left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Recursive function to sort and count inversions
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = (right + left) / 2;

        // Inversions in left subarray
        inv_count += mergeSortAndCount(arr, temp, left, mid);
        // Inversions in right subarray
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        // Inversions during merge
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    
    long long result = mergeSortAndCount(arr, temp, 0, n - 1);
    printf("Number of inversions are %lld\n", result);
    return 0;
}

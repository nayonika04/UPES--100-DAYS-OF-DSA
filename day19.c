#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare integers for qsort
int compareAbs(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZeroPair(int arr[], int n) {
    // Array should have at least two elements
    if (n < 2) {
        printf("Invalid Input: Array must have at least two elements\n");
        return;
    }

    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), compareAbs);

    int left = 0;
    int right = n - 1;
    int min_sum = arr[left] + arr[right];
    int min_left = left;
    int min_right = right;
    int sum;

    // Use two pointers to scan the array inwards
    while (left < right) {
        sum = arr[left] + arr[right];

        // If current sum is closer to zero, update the minimum sum and elements
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_left = left;
            min_right = right;
        }

        // If sum is exactly zero, we found the best possible pair
        if (sum == 0) {
            break;
        }
        
        // If sum is negative, to increase the sum, increment the left pointer
        else if (sum < 0) {
            left++;
        }
        // If sum is positive, to decrease the sum, decrement the right pointer
        else {
            right--;
        }
    }

    printf("%d %d\n", arr[min_left], arr[min_right]);
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) return 1;

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Read the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the pair
    findClosestToZeroPair(arr, n);

    free(arr);
    return 0;
}

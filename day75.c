#include <stdio.h>

int findMaxLen(int arr[], int n) {
    int max_len = 0;
    // Outer loop picks the starting point
    for (int i = 0; i < n; i++) {
        int curr_sum = 0;
        // Inner loop picks the ending point
        for (int j = i; j < n; j++) {
            curr_sum += arr[j];
            // If current sum is zero, update max_len
            if (curr_sum == 0) {
                int len = j - i + 1;
                if (len > max_len) {
                    max_len = len;
                }
            }
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = findMaxLen(arr, n);
    printf("%d\n", result); // Output: 5
    
    return 0;
}

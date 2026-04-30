#include <stdio.h>
#include <stdbool.h>


// Function to check if a valid allocation is possible
bool isPossible(int arr[], int n, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        // If single book exceeds limit, invalid
        if (arr[i] > curr_min) return false;

        if (curr_sum + arr[i] > curr_min) {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m) return false;
        } else {
            curr_sum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    if (m > n) return -1; // More students than books

    long long sum = 0;
    int max_pages = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max_pages) max_pages = arr[i];
    }

    int start = max_pages, end = sum;
    int result = -1;

    // Binary search for the minimum maximum pages
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            end = mid - 1; // Try smaller maximum
        } else {
            start = mid + 1; // Increase maximum
        }
    }
    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", findPages(arr, n, m));
    return 0;
}

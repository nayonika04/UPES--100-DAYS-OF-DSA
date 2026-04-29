#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort stalls in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if it's possible to place k cows with at least 'dist' distance
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1; // Place the first cow at the first stall
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= dist) {
            count++;
            last_pos = stalls[i];
            if (count >= k) return 1; // Successfully placed all cows
        }
    }
    return 0;
}

int solve() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary Search on the answer
    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, n, k, mid)) {
            ans = mid;      // Found a valid distance, try for a larger one
            low = mid + 1;
        } else {
            high = mid - 1; // Distance too large, try smaller
        }
    }
    printf("%d\n", ans);
    return 0;
}

int main() {
    solve();
    return 0;
}

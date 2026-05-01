#include <stdio.h>

// Helper function to check if it's possible to paint all boards 
// within a given 'mid' time limit using 'k' painters.
int isPossible(int boards[], int n, int k, long long maxTime) {
    int paintersCount = 1;
    long long currentBoardSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than the allowed time, it's impossible.
        if (boards[i] > maxTime) return 0;

        if (currentBoardSum + boards[i] > maxTime) {
            // Assign new painter
            paintersCount++;
            currentBoardSum = boards[i];
            if (paintersCount > k) return 0;
        } else {
            currentBoardSum += boards[i];
        }
    }
    return 1;
}

long long solve(int n, int k, int boards[]) {
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // Try to find a smaller maximum time
        } else {
            low = mid + 1; // Increase allowed time to accommodate more boards
        }
    }
    return result;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%lld\n", solve(n, k, boards));
    return 0;
}

#include <stdio.h>

/**
 * Finds the floor of the square root of a non-negative integer using Binary Search.
 * Returns the largest integer whose square is less than or equal to n.
 */
long long floorSqrt(long long n) {
    if (n == 0 || n == 1) return n;

    long long start = 0, end = n, ans = 0;
    
    while (start <= end) {
        long long mid = start + (end - start) / 2;

        // Check if mid*mid is equal to n
        if (mid * mid == n) {
            return mid;
        }

        // If mid*mid < n, mid is a potential answer, search in the right half
        if (mid * mid < n) {
            ans = mid;
            start = mid + 1;
        } 
        // If mid*mid > n, search in the left half
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%lld\n", floorSqrt(n));
    }
    return 0;
}

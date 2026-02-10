#include <stdio.h>
#include <string.h>
#include <ctype.h> // Required for tolower()

int is_palindrome(const char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    // Optional: Convert to lowercase for case-insensitive comparison
    // If case sensitivity is required, remove the tolower() calls.
    while (left < right) {
        // Skip non-alphanumeric characters if necessary (modify as needed)
        // while (!isalnum(s[left]) && left < right) { left++; }
        // while (!isalnum(s[right]) && left < right) { right--; }

        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // It is a palindrome
}

int main() {
    char s[100]; // Assume max string length is 100

    // Read input from the user
    if (scanf("%99s", s) != 1) {
        return 1; // Handle input error
    }

    if (is_palindrome(s)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

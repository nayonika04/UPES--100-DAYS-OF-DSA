#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char *s) {
    int count[256] = {0}; // Frequency array for all ASCII characters
    int len = strlen(s);

    // First Pass: Count occurrences
    for (int i = 0; i < len; i++) {
        count[(unsigned char)s[i]]++;
    }

    // Second Pass: Find first unique character
    for (int i = 0; i < len; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            return s[i];
        }
    }

    return '$'; // Return '$' if all characters repeat
}

int main() {
    char s[] = "geeksforgeeks";
    char result = findFirstNonRepeating(s);
    printf("%c\n", result); // Output: f
    return 0;
}

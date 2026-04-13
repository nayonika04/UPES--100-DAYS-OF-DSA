#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char findFirstRepeated(char* s) {
    // Hash table to store frequencies of 26 lowercase letters
    int hash[26] = {0}; 
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        // If character already seen, this is the first repetition
        if (hash[s[i] - 'a'] == 1) {
            return s[i];
        }
        // Mark character as seen
        hash[s[i] - 'a'] = 1;
    }
    return '\0'; // No repetition
}

int main() {
    char s[] = "geeksforgeeks";
    char result = findFirstRepeated(s);
    if (result != '\0')
        printf("%c\n", result);
    else
        printf("-1\n");
    return 0;
}


#include <stdio.h>

int main() {
    int n;
    
    // Read the number of rows and columns (n x n matrix)
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for matrix size.\n");
        return 1;
    }

    int matrix[n][n];
    int isIdentity = 1; // Assume it's an identity matrix initially

    // Read the matrix elements from the input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input for matrix elements.\n");
                return 1;
            }
        }
    }

    // Check if the matrix is an identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // Diagonal elements must be 1
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break; // No need to check further
                }
            } else {
                // Non-diagonal elements must be 0
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break; // No need to check further
                }
            }
        }
        if (isIdentity == 0) {
            break; // Exit the outer loop too
        }
    }

    // Print the result
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}

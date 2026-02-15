#include <stdio.h>

int main() {
    int m, n;
    
    // Read the number of rows (m) and columns (n)
    printf("Enter the number of rows and columns: ");
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input for dimensions.\n");
        return 1;
    }
    
    // Check if the matrix is square
    if (m != n) {
        printf("The matrix must be square to have a primary diagonal. Exiting.\n");
        return 1;
    }

    int matrix[m][n];
    int sum_diagonal = 0;

    // Read the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input for matrix elements.\n");
                return 1;
            }
        }
    }

    // Calculate the sum of the primary diagonal elements
    for (int i = 0; i < m; i++) {
        sum_diagonal += matrix[i][i]; // Add element where row index equals column index
    }

    // Print the result
    printf("Sum of the primary diagonal elements: %d\n", sum_diagonal);

    return 0;
}

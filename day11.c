#include <stdio.h>

int main() {
    int m, n, i, j;

    // Read the number of rows and columns
    if (scanf("%d %d", &m, &n) != 2) return 1;

    // Declare the matrices
    int matrix1[m][n], matrix2[m][n], sum[m][n];

    // Read elements of the first matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Read elements of the second matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the resultant matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}

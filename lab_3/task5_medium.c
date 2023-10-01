#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    // Initialize the adjacency matrix
    int adjacency_matrix[n][n];
    int i, j;

    // Read the input matrix
    printf("Enter the adjacency matrix (0s and 1s):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    // Display the computed adjacency matrix
    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                // Diagonal elements represent self-loops, set them to 0 or 1 as needed
                adjacency_matrix[i][j] = 0;
            }
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

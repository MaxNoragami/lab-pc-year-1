#include <stdio.h>

// Function to swap two columns of the matrix
void swapColumns(int matrix[][100], int col1, int col2, int n) {
    for (int i = 0; i < n; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

// Function to partition the matrix for quicksort by columns
int partition(int matrix[][100], int low, int high, int n) {
    int pivotCol = high;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (matrix[0][j] < matrix[0][pivotCol]) {
            i++;
            swapColumns(matrix, i, j, n);
        }
    }
    swapColumns(matrix, i + 1, high, n);
    return i + 1;
}

// Function to perform quicksort on columns of the matrix
void quickSort(int matrix[][100], int low, int high, int n) {
    if (low < high) {
        int pivotIndex = partition(matrix, low, high, n);
        quickSort(matrix, low, pivotIndex - 1, n);
        quickSort(matrix, pivotIndex + 1, high, n);
    }
}

int main() {
    int n, m;
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    // Input the matrix elements
    int matrix[100][100];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sort the matrix by columns using quicksort
    quickSort(matrix, 0, m - 1, n);

    // Display the sorted matrix
    printf("Sorted Matrix by column:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

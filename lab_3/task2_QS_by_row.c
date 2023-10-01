#include <stdio.h>

// Function to swap two rows of the matrix
void swapRows(int row1[], int row2[], int m) {
    for (int i = 0; i < m; i++) {
        int temp = row1[i];
        row1[i] = row2[i];
        row2[i] = temp;
    }
}

// Function to partition the matrix for quicksort
int partition(int matrix[][100], int low, int high, int m) {
    int *pivot = matrix[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (matrix[j][0] < pivot[0]) {
            i++;
            swapRows(matrix[i], matrix[j], m);
        }
    }
    swapRows(matrix[i + 1], matrix[high], m);
    return i + 1;
}

// Function to perform quicksort on rows of the matrix
void quickSort(int matrix[][100], int low, int high, int m) {
    if (low < high) {
        int pivotIndex = partition(matrix, low, high, m);
        quickSort(matrix, low, pivotIndex - 1, m);
        quickSort(matrix, pivotIndex + 1, high, m);
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

    // Sort the matrix by rows using quicksort
    quickSort(matrix, 0, n - 1, m);

    // Display the sorted matrix
    printf("Sorted Matrix by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

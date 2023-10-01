#include <stdio.h>

int main() {
    int n, m;
    printf("Input the number of rows (n): ");
    scanf("%d", &n);
    printf("Input the number of columns (m): ");
    scanf("%d", &m);

    int matrix[n][m];
    printf("Input the elements of the array:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    //prod of non-zero elements
    for(int j=0; j<m; j++){
        int prod = 1;
        for(int i=0; i<n; i++){
            if(matrix[n][m]!=0){
                prod *= matrix[i][j];
            }
        }
        printf("Product of non-zero elements in column %d: %d\n", j+1, prod);
    }

    //the neg nums counter on the main diagonal
    int count = 0;
    for (int i=0; i<n; i++){
        if(i<m && matrix[i][i]<0){
            count++;
        }
    }
    printf("The number of negative numbers on the main diagonal: %d", count);

  return 0;
}

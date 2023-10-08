#include<stdio.h>

void bubble_sort(int array[], int nr_elements){
    for(int i=0; i<nr_elements - 1; i++){
        for(int j=0; j<nr_elements-i-1; j++){
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){

    int column;
    int row;
    printf("Enter how many rows you want: ");
    scanf("%d", &row);
    printf("Enter how many columns you want: ");
    scanf("%d", &column);

    int matrix[row][column];
    printf("Enter the elements of the matrix: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int nr_elements = row*column;
    int array[nr_elements];

    int index = 0;
    for (int row_nr = 0; row_nr < row; row_nr++) {
        for (int col_nr = 0; col_nr < column; col_nr++) {
            array[index++] = matrix[row_nr][col_nr];
        }
    }

    bubble_sort(array, nr_elements);

    int index_2 = 0;
    int col_begin = 0;
    int col_end = column-1;
    int row_begin = 0;
    int row_end = row -1;

    while(col_begin<=col_end && row_begin<=row_end){

        for(int i=col_begin; i<=col_end;i++){
            matrix[row_begin][i] = array[index_2++];
        }
        row_begin++;

        for(int i=row_begin; i<=row_end; i++){
            matrix[i][col_end] = array[index_2++];

        }
        col_end--;

        if(row_begin<=row_end){
            for(int i=col_end; i>=col_begin;i--){
                matrix[row_end][i] = array[index_2++];
            }
            row_end--;
        }
        if(col_begin<=col_end){
            for(int i= row_end; i>=row_begin; i--){
                matrix[i][col_begin]=array[index_2++];
            }
            col_begin++;

        }
    }

    printf("The Mountain Matrix: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

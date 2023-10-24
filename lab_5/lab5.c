#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu();
void allocateMemory(int ***array, int n, int m);
void inputElements(int **array, int n, int m);
void fillRandom(int **array, int n, int m);
void sortOddRows(int **array, int n, int m);
void displayElements(int **array, int n, int m);
void deallocateMemory(int **array, int n);

void displayMenu() {
    printf("\nMenu Options:\n");
    printf("1. Allocate memory for the 2D array\n");
    printf("2. Input elements from the keyboard\n");
    printf("3. Fill the array with random values\n");
    printf("4. Sort rows using Selection Sort\n");
    printf("5. Display elements\n");
    printf("6. Deallocate memory\n");
    printf("0. Exit program\n");
}

void allocateMemory(int ***array, int n, int m) {
    int i;
    *array = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        (*array)[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Memory allocated successfully.\n");
}

void inputElements(int **array, int n, int m) {
    int i, j;
    printf("Enter the elements for the %d x %d array:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}

void fillRandom(int **array, int n, int m) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            array[i][j] = rand() % 100;
        }
    }
    printf("Array filled with random values.\n");
}

void sortOddRows(int **array, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            int minIndex = j;
            for (int k = j + 1; k < n; k++) {
                if (array[i][k] < array[i][minIndex]) {
                    minIndex = k;
                }
            }
            if (minIndex != j) {
                int temp = array[i][j];
                array[i][j] = array[i][minIndex];
                array[i][minIndex] = temp;
            }
        }
    }
    printf("Rows were sorted.\n");
}

void displayElements(int **array, int n, int m) {
    printf("The 2D Array elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void deallocateMemory(int **array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    array = NULL;
    printf("Memory deallocated successfully.\n");
}

void row_to_column(int **array_2D, int m, int n) {
    int **temp;


    temp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        temp[i] = (int *)malloc(m * sizeof(int));
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][i] = array_2D[i][j];
        }
    }
    for(int i = 0; i<n;i++){
    for(int j = 0; j<m; j++){
        printf("%d ", temp[i][j]);
    }
    printf("\n");
}
    free(temp);
}

void target_index_finder(int *array_1D, int k){

    int index = 0;
    int target;
    int first = 0;
    printf("Task 3: Enter a target value from the 1D array, whose index will be found: ");
    scanf("%d", &target);

    for(int i = 0; i<k; i++){


        if(target == *(array_1D + i)){
            index--;
            first++;
            if (first == 1){
                    printf("\n");
                printf("The index is: %d", i);
            }

        }

        index++;
        if(index == k){
        printf("\n");
        printf("There is no such value, my man.");
        }


    }
    printf("\n");

}

void value_var_printed_by_pointer(){
    int k;
    printf("Task 4: Insert an integer, whose value will be printed with the help of a pointer: ");
    scanf("%d", &k);
    int* p;
    p = &k;
    printf("Your value is: %d, printed with the help of the pointer with the memory address %p!\n", *p, &p);

}

void swap_value_by_pointer(){
    int* p1, value1;
    int* p2, value2;
    int* p_temp;
    printf("Task 5: Insert the first integer, whose value will be swapped with the help of a pointer: ");
    scanf("%d", &value1);
    printf("Insert the second integer: ");
    scanf("%d", &value2);
    p1 = &value1;
    p2 = &value2;
    p_temp = p1;
    p1 = p2;
    p2 = p_temp;
    printf("\n");
    printf("The first value after the swap: %d, with the address %p;\n", *p1, &p1);
    printf("The second value after the swap: %d, with the address %p;\n", *p2, &p2);
}

void sum_of_neg(int *array_1D, int k){
    int sum_of_neg = 0;
    for(int i = 0; i<k; i++){
        if(*(array_1D + i)<0){
            sum_of_neg += *(array_1D+i);
        }
    }
    printf("Task 2: Sum of negative elements of the 1D array: %d", sum_of_neg);
    printf("\n");
}

int main() {
    int k;
    int n, m;
    int **array = NULL;
    int choice;

    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    allocateMemory(&array, n, m);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                allocateMemory(&array, n, m);
                break;
            case 2:
                inputElements(array, n, m);
                break;
            case 3:
                fillRandom(array, n, m);
                break;
            case 4:
                sortOddRows(array, n, m);
                break;
            case 5:
                displayElements(array, n, m);
                break;
            case 6:
                deallocateMemory(array, n);
                break;
            case 0:
                printf("\n Have a nice day, mister!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);


int** array_2D;

printf("\n*****************************\n\n");
printf("Enter the number of rows of the 2D array: ");
scanf("%d", &n);
printf("Enter the number of columns of the 2D array: ");
scanf("%d", &m);

array_2D = (int**) malloc(n * sizeof(int));
printf("\n");
printf("Enter the elements of the array: \n");
for(int i = 0; i<n;i++){
    array_2D[i] = (int *)malloc(m * sizeof(int));
    for(int j = 0; j<m; j++){
        scanf("%d", &array_2D[i][j]);
    }
}
printf("\n");

if(n != m){
    printf("Error, the number of rows must be the same as the columns!");
}
else{
    printf("Task 1: The initial matrix with the values from the rows changed to the columns and vice-versa: \n");
    row_to_column(array_2D, m, n);
}

free(array_2D);
printf("\n*****************************\n\n");

printf("Enter the length of the 1D array: ");
scanf("%d", &k);

int* array_1D;

array_1D = (int*) malloc(k * sizeof(int));
printf("Enter the elements of the 1D array: ");
for(int i = 0; i<k; i++){
    scanf("%d", array_1D+i);
}
printf("\n");
sum_of_neg(array_1D, k);

 int* array_1Dc = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        array_1Dc[i] = array_1D[i];
    }

free(array_1D);

printf("\n*****************************\n\n");

target_index_finder(array_1Dc, k);
free(array_1Dc);

printf("\n*****************************\n\n");
value_var_printed_by_pointer();
printf("\n*****************************\n\n");
swap_value_by_pointer();


    return 0;
}

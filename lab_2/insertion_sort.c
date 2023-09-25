#include<stdio.h>
#include<time.h>

void insertionSort(int array[], int num)
    {
        for(int i = 1; i < num; i++){
                int temp = array[i];
                int j = i - 1;

                while(j >= 0 && array[j] > temp) {
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1] = temp;
        }
    }
int main()
    {


        int n;
        printf("Enter the length of the arrays (n>50): ");
        while(n <= 50){
        scanf("%d", &n);
        }

        int array_1[n], array_2[n];

        printf("Array 1: ");
        for(int i = 0; i < n; i++){
            scanf("%d", &array_1[i]);
        }

        printf("Array 2: ");
        for(int i = 0; i < n; i++){
            scanf("%d", &array_2[i]);
        }

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock(); // Start time

        printf("Easy Task Insertion Sort: ");
        insertionSort(array_1, n);
        for(int i=0; i < n; i++){
            printf("%d ", array_1[i]);
        }

    end_time = clock();   // End time
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nCPU Time Used: %f seconds\n", cpu_time_used);
    return 0;

    }

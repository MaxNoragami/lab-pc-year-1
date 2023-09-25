#include<stdio.h>
#include<time.h>

void selectionSort(int array[], int num)
    {
        for(int i = 0; i < num - 1; i++){
                int min = i;
            for(int j = i + 1; j < num; j++){
                if(array[min]>array[j]){
                    min = j;

                }
            }
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
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

        printf("Easy Task Selection Sort: ");
        selectionSort(array_1, n);
        for(int i=0; i < n; i++){
            printf("%d ", array_1[i]);
        }

    end_time = clock();   // End time
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nCPU Time Used: %f seconds\n", cpu_time_used);
    return 0;

    }

#include<stdio.h>
#include<time.h>

void evenSum(int array[], int num)
    {
        int sum = 0;
        for(int i = 0; i < num; i++){
            if (array[i] % 2== 0){
                sum += array[i];
            }
        }
      printf("%d", sum);
    }
int main()
    {


        int n;
        printf("Enter the length of the arrays (n>50): ");
        restart:
        scanf("%d", &n);
        if (n<=50) {
            goto restart;
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

        printf("Easy Task Sum Of Even Numbers: ");
        evenSum(array_1, n);

    end_time = clock();   // End time
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nCPU Time Used: %f seconds\n", cpu_time_used);
    return 0;

    }

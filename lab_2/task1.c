#include<stdio.h>
int main(){
float array[] = {55.7, 3, -2.33, -3, 6.7, 8.2, -66.69};
int n = sizeof(array)/sizeof(array[0]);

float max_v = array[0];
float sum_n = 0;
int count = 0;
int max_p[n];

for(int i = 0; i < n; i++){
    if (array[i] > max_v){
        max_v = array[i];
        count = 1;
        max_p[0] = i;
    }
    else if (array[i] == max_v){
        max_p[count] = i;
        (count)++;
    }

    if(array[i] < 0){
        sum_n = sum_n + array[i];
    }
}
int  max_pos;
for(int i = 0; i < count; i++) {
    max_pos = max_p[i];
}
printf("Task 1: \n");
printf("Max Value: %.2f\n", max_v);
printf("Positions of Max Value: ");
printf("%d ", max_pos);
printf("\nSum of Negative Elements: %.2f\n", sum_n);

return 0;
}
